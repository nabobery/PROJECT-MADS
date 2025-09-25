// 120. Triangle

// Solution 1: Recursive DP (Memoization)
// Time Complexity: O(N^2)
// Space Complexity: O(N^2) for dp array + O(N) for recursion stack
class Solution {
public:
    const int mx = 1e7;
    int helper(int i, int j, vector<vector<int>>& dp, vector<vector<int>>& triangle){
        if(j > i) return mx;
        if(dp[i][j] != mx) return dp[i][j];
        int res = triangle[i][j];
        if(i < dp.size() - 1) res += min(helper(i+1, j, dp, triangle), helper(i+1, j+1, dp, triangle));
        return dp[i][j] = res;
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(n, vector<int>(n, mx));
        return helper(0, 0, dp, triangle);
    }
};

// Solution 2: Iterative DP (Bottom-Up)
// Time Complexity: O(N^2)
// Space Complexity: O(N^2) for dp array
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

// Solution 3: Space Optimized Iterative DP
// Time Complexity: O(N^2)
// Space Complexity: O(N) for dp array
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