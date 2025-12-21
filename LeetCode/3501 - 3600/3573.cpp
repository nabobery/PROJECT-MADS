// 3573. Best Time to Buy and Sell Stock V

// Solution 1: Using Dynamic Programming
// The idea is to maintain 3 states: long position, short position, and no position.
// Time Complexity: O(n*k)
// Space Complexity: O(n*k)
typedef long long ll;

class Solution {
public:
    long long maximumProfit(vector<int>& prices, int k) {
        int n = prices.size();
        // neutral[i][j]: max profit at day i with j transactions and no position
        // longPos[i][j]: max profit at day i with j transactions and a long position
        // shortPos[i][j]: max profit at day i with j transactions and a short position
        vector<vector<ll>> neutral(n, vector<ll>(k+1, -1e15)), longPos(n, vector<ll>(k+1, -1e15)), shortPos(n, vector<ll>(k+1, -1e15));
        // Base case
        neutral[0][0] = 0;
        longPos[0][1] = -prices[0];
        shortPos[0][1] = prices[0];
        for(int i = 1; i < n;i++){
            // Base case for day i
            neutral[i][0] = 0;
            // Update states
            for(int j = 1; j <= k;j++){
                // long position[i][j]: either keep the long position or buy today after being neutral yesterday
                longPos[i][j] = max(longPos[i-1][j],  neutral[i-1][j-1] - prices[i]);
                // short position[i][j]: either keep the short position or sell today after being neutral yesterday
                shortPos[i][j] = max(shortPos[i-1][j], neutral[i-1][j-1] + prices[i]);
                // neutral[i][j]: either keep being neutral, sell the long position today, or buy to close the short position today
                neutral[i][j] = max({neutral[i-1][j], longPos[i-1][j] + prices[i], shortPos[i-1][j] - prices[i]});
            }
        }
        // Get the maximum profit at the last day with atmost k transactions and no position
        long long res = 0;
        for(int i = 0; i <= k;i++) res = max(res, neutral[n-1][i]);
        return res;
    }
};

// Solution 2: Space Optimization
// Time Complexity: O(n*k)
// Space Complexity: O(k)
typedef long long ll;

class Solution {
public:
    long long maximumProfit(vector<int>& prices, int k) {
        int n = prices.size();
        const ll INF = 1e16;
        vector<ll> neutral(k + 1, -INF);
        vector<ll> longPos(k + 1, -INF);
        vector<ll> shortPos(k + 1, -INF);

        neutral[0] = 0;
        longPos[1] = -prices[0];
        shortPos[1] = (ll)prices[0];

        for (int i = 1; i < n; i++) {
            vector<ll> next_neutral = neutral;
            vector<ll> next_longPos = longPos;
            vector<ll> next_shortPos = shortPos;

            for (int j = 1; j <= k; j++) {
                if (longPos[j] != -INF) {
                    next_neutral[j] = max(next_neutral[j], longPos[j] + prices[i]);
                }
                if (shortPos[j] != -INF) {
                    next_neutral[j] = max(next_neutral[j], shortPos[j] - prices[i]);
                }
                if (neutral[j - 1] != -INF) {
                    next_longPos[j] = max(next_longPos[j], neutral[j - 1] - prices[i]);
                    next_shortPos[j] = max(next_shortPos[j], neutral[j - 1] + prices[i]);
                }
            }
            neutral = next_neutral;
            longPos = next_longPos;
            shortPos = next_shortPos;
        }

        ll maxProfit = 0;
        for (int j = 0; j <= k; j++) {
            maxProfit = max(maxProfit, neutral[j]);
        }
        return maxProfit;
    }
};