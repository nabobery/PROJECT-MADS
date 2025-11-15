// 474. Ones and Zeroes

// Solution 1: Using Knapsack DP (recursive with memoization)
// Time Complexity: O(m * n * l), where m is the number of strings, n is the max number of 0's, l is the max number of 1's
// Space Complexity: O(m * n * l) for the memoization table
class Solution {
public:
    int helper(int k, int m, int n, vector<pair<int, int>>& cnt,
               vector<vector<vector<int>>>& dp) {
        if ((m == 0 && n == 0) || k == 0)
            return 0;
        if (dp[k][m][n] != -1)
            return dp[k][m][n];
        int res = 0;
        if (m >= cnt[k - 1].first && n >= cnt[k - 1].second)
            res = max(res, 1 + helper(k - 1, m - cnt[k - 1].first,
                                      n - cnt[k - 1].second, cnt, dp));
        res = max(res, helper(k - 1, m, n, cnt, dp));
        return dp[k][m][n] = res;
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        int k = strs.size();
        vector<pair<int, int>> cnt(k);
        for (int i = 0; i < k; i++) {
            int cntZeroes = 0;
            for (auto& ch : strs[i])
                if (ch == '0')
                    cntZeroes++;
            cnt[i] = {cntZeroes, strs[i].size() - cntZeroes};
        }
        vector<vector<vector<int>>> dp(
            k + 1, vector<vector<int>>(m + 1, vector<int>(n + 1, -1)));
        return helper(k, m, n, cnt, dp);
    }
};

// Solution 2: Using Knapsack DP (iterative)
// Time Complexity: O(m * n * l), where m is the number of strings,
// Space Complexity: O(m * n) for the DP table
class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int k = strs.size();
        vector<pair<int, int>> cnt(k);
        for (int i = 0; i < k; i++) {
            int cntZeroes = 0;
            for (auto& ch : strs[i])
                if (ch == '0')
                    cntZeroes++;
            cnt[i] = {cntZeroes, strs[i].size() - cntZeroes};
        }
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        for (int i = 0; i < k; i++) {
            for (int j = m; j >= cnt[i].first; j--) {
                for (int l = n; l >= cnt[i].second; l--) {
                    dp[j][l] = max(dp[j][l],
                                   1 + dp[j - cnt[i].first][l - cnt[i].second]);
                }
            }
        }
        return dp[m][n];
    }
};