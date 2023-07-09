// 120. Triangle

// O(N^2) time and O(N^2) space DP solution
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<vector<int>> dp(triangle.begin(), triangle.end());
        for(int i = triangle.size()- 2; i >= 0;i--){
            for(int j = 0; j <= i;j++){
                dp[i][j] = min(dp[i+1][j], dp[i+1][j+1]) + triangle[i][j];
            }
        }
        return dp[0][0];
    }
};

// O(N^2) time and O(N) space DP solution
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<int> dp(triangle[n-1].begin(), triangle[n-1].end());
        for(int i = n - 2; i >= 0;i--){
            for(int j = 0; j <= i;j++){
                dp[j] = min(dp[j], dp[j+1]) + triangle[i][j];
            }
        }
        return dp[0];
    }
};