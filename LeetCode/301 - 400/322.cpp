// 322. Coin Change

// O(n*amount) time and O(amount) space solution using DP (bottom-up approach)
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1, 1e5);
        dp[0] = 0;
        for(auto coin : coins) 
            if(coin < amount)
                dp[coin] = 1;
        for(int i = 1; i <= amount;i++){
            for(auto coin : coins){
                if(i >= coin) dp[i] = min(dp[i], dp[i-coin] + 1);
            }
        }
        return (dp[amount] == 1e5 ? -1 : dp[amount]);
    }
};

// O(n*amount) time and O(amount) space solution using DP (top-down approach)
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1, 1e5);
        dp[0] = 0;
        return helper(coins, amount, dp);
    }
    
    int helper(vector<int>& coins, int amount, vector<int>& dp){
        if(amount < 0) return -1;
        if(dp[amount] != 1e5) return dp[amount];
        int minCoins = 1e5;
        for(auto coin : coins){
            int res = helper(coins, amount - coin, dp);
            if(res >= 0) minCoins = min(minCoins, res + 1);
        }
        dp[amount] = (minCoins == 1e5 ? -1 : minCoins);
        return dp[amount];
    }
};
