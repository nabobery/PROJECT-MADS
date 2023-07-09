// 714. Best Time to Buy and Sell Stock with Transaction Fee

// O(n) time and O(n) space recursive with memoization solution
class Solution {
public:
    int helper(vector<int>& prices, int i, bool buy, int fee, vector<vector<int>>& dp){
        // base case
        if(i >= prices.size()) return 0;
        // if the value is already calculated then return it
        if(dp[i][buy] != -1) return dp[i][buy];
        // one choice is don't buy the stock and hold
        int c1 = helper(prices,i+1, buy,fee,dp);
        int c2 = 0;
        // another is buy/sell the stock
        // if buy is true then we have to buy the stock
        if(buy) c2 = -prices[i] - fee + helper(prices,i+1,false,fee,dp);
        // if buy is false then we have to sell the stock
        else c2 = prices[i] + helper(prices,i+1,true,fee,dp);
        // return the max of both the choices
        return dp[i][buy] = max(c1,c2);
    }
    int maxProfit(vector<int>& prices, int fee) {
        vector<vector<int>> dp(prices.size(), vector<int>(2,-1));
        return helper(prices, 0, true, fee,dp);
    }
};

// O(n) time and O(1) space solution
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        // initialize the result and hold
        int result = 0, hold = -prices[0];
        for(auto price : prices){
            // get the max of doing nothing and selling the stock
            result = max(result, hold + price - fee);
            // get the max of doing nothing and buying the stock
            hold = max(hold, result - price);
        }
        return result;
    }
};