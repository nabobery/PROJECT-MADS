// 1143. Longest Common Subsequence

// O(mn) time, O(mn) space DP solution (recursive + memoization)
class Solution {
public:
    int helper(int i, int j, string& s1, string& s2, vector<vector<int>>& dp){
        // base case (if we reach the start of any string, return 0)
        if(i < 0 || j < 0) return 0;
        // if we have already computed the answer for this subproblem, return it
        if(dp[i][j] != -1) return dp[i][j];
        // if the characters at the current indices are equal, we can include them in the LCS
        if(s1[i] == s2[j]) return dp[i][j] = 1 + helper(i-1,j-1,s1,s2,dp);
        // if the characters at the current indices are not equal, we have to exclude one of them
        else return dp[i][j] = max(helper(i-1,j,s1,s2,dp), helper(i,j-1,s1,s2,dp));
    }
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size(), n = text2.size();
        vector<vector<int>> dp(m, vector<int>(n,-1));
        return helper(m-1,n-1,text1,text2,dp);
    }
};

// O(mn) time, O(mn) space DP solution (iterative)
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size(), n = text2.size();
        vector<vector<int>> dp(m+1, vector<int>(n+1,0));
        for(int i = 1; i <= m; i++){
            for(int j = 1; j <= n; j++){
                if(text1[i-1] == text2[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
                else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        return dp[m][n];
    }
};


// O(mn) time, O(n) space DP solution (iterative)
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size(), n = text2.size();
        vector<int> dp(n+1,0);
        // we can use a single array to store the previous row of the DP table since we only need the previous row to compute the current row and update it in-place
        // we can use a single variable to store the previous value of the current cell since we only need the previous value to compute the current value we can use a single variable to store the current value of the current cell 
        for(int i = 1; i <= m; i++){
            int prev = 0;
            for(int j = 1; j <= n; j++){
                int temp = dp[j];
                // dp[i][j] = 1 + dp[i-1][j-1];
                if(text1[i-1] == text2[j-1]) dp[j] = 1 + prev;
                // dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                else dp[j] = max(dp[j], dp[j-1]);
                // update the previous value of the current cell
                prev = temp;
            }
        }
        return dp[n];
    }
};
