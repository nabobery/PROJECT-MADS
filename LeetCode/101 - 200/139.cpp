// 139. Word Break

// O(n^3) time, O(n) space solution using Recursion and Memoization

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        // data structure to store the words
        unordered_set<string> st(wordDict.begin(), wordDict.end());
        // dp[i] = true if s[i...n-1] can be segmented into words
        vector<int> dp(s.size(), - 1);
        return helper(s, st, 0, dp);
    }

    bool helper(string& s, unordered_set<string> &st, int start, vector<int>& dp){
        // base case
        if(start == s.size()) return true;
        // if already calculated
        if(dp[start] != - 1) return dp[start];
        for(int end = start+1; end <= s.size();end++){
            // if the word is present in the dictionary and the remaining string can be segmented
            if(st.find(s.substr(start, end-start)) != st.end() && helper(s, st, end, dp)){
                return dp[start] = true;
            }
        }
        // if no word can be found
        return dp[start] = false;
    }
};

// O(n^3) time, O(n) space solution using DP Iterative

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        // data structure to store the words
        unordered_set<string> st(wordDict.begin(), wordDict.end());
        int n = s.size();
        // dp[i] = true if s[0...i-1] can be segmented into words
        vector<bool> dp(n+1,false);
        // base case
        dp[0] = true;
        for(int i = 1; i <= n;i++){
            for(int j = 0; j < i;j++){
                // dp[i] = true if s[j...i-1] can be segmented into words and dp[j] is true
                if(dp[j] && st.find(s.substr(j, i-j)) != st.end()){
                    dp[i] = true;
                    break;
                }
            }
        }
        // return the answer
        return dp[n];
    }

};