// 664. Strange Printer

// Solution 1 using Iterative DP
// Time complexity: O(n^3)
// Space complexity: O(n^2)
class Solution {
public:
    int strangePrinter(string s) {
        int n = s.size();
        // dp[i][j] = minimum number of turns to print s[i..j]
        vector<vector<int>> dp(n, vector<int>(n, INT_MAX));
        // base case dp[i][i] = 1 as we need 1 turn to print a single character
        for (int i = 0; i < n; ++i) 
            dp[i][i] = 1;
        // iterate over all possible lengths
        for (int length = 2; length <= n; ++length) {
            // iterate over all possible starting indices
            for (int i = 0; i <= n - length; ++i) {
                int j = i + length - 1;
                // If s[i] == s[j], we can print s[i..j] in the same turn as s[i..j-1]
                if (s[i] == s[j]) 
                    dp[i][j] = dp[i][j - 1];
                // Otherwise, split the substring at various points and compute the minimum turns
                for (int k = i; k < j; ++k) 
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j]);
            }
        }
        // return minimum turns to print s[0..n-1]
        return dp[0][n - 1];
    }
};

// Solution 2 using Recursive DP
// Time complexity: O(n^3)
// Space complexity: O(n^2)
class Solution {
public:
    int strangePrinter(string s) {
        int n = s.size();
        // dp[i][j] = minimum number of turns to print s[i..j]
        vector<vector<int>> dp(n, vector<int>(n, -1));
        // return minimum turns to print s[0..n-1]
        return dfs(s, dp, 0, n - 1);
    }
    
    int dfs(string& s, vector<vector<int>>& dp, int i, int j) {
        // if i > j then we have printed the string
        if (i > j) return 0;
        // if dp[i][j] is already calculated then return it
        if (dp[i][j] != -1) return dp[i][j];
        // Initialize with the case where s[j] is printed in a new turn
        int ans = dfs(s, dp, i, j - 1) + 1;
        // Try to merge the printing of s[j] with previous characters
        for (int k = i; k < j; ++k) {
            // If s[k] is the same as s[j], they can be printed in the same turn
            if (s[k] == s[j]) {
                // Compute the minimum turns for the split substrings and update ans
                ans = min(ans, dfs(s, dp, i, k) + dfs(s, dp, k + 1, j - 1));
            }
        }
        // Store and return the computed result for dp[i][j]
        return dp[i][j] = ans;
    }
};
