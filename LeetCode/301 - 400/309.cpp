// 309. Best Time to Buy and Sell Stock with Cooldown


// O(n) time, O(n) space solution
class Solution {
public:
    vector<vector<int>> dp;
    int helper(vector<int>& prices, int i, bool buy){
        // base case
        if(i >= prices.size()) return 0;
        // if the state is already calculated, return it
        if(dp[i][buy] != -1) return dp[i][buy];
        // one choice is not to do anything and hold
        int c1 = helper(prices,i+1, buy);
        int c2 = 0;
        // if you are buying, you can't buy again until the next day, so you have to skip the next day
        if(buy) c2 = -prices[i] + helper(prices,i+1,false);
        // if you are selling, you can't sell again until the day after tomorrow, so you have to skip the next day
        else c2 = prices[i] + helper(prices,i+2,true);
        // return the max out of the two choices
        return dp[i][buy] = max(c1,c2);
    }
    int maxProfit(vector<int>& prices) {
        // initialize the dp array
        for(int i = 0; i < prices.size();i++){
            dp.push_back(vector<int>(2,-1));
        }
        // return the max profit
        return helper(prices, 0, true);
    }
};

// O(n) time, O(1) space solution
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // initialize the previous states
        int coolDown=0, sell=0, hold=INT_MIN;
        // cooldown is the time between selling and buying where you don't do anything,sell is the max profit you can get if you sell today, hold is the max profit you can get if you hold today
        for(auto price : prices){
            // get the previous states
            int prevCoolDown = coolDown, prevSell = sell, prevHold = hold;
            // update the states for the current day
            // get the max out of either selling it previous day  and being on cooldown or not selling it
            coolDown = max(prevCoolDown, prevSell);
            // get the max out of either selling it previous day or holding it previous day and selling it today
            sell = prevHold + price;
            hold = max(prevHold, prevCoolDown - price);
        }
        // return the max out of either selling it or being on cooldown
        return max(sell, coolDown);
    }
};