// 63. Unique Paths II

// O(mn) Time and O(mn) space solution using DP
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int>(n,0));
        // base case : if the first cell has an obstacle, then simply return as there would be no paths to the bottom right cell.
        if(!obstacleGrid[0][0]) dp[0][0] = 1;
        else return 0;
        for(int i = 0; i < m;i++){
            for(int j = 0; j < n;j++){
                // if the current cell is an obstacle, we ignore it. else we add the number of ways of reaching the cells above and left to it.
                if(i > 0 && !obstacleGrid[i][j]) dp[i][j] += dp[i-1][j];
                if(j > 0 && !obstacleGrid[i][j]) dp[i][j] += dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
    }
};

// O(mn) Time and O(n) space solution using DP
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        vector<int> dp(n, 0);
        // base case : if the first cell has an obstacle, then simply return as there would be no paths to the bottom right cell.
        if(!obstacleGrid[0][0]) dp[0] = 1;
        else return 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                // if the current cell is an obstacle, we ignore it. else we add the number of ways of reaching the cells above and left to it.
                if(obstacleGrid[i][j]) dp[j] = 0;
                else if(j > 0) dp[j] += dp[j - 1];
            }
        }
        return dp[n - 1];
    }
};