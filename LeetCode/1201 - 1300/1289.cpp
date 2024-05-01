// 1289. Minimum Falling Path Sum II

// Solution 1 using Top Down DP (Recursion + Memoization)
// Time complexity: O(n^3)
// Space complexity: O(n^2)
// The idea is to maintain a dp array of size n x n where dp[i][j] represents the minimum falling path sum ending at (i, j).
// The base case is when i = 0, dp[i][j] = grid[i][j].
// The recursive case is to iterate over all the columns k and find the minimum falling path sum ending at (i-1, k) and add grid[i][j] to it.
// The final answer is the minimum falling path sum ending at the last row.
class Solution {
public:
    int n;
    vector<vector<int>> dp;
    int helper(int i, int j, vector<vector<int>>& grid){
        if(i == 0) return dp[i][j] = grid[i][j];
        if(dp[i][j] != INT_MAX) return dp[i][j];
        for(int k = 0; k < n;k++) 
            if(k != j) dp[i][j] = min(grid[i][j] + helper(i-1, k, grid), dp[i][j]);
        return dp[i][j];
    }
    int minFallingPathSum(vector<vector<int>>& grid) {
        n = grid.size();
        dp.resize(n, vector<int>(n, INT_MAX));
        int res = INT_MAX;
        for(int i = 0; i < n;i++) res = min(res, helper(n-1, i, grid));
        return res;
    }
};

// Solution 2 using Bottom Up DP
// Time complexity: O(n^2)
// Space complexity: O(n^2)
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        // Base case
        for(int i = 0; i < n;i++) dp[0][i] = grid[0][i];
        for(int i = 1; i < n;i++){
            // Find the minimum and second minimum falling path sum ending at the previous row along with the column index
            vector<int> min1 = {INT_MAX, INT_MAX}, min2 = {INT_MAX, INT_MAX};
            for(int j = 0; j < n;j++){
                if(dp[i-1][j] < min1[0]){
                    min2 = min1;
                    min1 = {dp[i-1][j], j};
                }else if(dp[i-1][j] < min2[0])
                    min2 = {dp[i-1][j], j};
            }
            // Update the dp array
            for(int j = 0; j < n;j++)
                dp[i][j] = grid[i][j] + (j == min1[1] ? min2[0] : min1[0]);
        }
        // Return the minimum falling path sum ending at the last row
        return *min_element(dp[n-1].begin(), dp[n-1].end());
    }
};


// Extra Solution
// Number of Falling Paths with non-zero shifts
// class Solution {
// public:
//     int n;
//     vector<vector<int>> dp;
//     int helper(int i, int j, vector<vector<int>>& grid){
//         if(i == 0) return dp[i][j] = 1;
//         if(dp[i][j] != -1) return dp[i][j];
//         int res = 0;
//         for(int k = 0; k < n;k++) 
//             if(k != j) res += helper(i-1, k, grid);
//         return dp[i][j] = res;
//     }
//     int minFallingPathSum(vector<vector<int>>& grid) {
//         n = grid.size();
//         dp.resize(n, vector<int>(n, -1));
//         int res = 0;
//         for(int i = 0; i < n;i++) res += helper(n-1, i, grid);
//         return res;
//     }
// };