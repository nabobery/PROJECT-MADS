// 1092. Shortest Common Supersequence 

// Solution 1: Iterative DP
// Time Complexity: O(n*m)
// Space Complexity: O(n*m)
class Solution {
    public:
        string shortestCommonSupersequence(string str1, string str2) {
            int n = str1.size(), m = str2.size();
            vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= m; j++) {
                    // base case when both characters are same then we can add that character to our supersequence
                    if (str1[i - 1] == str2[j - 1]) {
                        dp[i][j] = 1 + dp[i - 1][j - 1];
                    // if characters are different then we have to choose the maximum length sub sequence
                    } else {
                        dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                    }
                }
            }
            
            // now we have to find the supersequence by backtracking the LCS dp array
            int i = n, j = m;
            string res = "";
            // Shortest Common Supersequence = str1 + str2 - LCS
            // So, we will add the characters of str1 and str2 to our supersequence which are not part of LCS    
            while (i > 0 && j > 0) {
                // if characters are same then we will add that character to our supersequence
                if (str1[i - 1] == str2[j - 1]) {
                    res += str1[i - 1];
                    i--, j--;
                // if characters are different then we will add the character which contributes more to LCS
                } else if (dp[i - 1][j] > dp[i][j - 1]) {
                    res += str1[i - 1];
                    i--;
                } else {
                    res += str2[j - 1];
                    j--;
                }
            }
            
            // if we have reached the end of str1 then we will add the remaining characters of str2 to our supersequence
            while (i > 0) {
                res += str1[i - 1];
                i--;
            }
            // if we have reached the end of str2 then we will add the remaining characters of str1 to our supersequence
            while (j > 0) {
                res += str2[j - 1];
                j--;
            }
            // reverse the supersequence as we have added the characters in reverse order
            reverse(res.begin(), res.end());
            return res;
        }
};