// 1937. Maximum Number of Points with Cost


// Solution 1: DP
// Time complexity: O(m*n)
// Space complexity: O(m*n)
class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
        int m = points.size(), n = points[0].size();
        vector<vector<long long>> dp(m, vector<long long>(n, 0));
        long long res = 0;
        for (int i = 0; i < n; i++)
            dp[0][i] = points[0][i];
        for (int i = 1; i < m; i++) {
            vector<long long> leftMax(n), rightMax(n);
            leftMax[0] = dp[i-1][0];
            for (int j = 1; j < n; j++)
                leftMax[j] = max(leftMax[j-1]-1, dp[i-1][j]);
            rightMax[n-1] = dp[i-1][n-1];
            for (int j = n-2; j >= 0; j--) 
                rightMax[j] = max(rightMax[j+1]-1, dp[i-1][j]);
            for (int j = 0; j < n; j++) 
                dp[i][j] = max(leftMax[j], rightMax[j]) + points[i][j];
        }
        for (int i = 0; i < n; i++) 
            res = max(res, dp[m-1][i]);
        return res;
    }
};

// Solution 2: DP (Optimized)
// Time complexity: O(m*n)
// Space complexity: O(n)
class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
        int m = points.size(), n = points[0].size();
        vector<long long> dp(n);
        long long res = 0;
        for (int i = 0; i < n; i++)
            dp[i] = points[0][i];
        for (int i = 1; i < m; i++) {
            vector<long long> leftMax(n), rightMax(n);
            leftMax[0] = dp[0];
            for (int j = 1; j < n; j++)
                leftMax[j] = max(leftMax[j-1]-1, dp[j]);
            rightMax[n-1] = dp[n-1];
            for (int j = n-2; j >= 0; j--) 
                rightMax[j] = max(rightMax[j+1]-1, dp[j]);
            for (int j = 0; j < n; j++) 
                dp[j] = max(leftMax[j], rightMax[j]) + points[i][j];
        }
        for (int i = 0; i < n; i++) 
            res = max(res, dp[i]);
        return res;
    }
};