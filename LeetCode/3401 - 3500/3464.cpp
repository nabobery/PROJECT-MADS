// 3464. Maximize the Distance Between Points on a Square

// Solution 1: Binary Search + Greedy
// Time Complexity: O(n log n + n^2 log(perimeter/k))
// Space Complexity: O(n)
class Solution {
public:
    // Convert (x, y) to its corresponding position on the perimeter of the square
    long long getPerimeter(int x, int y, int side) {
        if (y == 0)
            return x;
        if (x == side)
            return side + y;
        if (y == side)
            return 3LL * side - x;
        return 4LL * side - y;
    }

    // Check if we can place k points on the perimeter with at least minDist distance apart
    bool canPlace(long long minDist, int k, const vector<long long>& points,
                  long long perimeter) {
        int n = points.size();
        // Try to place points starting from each point in the sorted list
        for (int i = 0; i < n; ++i) {
            int count = 1;
            long long lastPos = points[i];
            // Place the next points greedily at least minDist apart
            for (int j = i + 1; j < n; ++j) {
                if (points[j] - lastPos >= minDist) {
                    count++;
                    lastPos = points[j];
                }
            }
            // If we have placed at least k points, check if the last point can wrap around to the first point
            if (count >= k) {
                if (k == 1 || (perimeter - (lastPos - points[i]) >= minDist)) {
                    return true;
                }
            }
        }
        // If we cannot place k points with at least minDist distance apart, return false
        return false;
    }

    int maxDistance(int side, vector<vector<int>>& points, int k) {
        int n = points.size();
        // Calculate the total perimeter of the square
        long long perimeter = 4LL * side;
        vector<long long> p(n);
        // Convert each point to its corresponding position on the perimeter
        // This allows us to treat the problem as placing points on a line of length equal to the perimeter
        for (int i = 0; i < n; ++i) {
            p[i] = getPerimeter(points[i][0], points[i][1], side);
        }
        // Sort the points based on their position on the perimeter
        sort(p.begin(), p.end());
        // Use binary search to find the maximum minimum distance that can be achieved
        long long left = 1, right = perimeter / k + 1;
        long long res = 0;
        // Binary search for the maximum minimum distance
        while (left <= right) {
            long long mid = left + (right - left) / 2;
            if (canPlace(mid, k, p, perimeter)) {
                res = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return (int)res;
    }
};

// Solution 2: Binary Search + Greedy (Optimized)
// Time Complexity: O(n log n + n log(perimeter/k))
// Space Complexity: O(nlog k)
class Solution {
public:
    long long getPerimeter(int x, int y, int side) {
        if (y == 0) return x;
        if (x == side) return (long long)side + y;
        if (y == side) return 3LL * side - x;
        return 4LL * side - y;
    }

    bool canPlace(long long minDist, int k, const vector<long long>& p, long long perimeter) {
        int n = p.size();
        // 1. Create a doubled array to handle wrap-around without modulo
        vector<long long> dp(2 * n);
        for (int i = 0; i < n; ++i) {
            dp[i] = p[i];
            dp[i + n] = p[i] + perimeter;
        }

        // 2. Precompute the 'next' point for each point using two pointers
        int m = 2 * n;
        vector<int> nxt(m + 1, m);
        int r = 0;
        for (int l = 0; l < m; ++l) {
            while (r < m && dp[r] < dp[l] + minDist) r++;
            nxt[l] = r;
        }

        // 3. Binary Lifting table: jump[i][j] is the index after 2^j jumps
        int levels = 32 - __builtin_clz(k); // log2(k)
        vector<vector<int>> jump(m + 1, vector<int>(levels, m));
        for (int i = 0; i < m; ++i) jump[i][0] = nxt[i];
        
        for (int j = 1; j < levels; ++j) {
            for (int i = 0; i < m; ++i) {
                if (jump[i][j - 1] != m)
                    jump[i][j] = jump[jump[i][j - 1]][j - 1];
            }
        }

        // 4. Check if any starting point i can complete the k-points cycle
        // We only need to check the first n points as potential starts
        for (int i = 0; i < n; ++i) {
            int cur = i;
            int steps = k - 1;
            for (int j = 0; j < levels; ++j) {
                if ((steps >> j) & 1) {
                    cur = jump[cur][j];
                    if (cur >= m) break;
                }
            }
            // Check if k-th point exists and has enough distance to wrap back to start
            if (cur < m && (dp[i] + perimeter - dp[cur] >= minDist)) {
                return true;
            }
        }
        return false;
    }

    int maxDistance(int side, vector<vector<int>>& points, int k) {
        int n = points.size();
        long long perimeter = 4LL * side;
        vector<long long> p(n);
        for (int i = 0; i < n; ++i) {
            p[i] = getPerimeter(points[i][0], points[i][1], side);
        }
        sort(p.begin(), p.end());

        long long left = 1, right = perimeter / k;
        long long res = 0;
        while (left <= right) {
            long long mid = left + (right - left) / 2;
            if (canPlace(mid, k, p, perimeter)) {
                res = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return (int)res;
    }
};