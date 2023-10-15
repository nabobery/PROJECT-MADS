// 1269. Number of Ways to Stay in the Same Place After Some Steps

// Solution 1 : Top Down DP (Recursion + Memoization)
// Time complexity: O(n*min(steps, arrLen))
// Space complexity: O(n*min(steps, arrLen))
class Solution {
public:
    int n, mod = 1e9+7;
    vector<vector<int>> dp;
    int solve(int pos, int steps){
        if(steps == 0)
            return (pos == 0);
        if(pos < 0 || pos >= n) return 0;
        if(dp[pos][steps] != -1) return dp[pos][steps];
        long res = solve(pos, steps-1);
        res += solve(pos-1, steps-1);
        res += solve(pos+1, steps-1);
        return dp[pos][steps] = res%mod;
    }
    int numWays(int steps, int arrLen) {
        n = min(arrLen, steps);
        dp.resize(n, vector<int>(steps+1, -1));
        return solve(0, steps);
    }
};

// Solution 2 : Bottom Up DP
// Time complexity: O(n*min(steps, arrLen))
// Space complexity: O(n*min(steps, arrLen))
class Solution {
public:
    int numWays(int steps, int arrLen) {
        int n = min(arrLen, steps);
        vector<vector<int>> dp(n, vector<int>(steps+1, 0));
        int mod = 1e9+7;
        dp[0][0] = 1;
        for(int i = 1;i <= steps;i++){
            for(int j = 0;j < n;j++){
                long res = dp[j][i-1];
                if(j > 0)
                    res += dp[j-1][i-1];
                if(j < n-1)
                    res += dp[j+1][i-1];
                dp[j][i] = res%mod;
            }
        }
        return dp[0][steps];
    }
};

// Solution 3 : Bottom Up DP with Space Optimization
// Time complexity: O(n*min(steps, arrLen))
// Space complexity: O(min(steps, arrLen))
class Solution {
public:
    int numWays(int steps, int arrLen) {
        int n = min(arrLen, steps);
        vector<int> dp(n, 0);
        int mod = 1e9+7;
        dp[0] = 1;
        for(int i = 1;i <= steps;i++){
            vector<int> new_dp(n, 0);
            for(int j = 0;j < n;j++){
                long res = dp[j];
                if(j > 0)
                    res += dp[j-1];
                if(j < n-1)
                    res += dp[j+1];
                new_dp[j] = res%mod;
            }
            dp = new_dp;
        }
        return dp[0];
    }
};