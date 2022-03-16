// 790. Domino and Tromino Tiling
class Solution {
public:
    long long mod = 1000000007;
    int numTilings(int n) {
        if(n < 3){
            return n;
        }
        long long dp[n + 1][3];
        for(int i = 0; i < n + 1; i++){
            dp[i][0] = 0;
            dp[i][1] = 0;
            dp[i][2] = 0;
        }
        dp[0][0] = dp[1][0] = 1;
        dp[1][1] = dp[1][2] = 1;
        for(int i = 2; i <= n;i++){
            dp[i][0] = (dp[i - 1][0] + dp[i-2][0] + dp[i-2][1] + dp[i-2][2])%mod;
            dp[i][1] = (dp[i - 1][0] + dp[i-1][2])%mod;
            dp[i][2] = (dp[i - 1][0] + dp[i-1][1])%mod;
        }
        return dp[n][0];       
    }
};