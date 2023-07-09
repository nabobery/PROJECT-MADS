// 121. Best Time to Buy and Sell Stock

// O(n) Time and O(n) space DP solution
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n  = prices.size(), result = 0;
        // dp[i] stores the maximum price from i to n-1
        vector<int> dp(n);
        dp[n-1] = prices[n-1];
        for(int i = n-2; i >= 0;i--){
            dp[i] = max(dp[i+1], prices[i+1]);
            result = max(result, dp[i] - prices[i]);
        }
        return result;
    }
};


// Kadane's algo variant O(n) time and O(1) space solution
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min_price = prices[0],result = 0;
        for(auto price : prices){
            min_price = min(price,min_price);
            result = max(result,price - min_price);
        }
        return result;
    }
};

// O(n) time and O(1) space solution
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int result = 0, curr = 0;
        for(int i = 1; i < prices.size();i++){
            // if curr is negative, then we can't make profit by selling at i, so we change it to zero by finding max
            // if curr is positive, then we can make profit by selling at i, so we add the difference to curr
            curr = max(0,curr += prices[i] - prices[i-1]);
            // we store the maximum profit we can make by selling at all i
            result = max(result,curr);
        }
        return result;
    }
};