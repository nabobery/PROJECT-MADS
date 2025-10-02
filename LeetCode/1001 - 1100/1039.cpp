// 1039. Minimum Score Triangulation of Polygon

// Solution 1: Using Recursion + Memoization 
// Time Complexity: O(n^3)
// Space Complexity: O(n^2)
class Solution {
public:
    int n;
    int helper(int i, int j, vector<vector<int>>& dp, vector<int>& values){
        if(j < i+2) return dp[i][j] = 0;
        if(j == i+2) return dp[i][j] = values[i]*values[i+1]*values[i+2];
        if(dp[i][j] != -1) return dp[i][j];
        int res = INT_MAX;
        for(int k = i+1; k < j;k++){
            int curr = values[i]*values[j]*values[k];
            res = min(res, curr + helper(i, k, dp, values) + helper(k, j, dp, values));
        }
        return dp[i][j] = res;
    }
    int minScoreTriangulation(vector<int>& values) {
        n = values.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return helper(0, n-1, dp, values);
    }
};

// Solution 2: Using Tabulation 
// Time Complexity: O(n^3)
// Space Complexity: O(n^2)
class Solution {
public:
    int minScoreTriangulation(vector<int>& values) {
        int n = values.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for(int i = n-1; i >= 0; i--){
            for(int j = i+2; j < n; j++){
                int res = INT_MAX;
                for(int k = i+1; k < j;k++){
                    int curr = values[i]*values[j]*values[k];
                    res = min(res, curr + dp[i][k] + dp[k][j]);
                }
                dp[i][j] = res;
            }
        }
        return dp[0][n-1];
    }
};