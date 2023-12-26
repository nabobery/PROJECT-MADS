// 2706. Buy Two Chocolates

// Solution 1 Simple sort
// Time complexity: O(nlogn)
// Space complexity: O(1)
class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        sort(prices.begin(), prices.end());
        return ((prices[0] + prices[1] > money) ? money : money-prices[0]-prices[1]);
    }
};

// Solution 2 Finding min and 2nd min
// Time complexity: O(n)
// Space complexity: O(1)
class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        int min1 = 101, min2 = 101;
        for (auto& price : prices) {
            if (price < min1) {
                min2 = min1;
                min1 = price;
            } else if (price < min2) {
                min2 = price;
            }
        }
        return ((min1 + min2 > money) ? money : money-min1-min2);
    }
};