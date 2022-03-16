// 121. Best Time to Buy and Sell Stock
// Kadane's algo variant
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n == 1)
            return 0;
        int buy = prices[0];
        int result = 0;
        for(int ele : prices){
            buy = min(ele,buy);
            result = max(result,ele - buy);
        }
        return result;
    }
};

// one more variant
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int result = 0, curr = 0;
        for(int i = 1; i < prices.size();i++){
            curr = max(0,curr += prices[i] - prices[i-1]);
            result = max(result,curr);
        }
        return result;
    }
};