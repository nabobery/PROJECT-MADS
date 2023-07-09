// 516. Longest Palindromic Subsequence

// O(n^2) time, O(n^2) space DP solution (recursive + memoization)
class Solution {
public:
    int helper(string& s, int l, int r, vector<vector<int>>& dp){
        // base case 
        if(l == r) return dp[l][r] = 1;
        // return 0 if l > r as it is not a subsequence
        if(l > r) return 0;
        // return if already calculated
        if(dp[l][r]) return dp[l][r]; 
        // if the characters are equal, then add 2 to the length of the longest palindromic subsequence in the remaining string
        // else, take the max of the length of the longest palindromic subsequence in the remaining string by removing the leftmost character or the rightmost character
        return dp[l][r] = s[l] == s[r] ? 2 + helper(s,l+1,r-1, dp) : max(helper(s,l,r-1, dp),helper(s,l+1,r, dp));
    }
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n));
        return helper(s,0,n-1, dp);
    }
};

// O(n^2) time, O(n^2) space DP solution (iterative)
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n));
        // base case
        for(int i = 0; i < n; i++) dp[i][i] = 1;
        // fill the dp table
        for(int i = n-1; i >= 0; i--){
            for(int j = i+1; j < n; j++){
                if(s[i] == s[j]) dp[i][j] = 2 + dp[i+1][j-1];
                else dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
            }
        }
        return dp[0][n-1];
    }
};