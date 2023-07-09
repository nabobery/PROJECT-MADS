// 64. Minimum Path Sum

// O(mn) Time and O(mn) space solution using Recursion + Memoization
class Solution {
public:
    int helper(vector<vector<int>>& grid, int m, int n, vector<vector<int>>& dp){
        if (n < 0 || m < 0) return 1e5; 
        else if(m==0 && n==0) return grid[0][0]; 
        if(dp[m][n]!=-1) return dp[m][n];
        return dp[m][n]=grid[m][n]+min(helper(grid,m-1,n,dp),helper(grid,m,n-1,dp));
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m =  grid.size(), n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n,-1));
        return helper(grid,m-1,n-1,dp);
    }
};

// O(mn) Time and O(mn) space solution using DP
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n,1e5));
        // base case : the first cell will have the value of the first cell of the grid.
        dp[0][0] = grid[0][0];
        for(int i = 0; i < m;i++){
            for(int j = 0; j < n;j++){
                // if we are not in the first cell, we can calculate the min path sum of the current cell by adding the min of the values above and left to it.
                if(i > 0) dp[i][j] = min(dp[i][j], grid[i][j] + dp[i-1][j]);
                if(j > 0) dp[i][j] = min(dp[i][j], grid[i][j] + dp[i][j-1]);
            }
        }
        return dp[m-1][n-1];
    }
};

// O(mn) Time and O(n) space solution using DP
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<int> dp(n,grid[0][0]);
        // base case : the first row will have the sum of all the values in the first row of the grid.
        for(int i = 1; i < n;i++) dp[i] = dp[i-1] + grid[0][i];
        // for each row, we will calculate the min path sum of the current cell by adding the min of the values above and left to it.
        for(int i = 1; i < m;i++){
            // for the first cell of the row, we will add the value of the cell above it.
            dp[0] += grid[i][0];
            // for the rest of the cells, we will add the min of the values above and left to it.
            for(int j = 1; j < n;j++){
                dp[j] = min(dp[j], dp[j-1]) + grid[i][j];
            }
        }
        return dp[n-1];
    }
};

