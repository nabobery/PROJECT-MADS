// 1475. Final Prices With a Special Discount in a Shop

// Solution 1: Brute force
// Time complexity: O(n^2)
// Space complexity: O(1)
class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int n = prices.size();
        vector<int> res(n);
        for(int i = 0; i < n;i++){
            int discount = 0;
            for(int j = i+1; j < n;j++){
                if(prices[j] <= prices[i]){
                    discount = prices[j];
                    break;
                }
            }
            res[i] = prices[i] - discount;
        }
        return res;
    }
};

// Solution 2: Monotonic stack
// Time complexity: O(n)
// Space complexity: O(n)
class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int n = prices.size();
        vector<int> res(n);
        stack<int> stk;
        for(int i = n-1; i >= 0;i--){
            while(!stk.empty() && prices[stk.top()] > prices[i]) stk.pop();
            res[i] = stk.empty() ? prices[i] : prices[i] - prices[stk.top()]; 
            stk.push(i);
        }
        return res;
    }
};