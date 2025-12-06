// 3625. Count Number of Trapezoids II

// Solution 1: Grouping by Slopes and Using a Set for Uniqueness
// Time Complexity: O(N^4) 
// Space Complexity: O(N^2) for storing line segments and unique quadrilaterals
class Solution {
public:
    int countTrapezoids(vector<vector<int>>& points) {
        int n = points.size();
        // Group line segments by their slopes
        map<pair<int, int>, vector<pair<int, int>>> slopeGroups;
        // Set to store unique quadrilaterals
        set<vector<int>> uniqueQuads;

        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                // Calculate normalized slope
                pair<int, int> slope = getNormalizedSlope(points[i], points[j]);
                slopeGroups[slope].push_back({i, j});
            }
        }

        for (auto const& [slope, segments] : slopeGroups) {
            for (int i = 0; i < segments.size(); ++i) {
                for (int j = i + 1; j < segments.size(); ++j) {
                    int p1 = segments[i].first;
                    int p2 = segments[i].second;
                    int p3 = segments[j].first;
                    int p4 = segments[j].second;

                    vector<int> quad = {p1, p2, p3, p4};
                    sort(quad.begin(), quad.end());

                    // Ensure all points are distinct
                    if (quad[0] == quad[1] || quad[1] == quad[2] || quad[2] == quad[3]) {
                        continue; 
                    }

                    // Check that the other pair of sides are not parallel
                    pair<int, int> crossSlope = getNormalizedSlope(points[p1], points[p3]);
                    if (crossSlope == slope) {
                        continue; 
                    }

                    uniqueQuads.insert(quad);
                }
            }
        }

        return uniqueQuads.size();
    }

private:
    pair<int, int> getNormalizedSlope(const vector<int>& p1, const vector<int>& p2) {
        int dx = p2[0] - p1[0];
        int dy = p2[1] - p1[1];
        
        if (dx == 0 && dy == 0) return {0, 0};

        int d = gcd(abs(dx), abs(dy));
        dx /= d;
        dy /= d;

        if (dx < 0 || (dx == 0 && dy < 0)) {
            dx = -dx;
            dy = -dy;
        }

        return {dx, dy};
    }
};

// Solution 2: Using a Hash Map to Count Parallel Line Segments
// Time Complexity: O(N^2)
// Space Complexity: O(N^2) for storing line segments and midpoints
class Solution {
public:
    int countTrapezoids(vector<vector<int>>& points) {
        int n = points.size();

        map<pair<int, int>, map<int, int>> lines;
        map<pair<int, int>, map<pair<int, int>, int>> midpoints;

        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int x1 = points[i][0], y1 = points[i][1];
                int x2 = points[j][0], y2 = points[j][1];

                int dy = y1 - y2;
                int dx = x1 - x2;

                if (dx < 0) {
                    dx = -dx;
                    dy = -dy;
                } else if (dx == 0 && dy < 0) {
                    dy = -dy;
                }

                int common = gcd(abs(dx), abs(dy));
                dy /= common;
                dx /= common;

                int intercept = (int)dx * y1 - (int)dy * x1;
                pair<int, int> slope = {dy, dx};

                lines[slope][intercept]++;
                midpoints[{x1 + x2, y1 + y2}][slope]++;
            }
        }

        int ans = 0;

        // Count pairs of parallel lines forming trapezoids
        for (auto const& [slope, interceptMap] : lines) {
            int runningSum = 0;
            for (auto const& [intercept, count] : interceptMap) {
                ans += (int)count * runningSum;
                runningSum += count;
            }
        }

        // Subtract cases where both pairs of sides are parallel (parallelograms) to avoid double counting
        for (auto const& [mid, slopeMap] : midpoints) {
            int runningSum = 0;
            for (auto const& [slope, count] : slopeMap) {
                ans -= (int)count * runningSum;
                runningSum += count;
            }
        }

        return ans;
    }
};