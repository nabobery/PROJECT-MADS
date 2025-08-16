// 2787. Ways to Express an Integer as Sum of Powers

// Solution 1: Using Dynamic Programming
// Time Complexity: O(n)
// Space Complexity: O(n)
class Solution {
public:
    // generate all possible number which are a power of x less than n
    // then check for all possible ways to sum up to n using dp
    const int mod = 1e9 + 7;
    int numberOfWays(int n, int x) {
        vector<int> dp(n+1 , 0);
        vector<int> powers;
        // get all the powers 
        for(int i = 1; i <= n;i++){
            int power = pow(i, x);
            if(power > n) break;
            powers.push_back(power);
        }
        // use knapsack dp and get the number of ways to get sum n using numbers of power x
        dp[0] = 1;
        for(int power: powers){
            for(int i = n; i >= power;i--)
                dp[i] = long(dp[i] + dp[i - power]) % mod;
        }
        return dp[n];
    }
};