// 3742. Maximum Path Score in a Grid

// Solution 1: Using BFS and Pruning 
// Time Complexity: O((m+n-2)C(m-1)) in the worst case, where we explore all paths 
// Space Complexity: O(m*n*k) for the queue and visited set
class Solution {
public:
    int maxPathScore(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();

        vector<vector<vector<int>>> dp(
            m, vector<vector<int>>(n, vector<int>(k + 1, -1)));

        queue<tuple<int, int, int, int>> q;
        q.push({0, 0, 0, 0});

        int res = -1;

        while (!q.empty()) {
            auto [r, c, cost, score] = q.front();
            q.pop();

            int newCost = cost + (grid[r][c] != 0);
            int newScore = score + grid[r][c];

            if (newCost > k)
                continue;

            if (r == m - 1 && c == n - 1) {
                res = max(res, newScore);
                continue;
            }

            if (r + 1 < m) {
                if (dp[r + 1][c][newCost] < newScore) {
                    dp[r + 1][c][newCost] = newScore;
                    q.push({r + 1, c, newCost, newScore});
                }
            }

            if (c + 1 < n) {
                if (dp[r][c + 1][newCost] < newScore) {
                    dp[r][c + 1][newCost] = newScore;
                    q.push({r, c + 1, newCost, newScore});
                }
            }
        }

        return res;
    }
};


// Solution 2: Using Dynamic Programming
// Time Complexity: O(m*n*k) where we fill the dp table
// Space Complexity: O(m*n*k) for the dp table
class Solution {
public:
    int maxPathScore(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();

        // dp[r][c][cost] = maximum score to reach (r, c) with cost 'cost'
        vector dp(m, vector(n, vector<int>(k + 1, -1)));

        // base case: starting point
        int startCost = (grid[0][0] != 0);
        if (startCost <= k)
            dp[0][0][startCost] = grid[0][0];

        // fill the dp table
        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                for (int cost = 0; cost <= k; cost++) {
                    // if not reachable, skip
                    if (dp[r][c][cost] == -1)
                        continue;

                    // move down if possible
                    if (r + 1 < m) {
                        int nc = cost + (grid[r + 1][c] != 0);
                        if (nc <= k) {
                            // update the dp value for the next cell
                            dp[r + 1][c][nc] =
                                max(dp[r + 1][c][nc],
                                    dp[r][c][cost] + grid[r + 1][c]);
                        }
                    }

                    // move right if possible
                    if (c + 1 < n) {
                        int nc = cost + (grid[r][c + 1] != 0);
                        if (nc <= k) {
                            // update the dp value for the next cell
                            dp[r][c + 1][nc] =
                                max(dp[r][c + 1][nc],
                                    dp[r][c][cost] + grid[r][c + 1]);
                        }
                    }
                }
            }
        }

        // find the maximum score at the bottom-right corner with any cost <= k
        int res = -1;
        for (int cost = 0; cost <= k; cost++) {
            res = max(res, dp[m - 1][n - 1][cost]);
        }
        return res;
    }
};
