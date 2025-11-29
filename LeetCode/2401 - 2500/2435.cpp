// 2435. Paths in Matrix Whose Sum Is Divisible by K

// Solution 1: Dynamic Programming
// Time Complexity: O(m * n * k)
// Space Complexity: O(m * n * k)
// where m is the number of rows, n is the number of columns in the grid, and k is the given integer.
// Brute force would be exponential in nature as we would explore all possible paths. (m+n-2 choose n-1) paths.
// The DP approach optimizes this by storing intermediate results for each cell and remainder.
// The idea is to maintain a 3D DP array where dp[i][j][r] represents the number of ways to reach cell (i, j) with a sum that gives a remainder r when divided by k.
// We iterate through each cell and update the DP array based on the values from the top and left cells. (As we can only move down or right)
class Solution {
public:
    const int mod = 1e9+7;
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(k, 0)));
        dp[0][0][grid[0][0]%k] = 1;
        for(int i = 0; i < m;i++){
            for(int j = 0; j < n;j++){
                for(int rem = 0; rem < k;rem++){
                    int newRem = (rem+grid[i][j])%k;
                    long curr = dp[i][j][newRem];
                    if(i > 0) curr = (curr + dp[i-1][j][rem])% mod;
                    if(j > 0) curr = (curr + dp[i][j-1][rem])% mod;
                    dp[i][j][newRem] = curr;
                }
            }
        }
        return dp[m-1][n-1][0];
    }
};