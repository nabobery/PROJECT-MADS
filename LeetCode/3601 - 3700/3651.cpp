// 3651. Minimum Cost Path with Teleportations

// Solution 1 Using Dynamic Programming
// Time Complexity: O(n * m * k)
// Space Complexity: O(n * m * k)
class Solution {
public:
    const int INF = 1e9;
    int minCost(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        // dp[t][i][j]: minimum cost to reach (i, j) using at most t teleportations
        vector<vector<vector<int>>> dp(k+1, vector<vector<int>>(m, vector<int>(n, INF)));
        // Base case as we start from (0, 0) with 0 cost
        for (int t = 0; t <= k; t++) 
            dp[t][0][0] = 0;
        // Fill the dp table
        for (int t = 0; t <= k; t++) {
            // Move down or right without teleportation
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    if (i == 0 && j == 0) continue;
                    
                    int moveUp = (i > 0) ? dp[t][i - 1][j] : INF;
                    int moveLeft = (j > 0) ? dp[t][i][j - 1] : INF;
                    
                    int bestPrev = min(moveUp, moveLeft);
                    if (bestPrev != INF) {
                        dp[t][i][j] = min(dp[t][i][j], bestPrev + grid[i][j]);
                    }
                }
            }

            // Teleportation step
            if (t < k) {
                // find the max value in the grid
                int maxVal = 0;
                for (const auto& row : grid) {
                    for (int val : row) maxVal = max(maxVal, val);
                }
                // min_reach[v]: minimum cost to reach any cell with value >= v using at most t teleportations
                vector<int> min_reach(maxVal + 2, INF);
                for (int i = 0; i < m; i++) {
                    for (int j = 0; j < n; j++) {
                        if (dp[t][i][j] != INF) {
                            min_reach[grid[i][j]] = min(min_reach[grid[i][j]], dp[t][i][j]);
                        }
                    }
                }
                // Propagate the minimum costs downwards
                for (int v = maxVal; v >= 0; v--) {
                    min_reach[v] = min(min_reach[v], min_reach[v + 1]);
                }
                // Update dp for teleportation to find minimum cost to reach each cell with t+1 teleportations
                for (int i = 0; i < m; i++) {
                    for (int j = 0; j < n; j++) {
                        dp[t + 1][i][j] = min(dp[t + 1][i][j], min_reach[grid[i][j]]);
                    }
                }
            }
        }
        // Find the minimum cost to reach (m-1, n-1) using at most k teleportations
        int res = INF;
        for (int t = 0; t <= k; t++) 
            res = min(res, dp[t][m - 1][n - 1]);
        return res;
    }
};


