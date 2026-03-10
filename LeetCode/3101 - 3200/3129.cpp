// 3129. Find All Possible Stable Binary Arrays I


// Solution 1: Dynamic Programming Approach
// Time Complexity: O(zero * one * 2) where zero is the number of 0's and one is the number of 1's
// Space Complexity: O(zero * one* 2) since we are using a 3D dp array to store the results of subproblems
typedef long long ll;

class Solution {
public:
    const int mod = 1e9+7;
    int numberOfStableArrays(int zero, int one, int limit) {
        // dp[i][j][0] represents the number of stable arrays with i 0's and j 1's that end with a 0
        // dp[i][j][1] represents the number of stable arrays with i 0's and j 1's that end with a 1
        vector<vector<vector<ll>>> dp(zero+1, vector<vector<ll>>(one+1, vector<ll>(2, 0)));
        // Base cases: An array with only 0's or only 1's is stable if the count does not exceed the limit
        for(int i = 0; i <= min(zero, limit);i++) dp[i][0][0] = 1;
        for(int i = 0; i <= min(one, limit);i++) dp[0][i][1] = 1;
        // Fill the dp array using the transition rules
        for(int i = 1; i <= zero;i++){
            for(int j = 1; j <= one;j++){
                // To end with a 0, we can append a 0 to any stable array that ends with either a 0 or a 1, but we need to ensure we do not exceed the limit of consecutive 0's
                dp[i][j][0] = (dp[i-1][j][0]+ dp[i-1][j][1])% mod;
                // If we have more than 'limit' consecutive 0's, we need to subtract the cases where we appended a 0 to an array that already had 'limit' consecutive 0's
                // This is done by subtracting the number of stable arrays that end with a 1 and have 'limit' consecutive 0's before appending the last 0
                if(i > limit){
                    dp[i][j][0] = (dp[i][j][0] - dp[i-limit-1][j][1] + mod) %mod;
                }
                // To end with a 1, we can append a 1 to any stable array that ends with either a 0 or a 1, but we need to ensure we do not exceed the limit of consecutive 1's
                dp[i][j][1] = (dp[i][j-1][0]+ dp[i][j-1][1])% mod;
                // If we have more than 'limit' consecutive 1's, we need to subtract the cases where we appended a 1 to an array that already had 'limit' consecutive 1's
                // This is done by subtracting the number of stable arrays that end with a 0
                if(j > limit){
                    dp[i][j][1] = (dp[i][j][1] - dp[i][j-limit-1][0] + mod) %mod;
                }
            }
        }
        // The total number of stable arrays with 'zero' 0's and 'one' 1's is the sum of those that end with a 0 and those that end with a 1
        return (dp[zero][one][0] + dp[zero][one][1])% mod;
    }
};

// Elegant and optimized Solution 1
// Time Complexity: O(zero * one) where zero is the number of 0's and one is the number of 1's
// Space Complexity: O(zero * one) since we are using a 2D dp array to store the results of subproblems
typedef long long ll;

class Solution {
public:
    int numberOfStableArrays(int zero, int one, int limit) {
        int mod = 1e9 + 7;
        vector<vector<ll>> dp0(zero + 1, vector<ll>(one + 1, 0));
        vector<vector<ll>> dp1(zero + 1, vector<ll>(one + 1, 0));

        for (int i = 1; i <= min(zero, limit); i++) dp0[i][0] = 1;
        for (int j = 1; j <= min(one, limit); j++) dp1[0][j] = 1;

        for (int i = 1; i <= zero; i++) {
            for (int j = 1; j <= one; j++) {
                dp0[i][j] = (dp0[i - 1][j] + dp1[i - 1][j]) % mod;
                if (i > limit) {
                    dp0[i][j] = (dp0[i][j] - dp1[i - limit - 1][j] + mod) % mod;
                }

                dp1[i][j] = (dp1[i][j - 1] + dp0[i][j - 1]) % mod;
                if (j > limit) {
                    dp1[i][j] = (dp1[i][j] - dp0[i][j - limit - 1] + mod) % mod;
                }
            }
        }

        return (dp0[zero][one] + dp1[zero][one]) % mod;
    }
};