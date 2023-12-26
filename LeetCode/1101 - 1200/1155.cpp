// 1155. Number of Dice Rolls With Target Sum

// Solution 1 using Recursion + Memoization (Top Down)
// Time Complexity: O(n*k*target)
// Space Complexity: O(n*target)
class Solution {
public:
    int mod = 1e9 + 7, k;
    int helper(int n, int x, vector<vector<int>>& dp){
        if(x <= 0) return 0;
        if(n == 1){
            if(x > 0 && x <= k) return dp[n-1][x] = 1;
            return 0;
        }
        if(dp[n-1][x] != -1) return dp[n-1][x];
        long long result = 0;
        for(int i = 1; i <= k;i++){
            result += helper(n-1, x-i, dp);
            result %= mod;
        }
        return dp[n-1][x] = result%mod;
    }
    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>> dp(n, vector<int>(target+1, -1));
        this->k = k;
        return helper(n, target, dp);
    }
};

// Solution 2 using DP (Bottom Up)
// Time Complexity: O(n*k*target)
// Space Complexity: O(n*target)
class Solution {
public:
    int mod = 1e9 + 7;
    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>> dp(n+1, vector<int>(target+1, 0));
        for(int i = 1; i <= k && i <= target; i++) dp[1][i] = 1;
        for(int i = 2; i <= n; i++){
            for(int j = 1; j <= target; j++){
                for(int l = 1; l <= k && l <= j; l++){
                    dp[i][j] += dp[i-1][j-l];
                    dp[i][j] %= mod;
                }
            }
        }
        return dp[n][target];
    }
};

// Solution 3 using DP (Bottom Up) with Space Optimization
// Time Complexity: O(n*k*target)
// Space Complexity: O(target)
class Solution {
public:
    int mod = 1e9 + 7;
    int numRollsToTarget(int n, int k, int target) {
        vector<int> dp(target+1, 0);
        dp[0] = 1;
        for(int i = 1; i <= n; i++){
            vector<int> temp(target+1, 0);
            for(int j = 1; j <= target; j++){
                for(int l = 1; l <= k && l <= j; l++){
                    temp[j] += dp[j-l];
                    temp[j] %= mod;
                }
            }
            dp = temp;
        }
        return dp[target];
    }
};