// 3454. Separate Squares II

// Solution 1: Using Binary Search and calculate area of strips (TLE)
// Time Complexity: O(N^2 + N log N)
// Space Complexity: O(N)
// Strip Area Calculation and Binary Search to find the dividing line
struct Strip {
    double yStart, yEnd, area;
};

class Solution {
public:
    double separateSquares(vector<vector<int>>& squares) {
        vector<int> yCoords;
        // Collect all unique y-coordinates
        for (const auto& s : squares) {
            yCoords.push_back(s[1]);
            yCoords.push_back(s[1] + s[2]);
        }
        sort(yCoords.begin(), yCoords.end());
        yCoords.erase(unique(yCoords.begin(), yCoords.end()), yCoords.end());

        // Calculate area of strips between consecutive y-coordinates
        vector<Strip> strips;
        double totalArea = 0;

        // For each strip defined by consecutive y-coordinates
        for (size_t i = 0; i < yCoords.size() - 1; ++i) {
            int yLow = yCoords[i];
            int yHigh = yCoords[i + 1];
            
            // Collect x-intervals of squares that intersect with the current strip
            vector<pair<int, int>> xIntervals;
            for (const auto& s : squares) {
                if (s[1] < yHigh && (s[1] + s[2]) > yLow) {
                    xIntervals.push_back({s[0], s[0] + s[2]});
                }
            }

            if (xIntervals.empty()) continue;
            
            // Calculate the union width of x-intervals
            sort(xIntervals.begin(), xIntervals.end());
            double unionWidth = 0;
            int currStart = xIntervals[0].first;
            int currEnd = xIntervals[0].second;

            // Merge intervals to find union width
            for (size_t j = 1; j < xIntervals.size(); ++j) {
                if (xIntervals[j].first < currEnd) {
                    currEnd = max(currEnd, xIntervals[j].second);
                } else {
                    unionWidth += (currEnd - currStart);
                    currStart = xIntervals[j].first;
                    currEnd = xIntervals[j].second;
                }
            }
            unionWidth += (currEnd - currStart);

            // Calculate area of the strip and store it
            double stripArea = unionWidth * (yHigh - yLow);
            strips.push_back({(double)yLow, (double)yHigh, stripArea});
            totalArea += stripArea;
        }

        // Binary search to find the y-coordinate that divides area into two equal parts
        double low = yCoords.front(), high = yCoords.back();
        double targetArea = totalArea / 2.0;

        for(int iter = 0; iter < 60; ++iter) {
            double mid = low + (high - low) / 2.0;
            if (getAreaBelow(mid, strips) >= targetArea) {
                high = mid;
            } else {
                low = mid;
            }
        }

        return low;
    }

private:
    // Calculate area below a given y-coordinate
    double getAreaBelow(double y, const vector<Strip>& strips) {
        double area = 0;
        for (const auto& strip : strips) {
            // If the strip is completely above y
            if (y <= strip.yStart) break;
            // If the strip is completely below y
            if (y >= strip.yEnd) {
                area += strip.area;
            // If the strip is partially below y
            } else {
                double height = y - strip.yStart;
                double fullHeight = strip.yEnd - strip.yStart;
                area += strip.area * (height / fullHeight);
            }
        }
        return area;
    }
};

// Solution 2: Using Sweep Line Algorithm and Segment Tree (AC)
// Time Complexity: O(N log N)
// Space Complexity: O(N)
// Sweep Line to process events and Segment Tree to maintain coverage
// Segment tree to maintain the UNION length of active x-intervals
class SegmentTree {
private:
    // count[pos]: how many intervals currently cover this node's segment
    vector<int> count;

    // covered[pos]: total covered length of this node's segment
    vector<int> covered;

    // Discretized x-coordinates
    vector<int> xs;

    // Number of x-intervals
    int n;

    // Update range [qleft, qright) with +1 (add) or -1 (remove)
    void modify(int qleft, int qright, int qval,
                int left, int right, int pos) {

        // No overlap between node segment and update range
        if (xs[right + 1] <= qleft || xs[left] >= qright)
            return;

        // Fully covered by update range
        if (qleft <= xs[left] && xs[right + 1] <= qright) {
            count[pos] += qval;
        } else {
            // Partial overlap → go deeper
            int mid = (left + right) / 2;
            modify(qleft, qright, qval, left, mid, pos * 2 + 1);
            modify(qleft, qright, qval, mid + 1, right, pos * 2 + 2);
        }

        // If covered by at least one interval → fully covered
        if (count[pos] > 0) {
            covered[pos] = xs[right + 1] - xs[left];
        } else {
            // Leaf node with no coverage
            if (left == right) {
                covered[pos] = 0;
            } else {
                // Combine children
                covered[pos] = covered[pos * 2 + 1]
                             + covered[pos * 2 + 2];
            }
        }
    }

public:
    SegmentTree(vector<int>& xs_) : xs(xs_) {
        // Number of x-segments is one less than number of x-points
        n = xs.size() - 1;
        count.resize(4 * n, 0);
        covered.resize(4 * n, 0);
    }

    // Public update call
    void update(int qleft, int qright, int qval) {
        modify(qleft, qright, qval, 0, n - 1, 0);
    }

    // Total covered x-length
    int query() {
        return covered[0];
    }
};

class Solution {
public:
    double separateSquares(vector<vector<int>>& squares) {

        // Sweep-line events:
        // (y, +1/-1, x_left, x_right)
        vector<tuple<int, int, int, int>> events;

        // Collect x-coordinates for discretization
        set<int> xsSet;

        for (auto& sq : squares) {
            int x = sq[0], y = sq[1], l = sq[2];
            int xr = x + l;

            // Square enters at y
            events.emplace_back(y, 1, x, xr);

            // Square exits at y + l
            events.emplace_back(y + l, -1, x, xr);

            xsSet.insert(x);
            xsSet.insert(xr);
        }

        // Sort events by y-coordinate
        sort(events.begin(), events.end());

        // Discretize x-coordinates
        vector<int> xs(xsSet.begin(), xsSet.end());

        // Segment tree over x-axis
        SegmentTree segTree(xs);

        // Prefix area sums after each event
        vector<double> psum;

        // Active x-widths after each event
        vector<int> widths;

        double total_area = 0.0;

        // Previous y-coordinate
        int prev = get<0>(events[0]);

        // Sweep line from bottom to top
        for (auto& [y, delta, xl, xr] : events) {

            // Current union width on x-axis
            int len = segTree.query();

            // Area added since last y
            total_area += 1LL * len * (y - prev);

            // Update active x-intervals
            segTree.update(xl, xr, delta);

            // Record prefix area and width
            psum.push_back(total_area);
            widths.push_back(segTree.query());

            prev = y;
        }

        // We want half the total union area
        long long target = (long long)(total_area + 1) / 2;

        // Find strip where area crosses half
        int i = lower_bound(psum.begin(), psum.end(), target)
                - psum.begin() - 1;

        // Area accumulated before this strip
        double area = psum[i];

        // Width of this horizontal strip
        int width = widths[i];

        // Starting y of this strip
        int height = get<0>(events[i]);

        // Linearly interpolate inside the strip
        return height + (total_area - area * 2) / (width * 2.0);
    }
};
