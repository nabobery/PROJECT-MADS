// 790. Domino and Tromino Tiling

// Solution 1: Dynamic Programming
// Time Complexity: O(n)
// Space Complexity: O(n)
// there're 3 states for any 2 x n board filled using dominoes and trominoes:
// 1. dp[i][0]: The number of ways to completely tile columns 0 to i
// 2. dp[i][1]: The number of ways where columns 0 to i are tiled and column i is missing the top cell
// 3. dp[i][2]: The number of ways where columns 0 to i are tiled and column i is missing the bottom cell

// The recurrence relations are:
// dp[i][0] = dp[i - 1][0] + dp[i - 2][0] + dp[i - 2][1] + dp[i - 2][2]
// = 1 vertical domino on dp[i - 1][0] + 2 vertical domino on dp[i - 2][0] + 1 top tromino on dp[i - 2][1] + 1 bottom tromino on dp[i - 2][2]
// dp[i][1] = dp[i - 1][0] + dp[i - 1][2]
// = 1 bottom tromino on dp[i - 1][0] + 1 horiontal domino on dp[i - 1][2]
// dp[i][2] = dp[i - 1][0] + dp[i - 1][1]
// = 1 top domino on dp[i - 1][0] + 1 horiontal domino on dp[i - 1][1]


class Solution {
public:
    long long mod = 1000000007;
    int numTilings(int n) {
        if(n < 3){
            return n;
        }
        long long dp[n + 1][3];
        // Initialize the dp array to 0
        for(int i = 0; i < n + 1; i++){
            dp[i][0] = 0;
            dp[i][1] = 0;
            dp[i][2] = 0;
        }
        // Base cases
        // For a board with 0 columns, we consider it “completed", so there's 1 way to tile it
        // For a board with 1 column, we can only place a vertical domino, so there's 1 way to tile it
        dp[0][0] = dp[1][0] = 1;
        // For a board with 1 column and with some cells missing, we set this hypothetical base case to 1 
        dp[1][1] = dp[1][2] = 1;
        for(int i = 2; i <= n;i++){
            dp[i][0] = (dp[i - 1][0] + dp[i-2][0] + dp[i-2][1] + dp[i-2][2])%mod;
            dp[i][1] = (dp[i - 1][0] + dp[i-1][2])%mod;
            dp[i][2] = (dp[i - 1][0] + dp[i-1][1])%mod;
        }
        // The answer is the number of ways to completely tile the board with n columns
        return dp[n][0];       
    }
};