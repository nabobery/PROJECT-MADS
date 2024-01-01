// 1531. String Compression II

// Solution 1 : Top Down DP
// Time Complexity: O(N^2 * K)
// Space Complexity: O(N * K)
class Solution {
public:
    int n;
    // dp[i][k] = min length of compressed string starting from index i(s[i:]) with at most k deletions
    vector<vector<int>> dp;
    // len(x) = length of x in compressed form
    int len(int x) {return x == 1 ? 0 : x < 10 ? 1 : x < 100 ? 2 : 3;}
    int helper(string& s, int i, int k){
        // if k < 0, it means we have deleted more than k characters, return a large value
        if(k < 0) return 101;
        // if we have reached the end of string or the remaining string is smaller than k(We can delete all), return 0
        if(i >= n || n - i <= k) return 0;
        // if we have already calculated the answer, return it
        if(dp[i][k] != -1) return dp[i][k];
        // otherwise, we have two options, either delete the current character or keep it
        // res = min length of compressed string starting from index i(s[i:]) with at most k deletions
        // mx = maximum number of occurences of any character in the current substring s[i:j]
        int res = n, mx = 0;
        // cnt[i] = number of occurences of character i in the current substring s[i:]
        int cnt[26] = {0};
        // iterate over all possible substrings s[i:j]
        for(int j = i; j < n;j++){
            // update the count of character s[j]
            mx = max(mx, ++cnt[s[j] - 'a']);
            // either delete the current character or keep it
            // if we delete anything from s[i:j], we delete such that we keep the maximum number of occurences of any character group and delete the rest (k - (j-i+1-mx))
            // length of compressed string starting is 1 + length of number of characters in the maximum character group + length of compresed string of helper(s, j+1, k - (j-i+1-mx))
            res = min(res, 1 + len(mx) + helper(s, j+1, k - (j-i+1-mx))); 
        }
        return dp[i][k] = res;
    }
    // the basic idea is to go through all possible substrings s[i:j] and keep the maximum number of occurences of any character group and delete the rest
    // so that we can compress the string as much as possible and get the minimum length and delete less characters
    // For Example We have aabbaa, we delete bb and get a4
    int getLengthOfOptimalCompression(string s, int k) {
        n = s.size();
        dp.resize(n, vector<int>(k+1, -1));
        return helper(s, 0, k);
    }
};


// Solution 2 : Bottom Up DP
// Time Complexity: O(N^2 * K)
// Space Complexity: O(N * K)
class Solution {
public:
    int len(int x) {return x == 1 ? 0 : x < 10 ? 1 : x < 100 ? 2 : 3;}
    int getLengthOfOptimalCompression(string s, int k) {
        int n = s.size();
        vector<vector<int>> dp(n+1, vector<int>(k+1, 101));
        // dp[i][j] = min length of compressed string ending at index i(s[:i]) with at most j deletions
        // base case when there's no string left and no deletions left
        dp[0][0] = 0;
        // iterate over all possible substrings s[:i]
        for(int i = 1; i <= n; i++){
            // iterate over all possible deletions
            for(int j = 0; j <= k; j++){
                // cnt = number of occurences of character s[i-1] in the current substring s[:i]
                int cnt = 0, del = 0;
                // we're trying to make a group of characters s[k:i] and delete the rest
                for(int k = i; k >= 0;k--){
                    // update the count of character s[i-1]
                    if (s[k-1] == s[i-1]) cnt++;
                    // else delete
                    else del++;
                    // if we can delete to make a group of characters s[k:i]
                    if(j - del >= 0) dp[i][j] = min(dp[i][j], len(cnt) + dp[k-1][j-del]);
                }
                // if we delete the current character s[i-1]
                if(j > 0) dp[i][j] = min(dp[i][j], dp[i-1][j-1]);
            }
        }
        return dp[n][k];
    }
};