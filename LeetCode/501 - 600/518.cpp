// 518. Coin Change II

// O(amount*n) Time and O(amount*n) space solution Recursive with memoization
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<vector<int>> dp(coins.size()+1, vector<int>(amount+1, -1));
        return helper(coins, amount, coins.size(), dp);
    }
    
    int helper(vector<int>& coins, int amount, int n, vector<vector<int>>& dp){
        // base case: if amount is 0 then we can make it with 1 way i.e. by not using any coin
        if(amount == 0) return 1;
        // if amount is not 0 and no coins are left then we can't make it
        if(n == 0) return 0;
        if(dp[n][amount] != -1) return dp[n][amount];
        // if coin > amount then we can't use it so we move to next coin and keep the amount same
        if(amount < coins[n-1]) return dp[n][amount] = helper(coins, amount, n-1, dp);
        // if coin <= amount then we can use it or not use it
        return dp[n][amount] = helper(coins, amount-coins[n-1], n, dp) + helper(coins, amount, n-1, dp);
    }
};

// O(amount*n) Time and O(amount*n) space DP solution Iterative 
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<vector<int>> dp(coins.size()+1, vector<int>(amount+1, 0));
        // base case: if amount is 0 then we can make it with 1 way i.e. by not using any coin
        for(int i = 0; i <= coins.size();i++) dp[i][0] = 1;
        for(int i = 1; i <= coins.size();i++){
            for(int j = 1; j <= amount;j++){
                // if coin <= amount then we can use it or not use it
                if(j >= coins[i-1]) dp[i][j] = dp[i-1][j] + dp[i][j-coins[i-1]];
                // if coin > amount then we can't use it so we move to next coin and keep the amount same
                else dp[i][j] = dp[i-1][j];
            }
        }
        return dp[coins.size()][amount];
    }
};


// O(amount*n) Time and O(amount) space solution Iterative
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<int> dp(amount+1, 0);
        dp[0] = 1;
        for(auto coin : coins){
            for(int i = 1; i <= amount;i++){
                if(i >= coin) dp[i] += dp[i-coin];
            }
        }
        return dp[amount];
    }
};


