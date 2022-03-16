// 5. Longest Palindromic Substring
// my naive TLE Solution O(n^3) time and space solution
class Solution {
public:
    bool isPalindrome(string s){
        int n = s.size();
        if(n == 1) return true;
        for(int i = 0; i < n/2;i++){
            if(s[i] != s[n-i-1]) return false;
        }
        return true;
    }
    string longestPalindrome(string s) {
        int n = s.size();
        if(n == 1) return s;
        string result = "";
        for(int i = 0; i < n;i++){
            for(int j = n -1; j >= i;j--){
                string temp = s.substr(i,abs(j-i+1));
                if(isPalindrome(temp)){
                    if(temp.size() > result.size())
                        result = temp;
                }
            }
        }
        return result;
    }
};

// using DP table O(n^2) time and space solution
class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        if(n == 1) return s;
        string result = "";
        vector<vector<bool>> dp(n , vector<bool> (n, false));
        for(int i = 0; i < n;i++){
            dp[i][i] = true;
        }
        for(int i = 0; i < n-1;i++) dp[i][i+1] = (s[i] == s[i+1]);
        for(int i = n-3; i>=0; --i){
            for(int j = i+2;j<n; ++j){
                dp[i][j] = (dp[i+1][j-1] && s[i] == s[j]);
            }
        }
        int max = 0;
        for(int i = 0;i < n;i++){
            for(int j = i;j < n;j++){
                if(dp[i][j] && j-i+1 > max){
                    max = j-i+1;
                    result = s.substr(i,j-i+1);
                }
            }
        }
        return result;
    }
};

// expand around center O(n^2) time and O(1) space
class Solution {
public:
    int expandAroundCenter(string s, int left, int right) {
        int L = left, R = right;
        while (L >= 0 && R < s.size() && s[L] == s[R]) {
            L--;
            R++;
        }
        return R - L - 1;
    }
    string longestPalindrome(string s) {
        if (s.length() == 1) return s;
        int start = 0, end = 0;
        for (int i = 0; i < s.size(); i++) {
            int len1 = expandAroundCenter(s, i, i); // odd length
            int len2 = expandAroundCenter(s, i, i + 1); // even length
            int len = max(len1, len2); // taking max
            // if length greater than previous length
            if (len > end - start) {
                start = i - (len - 1) / 2; // getting start from length and center i
                end = i + len / 2; // getting end from length and center i
            }
        }
        return s.substr(start, end - start + 1);
    }
};

// greedy and fast where we skip duplicate chars
class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        if(n < 2) return s;
        int maxIdx = 0;
        int maxLen = 1;
        int i = 0;
        while (i < n) {
            int start = i;
            int end = i;
            // expand the window from the end if it's an even palindrome and skip duplicates
            while (end + 1 < n && s[end] == s[end + 1]) end++;
            i = end + 1;
            // expand the window from both sides until it's not longer a palindrome
            while (start - 1 >= 0 && end + 1 < s.size() && s[start - 1] == s[end + 1]) {
                start--, end++;
            }
            int currLen = end - start + 1;
            if (currLen > maxLen) {
                maxIdx = start;
                maxLen = currLen;
            }
        }
        return s.substr(maxIdx, maxLen);
    }
};
