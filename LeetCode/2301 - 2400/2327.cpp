// 2327. Number of People Aware of a Secret

// Solution 1: Using Dynamic Programming
// Time Complexity: O(n)
// Space Complexity: O(n)
class Solution {
public:
    const int mod = 1e9 + 7;
    int peopleAwareOfSecret(int n, int delay, int forget) {
        // res is the final answer and sharing is the number of people currently sharing the secret
        long res = 0, sharing = 0;
        // dp[i] is the number of people who learned the secret on day i
        vector<long> dp(n+1, 0);
        // Initially, one person knows the secret on day 1
        dp[1] = 1;
        for(int i = 2; i <= n;i++){
            // Calculate the number of people sharing the secret on day i
            // people who can share the secret on day i are people who learned the secret on day i - delay
            if(i - delay >= 1) sharing = (sharing + dp[i-delay]) % mod;
            // people who can no longer share the secret on day i are people who learned the secret on day i - forget
            if(i - forget >= 1) sharing = (sharing - dp[i-forget] + mod) % mod;
            // people who learned the secret on day i are equal to the ones who are sharing it
            dp[i] = sharing;
        };
        // Calculate the final result which is number of people who know the secret on day n
        // which is the sum of all people who learned the secret after day n - forget
        for(int i = n-forget+1; i <= n;i++) res = (res + dp[i]) % mod;
        return res;
    }
};


