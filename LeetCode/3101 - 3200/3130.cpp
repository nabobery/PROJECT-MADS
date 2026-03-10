// 3130. Find All Possible Stable Binary Arrays II

// Solution 1: Dynamic Programming Approach
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