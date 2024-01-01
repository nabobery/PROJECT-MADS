// 1335. Minimum Difficulty of a Job Schedule

// Solution 1 : Top Down DP
// Time Complexity: O(n^2 * d)
// Space Complexity: O(n * d)
class Solution {
public:
    int n;
    vector<vector<int>> dp;
    int helper(int i, int d, vector<int>& jobDifficulty){
        if(i == n && d == 0) return 0;
        if(d < 0 || n-i < d) return 1e6;
        if(dp[i][d] != 1e6) return dp[i][d];
        int res = 1e6, mx = 0;
        for(int j =i; j < n;j++){
            mx = max(mx, jobDifficulty[j]);
            res = min(res, mx + helper(j+1,d-1, jobDifficulty));
        }
        return dp[i][d] = res;  
    }
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        n = jobDifficulty.size();
        if(d > n) return -1;
        dp.resize(n, vector<int>(d+1, 1e6));
        return helper(0, d, jobDifficulty);
    }
};

// Solution 2 : Bottom Up DP
// Time Complexity: O(n^2 * d)
// Space Complexity: O(n * d)
class Solution {
public:
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int n = jobDifficulty.size();
        if(d > n) return -1;
        vector<vector<int>> dp(n+1, vector<int>(d+1, 1e6));
        dp[0][0] = 0;
        for(int i = 1; i <= n; i++){
            for(int k = 1; k <= d; k++){
                int mx = 0;
                for(int j = i-1; j >= k-1; j--){
                    mx = max(mx, jobDifficulty[j]);
                    dp[i][k] = min(dp[i][k], mx + dp[j][k-1]);
                }
            }
        }
        return dp[n][d];
    }
};