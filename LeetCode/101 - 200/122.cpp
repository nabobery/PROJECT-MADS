/* 122. Best Time to Buy and Sell Stock II */


// O(n) time and O(1) space greedy solution using peak and valley approach
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int i = 0, valley = prices[0], peak = prices[0], result = 0;
        while(i < prices.size() - 1){
            // find the valley
            while(i < prices.size() - 1 && prices[i] >= prices[i+1]){
                i++;
            }
            valley = prices[i];
            // find the peak
            while(i < prices.size() - 1 && prices[i] <= prices[i+1]){
                i++;
            }
            peak = prices[i];
            result += (peak - valley);
        }
        return result;
    }
};

// O(n) time and O(1) space Greedy solution
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int result = 0, prev = prices[0];
        for(auto curr : prices){
            // if the profit gained is positive, add it to the total
            if(curr > prev){
                result += (curr -prev);
            }
            prev = curr;
        }
        return result;
    }
};



