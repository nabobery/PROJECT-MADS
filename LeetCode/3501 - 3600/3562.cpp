// 3562. Maximum Profit from Trading Stocks with Discounts

// Solution 1: Using Knapsack on Tree DP
// Time Complexity: O(N * B^2)
// Space Complexity: O(N + B)
class Solution {
    // Member variables to store problem parameters
    // N: number of employees
    // B: budget
    // P: present prices of stock for each employee
    // F: future prices of stock for each employee
    // adj: adjacency list representing the hierarchy tree
    int N, B;
    vector<int> P, F;
    vector<vector<int>> adj;

    pair<vector<int>, vector<int>> dfs(int u) {
        // DP arrays for the current node u
        // dp_not_buy: max profit if u does not buy stock
        vector<int> dp_not_buy(B + 1, -1e9);
        // If u does not buy stock, profit is 0 with 0 cost
        dp_not_buy[0] = 0;

        // dp_buy_full: max profit if u buys stock
        vector<int> dp_buy_full(B + 1, -1e9);
        // If u buys stock at full price
        int cost_full = P[u - 1];
        // Profit if u buys stock at full price
        int profit_full = F[u - 1] - P[u - 1]; 
        // Only consider buying the stock within budget
        if (cost_full <= B) {
            dp_buy_full[cost_full] = profit_full;
        }

        // dp_buy_half: max profit if u buys stock at half price
        vector<int> dp_buy_half(B + 1, -1e9);
        // If u buys stock at half price
        int cost_half = P[u - 1] / 2;
        // Profit if u buys stock at half price
        int profit_half = F[u - 1] - cost_half;
        // Only consider buying the stock within budget
        if (cost_half <= B) {
            dp_buy_half[cost_half] = profit_half;
        }

        // Process all children of u
        for (int v : adj[u]) {
            // Get DP results from child v
            pair<vector<int>, vector<int>> child_res = dfs(v);
            // child_res.first: max profit if v does not buy stock
            const vector<int>& child_no = child_res.first;
            // child_res.second: max profit if v buys stock
            const vector<int>& child_yes = child_res.second;
            
            // Merge function to combine DP results
            auto merge = [&](vector<int>& current_dp, const vector<int>& child_dp) {
                // Temporary DP array to store merged results
                vector<int> next_dp(B + 1, -1e9);
                // Perform knapsack-like merging
                // Iterate over all possible budgets
                for (int w = 0; w <= B; ++w) {
                    // Try all possible splits of budget w between current and child
                    for (int k = 0; k <= w; ++k) {
                        // Update next_dp with the maximum profit
                        if (current_dp[w - k] > -1e8 && child_dp[k] > -1e8) {
                            next_dp[w] = max(next_dp[w], current_dp[w - k] + child_dp[k]);
                        }
                    }
                }
                // Update current_dp with merged results
                current_dp = next_dp;
            };

            // Merge child results into current DP arrays
            // If u does not buy stock and child v does not buy stock
            merge(dp_not_buy, child_no);
            // If u buys stock (full or half price) and child v buys stock
            merge(dp_buy_full, child_yes);
            merge(dp_buy_half, child_yes);
        }

        // Prepare results for current node u to return
        vector<int> res_no_parent(B + 1);
        vector<int> res_yes_parent(B + 1);

        // If u has no parent (i.e., u is CEO), we can choose max profit
        // If u has a parent, we consider the case where u buys stock at half price
        for (int i = 0; i <= B; ++i) {
            // Max profit if u has no parent
            res_no_parent[i] = max(dp_not_buy[i], dp_buy_full[i]);
            // Max profit if u has a parent
            res_yes_parent[i] = max(dp_not_buy[i], dp_buy_half[i]);
        }

        // Return the DP results for current node u
        return {res_no_parent, res_yes_parent};
    }

public:
    int maxProfit(int n, vector<int>& present, vector<int>& future, vector<vector<int>>& hierarchy, int budget) {
        N = n;
        B = budget;
        P = present;
        F = future;
        // Build adjacency list of the hierarchy tree of bosses and employees
        adj.assign(n + 1, vector<int>());
        for (auto& edge : hierarchy) {
            adj[edge[0]].push_back(edge[1]);
        }


        // Perform DFS from the root (CEO)
        pair<vector<int>, vector<int>> result = dfs(1);

        int ans = 0;
        // The answer is the maximum profit we can achieve 
        // As CEO has no parent, we consider only that case
        for (int x : result.first) {
            ans = max(ans, x);
        }
        return ans;
    }
};