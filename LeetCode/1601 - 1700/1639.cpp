// 1639. Number of Ways to Form a Target String Given a Dictionary


// Solution 1: Recursion with memoization (Bottom Up)
// Time complexity: O(n * m)
// Space complexity: O(n * m)
class Solution {
public:
    const int mod = 1e9 + 7;
    long helper(int ind, int indTarget, vector<vector<int>>& freq, string& target, vector<vector<long>>& dp){
        if(indTarget == target.size()) return 1;
        if (ind == freq.size()) return 0;
        if(dp[ind][indTarget] != -1) return dp[ind][indTarget];
        char ch = target[indTarget];
        long res = helper(ind+1, indTarget, freq, target, dp) % mod;
        int cnt = freq[ind][ch - 'a'];
        if(cnt)
            res = (res + cnt * helper(ind + 1, indTarget + 1, freq, target, dp) % mod) % mod;
        return dp[ind][indTarget] = res;
    }
    int numWays(vector<string>& words, string target) {
        int n = words.size(), m = words[0].size(), k = target.size();
        vector<vector<int>> freq(m, vector<int>(26, 0));
        vector<vector<long>> dp(m, vector<long>(k, -1));
        for(int i = 0; i < n;i++){
            for(int j = 0; j < m;j++){
                freq[j][words[i][j] - 'a']++;
            }
        }
        return helper(0, 0, freq, target, dp);
    }
};

// Solution 2: Iterative DP (Top Down)
// Time complexity: O(n * m)
// Space complexity: O(n * m)
class Solution {
public:
    const int mod = 1e9 + 7;
    int numWays(vector<string>& words, string target) {
        int n = words.size(), m = words[0].size(), k = target.size();
        vector<vector<int>> freq(m, vector<int>(26, 0));
        vector<vector<long>> dp(m, vector<long>(k, 0));
        for(int i = 0; i < n;i++){
            for(int j = 0; j < m;j++){
                freq[j][words[i][j] - 'a']++;
            }
        }
        for(int i = 0; i < m;i++){
            dp[i][0] = freq[i][target[0] - 'a'];
        }
        for(int i = 1; i < m;i++){
            dp[i][0] += dp[i-1][0];
        }
        for(int i = 1; i < m;i++){
            for(int j = 1; j < k;j++){
                dp[i][j] = (dp[i-1][j] + (long)freq[i][target[j] - 'a'] * dp[i-1][j-1]) % mod;
            }
        }
        return dp[m-1][k-1];
    }
};