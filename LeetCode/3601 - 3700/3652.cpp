// 3652. Best Time to Buy and Sell Stock using Strategy

// Solution 1: Using Sliding Window and Prefix Sum
// Time Complexity: O(n)
// Space Complexity: O(n)
class Solution {
public:
    long long maxProfit(vector<int>& prices, vector<int>& strategy, int k) {
        int n = prices.size();
        vector<long long> prefixPrices(n + 1, 0), prefixProfit(n + 1, 0);
        // Calculate prefix sums
        for (int i = 0; i < n; i++) {
            prefixProfit[i + 1] = prefixProfit[i] + prices[i] * strategy[i];
            prefixPrices[i + 1] = prefixPrices[i] + prices[i];
        }
        // Sliding window to find the maximum profit
        long long res = prefixProfit[n];
        // Try every window of size k
        for (int i = 0; i <= n - k; i++) {
            // Calculate the profit if we modify the current window strategy
            long long originalWindowProfit = prefixProfit[i + k] - prefixProfit[i];
            long long newWindowProfit = prefixPrices[i + k] - prefixPrices[i + k / 2];
            // Update the result
            res = max(res, prefixProfit[n] - originalWindowProfit + newWindowProfit);
        }
        return res;
    }
};

// Solution 2: Using Sliding Window with O(1) Space
// Time Complexity: O(n)
// Space Complexity: O(1)
class Solution {
public:
    long long maxProfit(vector<int>& prices, vector<int>& strategy, int k) {
        int n = prices.size();
        long long total = 0, sSum = 0, pSum = 0;

        for (int i = 0; i < n; i++) total += prices[i] * strategy[i];

        for (int i = 0; i < k; i++) sSum += prices[i] * strategy[i];
        for (int i = k / 2; i < k; i++) pSum += prices[i];

        long long maxDelta = pSum - sSum;
        for (int i = 1; i <= n - k; i++) {
            sSum += prices[i + k - 1] * strategy[i + k - 1] - prices[i - 1] * strategy[i - 1];
            pSum += prices[i + k - 1] - prices[i + k / 2 - 1];
            maxDelta = max(maxDelta, pSum - sSum);
        }

        return total + max(0LL, maxDelta);
    }
};