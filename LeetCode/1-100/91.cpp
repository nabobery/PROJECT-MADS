// 91. Decode Ways

// O(N) time and O(N) space solution (Top Down DP) Recursion with memoization
class Solution {
public:
    int helper(string& s,int i, vector<int>& dp){
        if(i == s.size()) return 1;
        if(dp[i] != -1) return dp[i];
        int result = 0;
        if(s[i] != '0') result += helper(s,i+1,dp);
        if(i+1 < s.size() && (s[i] == '1' || (s[i] == '2' && s[i+1] < '7'))) result += helper(s,i+2,dp);
        return dp[i] = result;
    }
    int numDecodings(string s) {
        vector<int> dp(s.size(), -1);
        return helper(s,0,dp);
    }
};

// O(N) time and O(1) space solution (Bottom Up DP) Iterative
class Solution {
public:
    int numDecodings(string s) {
        if(s[0] == '0') return 0;
        int n = s.size();
        vector<int>dp(n+1,0);
        dp[0] = dp[1] = 1;
        for(int i = 2; i <= n;i++){
            if(s[i-1] != '0') dp[i] += dp[i-1];
            if(s[i-2] == '1' || (s[i-2] == '2' && s[i-1] < '7')) dp[i] += dp[i-2];
        }
        return dp[n];
    }
};

// O(N) time and O(1) space solution (Bottom Up DP) Iterative
class Solution {
public:
    int numDecodings(string s) {
        if(s[0] == '0') return 0;
        int n = s.size();
        int prev = 1, curr = 1;
        for(int i = 2; i <= n;i++){
            int temp = 0;
            if(s[i-1] != '0') temp += curr;
            if(s[i-2] == '1' || (s[i-2] == '2' && s[i-1] < '7')) temp += prev;
            prev = curr;
            curr = temp;
        }
        return curr;
    }
};