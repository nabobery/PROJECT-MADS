// 1140. Stone Game II

// Solution 1 using Preix Sum + Recursion + Memoization
// Time complexity: O(n^2)
// Space complexity: O(n^2)
class Solution {
public:
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        // prefixSum[i] = sum of piles[0] to piles[i - 1]
        vector<int> prefixSum(n + 1, 0);
        for (int i = 0; i < n; ++i) 
            prefixSum[i + 1] = prefixSum[i] + piles[i];
        // dp[i][m] = maximum stones that can be obtained starting from piles[i] with m as the maximum number of piles that can be taken
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        // dfs(i, m) = maximum stones that can be obtained starting from piles[i] with m as the maximum number of piles that can be taken
        return dfs(0, 1, piles, prefixSum, dp);
    }

    // helper function to calculate the maximum stones that can be obtained starting from piles[i] with m as the maximum number of piles that can be taken
    int dfs(int i, int m, vector<int>& piles, vector<int>& prefixSum, vector<vector<int>>& dp) {
        // if i >= piles.size() then no more piles left to take so return 0
        if (i >= piles.size()) return 0;
        // if dp[i][m] is already calculated then return it
        if (dp[i][m] != -1) return dp[i][m];
        // maxStones = maximum stones that can be obtained starting from piles[i] with m as the maximum number of piles that can be taken
        int maxStones = 0;
        // x = number of piles that can be taken
        for (int x = 1; x <= 2 * m; ++x) {
            // if i + x > piles.size() then no more piles left to take so break
            if (i + x > piles.size()) break;
            // stones = sum of piles[i] to piles[i + x - 1]
            int stones = prefixSum[i + x] - prefixSum[i];
            // max stones can be gotten by Alice
            // max of stones + (sum of remaining piles) - dfs(i + x, max(m, x)) and maxStones
            maxStones = max(maxStones, stones + (prefixSum.back() - prefixSum[i + x]) - dfs(i + x, max(m, x), piles, prefixSum, dp));
        }
        // store the result in dp[i][m] and return it
        return dp[i][m] = maxStones;
    }
};