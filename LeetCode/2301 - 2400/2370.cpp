// 2370. Longest Ideal Subsequence

// Solution 1 using Top Down DP (Recursion + Memoization)
// Time complexity: O(n*26) = O(n)
// Space complexity: O(n*26) = O(n)
class Solution {
public:
    // helper function to find the longest ideal string starting from index i with prevChar
    int helper(int i, char prevChar, string& s, int& k, vector<vector<int>>& dp){
        // base case when i reaches the end of the string
        if(i >= s.size()) return 0;
        // if the result is already calculated, return it
        if(dp[i][prevChar - 'a'] != -1) return dp[i][prevChar - 'a'];
        // don't take current char into subsequence and find the longest ideal string starting from index i+1 with prevChar = prevChar
        int notTake = helper(i+1, prevChar, s, k ,dp), take = 0;
        // take the current char only if it is equal to prevChar or the difference between them is less than or equal to k
        if(prevChar > 'z' || abs(s[i] - prevChar) <= k) take += 1 + helper(i+1, s[i], s, k, dp);
        // 
        return dp[i][prevChar - 'a'] = max(take, notTake);
    }
    int longestIdealString(string s, int k) {
        int n = s.size();
        // 26 is the number of characters in the alphabet and 27 is for the case when prevChar doesn't exist
        vector<vector<int>> dp(n, vector<int>(27, -1));
        // return longest ideal string starting from index 0 with prevChar = 'z' + 1
        return helper(0, 'z' + 1, s, k, dp);
    }
};

// Solution 2 using Bottom Up DP (Iterative) with Space Optimization
// Time complexity: O(n*26) = O(n)
// Space complexity: O(26)
// The idea is to fill the dp array from the end of the string to the beginning
// dp[c] stores the length of the longest ideal subsequence where the last character is c
// we go thorugh every index from the end and for each index we calculate the longest ideal subsquence where the last char is the current and update the dp array
// if the prev and current char are equal or the difference between them is less than or equal to k, we can take the current char into the subsequence
class Solution {
public:
    int longestIdealString(string s, int k) {
        int n = s.size(), res = 0;
        vector<int> dp(26, 0);
        for(int i = n-1;i >= 0;i--){
            int curr = s[i] - 'a';
            int take = 0;
            for(int prev = 0;prev < 26;prev++)
                if(abs(curr - prev) <= k) take = max(take, dp[prev]);
            dp[curr] = max(dp[curr], 1 + take);
            res = max(res, dp[curr]);
        }
        return res;
    }
};
