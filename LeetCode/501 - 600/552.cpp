// 552. Student Attendance Record II

// Solution 1 using Recursion + Memoization (Top-Down)
// Time complexity: O(6n) = O(n)
// Space complexity: O(6n) = O(n)
class Solution {
public:
    int checkRecord(int n) {
        // memo[n][absent][late] = number of valid attendance records of length n
        // can be absent for at atmost 1 day in total and can be late for at most 2 days in a row
        vector<vector<vector<int>>> memo(n + 1, vector<vector<int>>(2, vector<int>(3, -1)));
        // number of valid attendance records of length n with 0 absent and 0 late days
        return dfs(n, 0, 0, memo);
    }
    
    int dfs(int n, int absent, int late, vector<vector<vector<int>>>& memo) {
        // base case 
        if (n == 0) return 1;
        // if already calculated return the value
        if (memo[n][absent][late] != -1) return memo[n][absent][late];
        // initialize ans
        int ans = 0;
        // if present
        ans = (ans + dfs(n - 1, absent, 0, memo)) % 1000000007;
        // if absent and absent days are less than 1
        if (absent == 0) ans = (ans + dfs(n - 1, 1, 0, memo)) % 1000000007;
        // if not late and late days are less than 2
        if (late < 2) ans = (ans + dfs(n - 1, absent, late + 1, memo)) % 1000000007;
        // store the value in memo
        return memo[n][absent][late] = ans;
    }
};

// Solution 2 using DP (Bottom-Up)
// Time complexity: O(6n) = O(n)
// Space complexity: O(6n) = O(n)

class Solution {
public:
    int checkRecord(int n) {
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(3, 0)));
        dp[0][0][0] = 1;
        for(int i = 0; i < n;i++){
            for(int absent = 0; absent <= 1;absent++){
                for(int late = 0; late <= 2;late++){
                    // if present
                    dp[i + 1][absent][0] = (dp[i + 1][absent][0] + dp[i][absent][late]) % 1000000007;
                    // if absent and absent days are less than 1
                    if(absent < 1) dp[i + 1][absent + 1][0] = (dp[i + 1][absent + 1][0] + dp[i][absent][late]) % 1000000007;
                    // if not late and late days are less than 2
                    if(late < 2) dp[i + 1][absent][late + 1] = (dp[i + 1][absent][late + 1] + dp[i][absent][late]) % 1000000007;
                }
            }
        }
        int res = 0;
        for(int absent = 0; absent <= 1;absent++){
            for(int late = 0; late <= 2;late++){
                res = (res + dp[n][absent][late]) % 1000000007;
            }
        }
        return res;
    }
};

// Solution 3 using DP (Bottom-Up) with Space Optimization
// Time complexity: O(6n) = O(n)
// Space complexity: O(6) = O(1)

class Solution {
public:
    int checkRecord(int n) {
        int dp[2][3], temp[2][3];
        memset(dp, 0, sizeof(dp));
        dp[0][0] = 1;
        for(int i = 0; i < n;i++){
            memset(temp, 0, sizeof(temp));
            for(int absent = 0; absent <= 1;absent++){
                for(int late = 0; late <= 2;late++){
                    temp[absent][0] = (temp[absent][0] + dp[absent][late]) % 1000000007;
                    if(absent < 1) temp[absent + 1][0] = (temp[absent + 1][0] + dp[absent][late]) % 1000000007;
                    if(late < 2) temp[absent][late + 1] = (temp[absent][late + 1] + dp[absent][late]) % 1000000007;
                }
            }
            for(int absent = 0; absent <= 1; absent++)
                for(int late = 0; late <= 2;late++)
                    dp[absent][late] = temp[absent][late];
        }
        int res = 0;
        for(int absent = 0; absent <= 1;absent++){
            for(int late = 0; late <= 2;late++){
                res = (res + dp[absent][late]) % 1000000007;
            }
        }
        return res;
    }
};
