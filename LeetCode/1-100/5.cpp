// 5. Longest Palindromic Substring

// naive TLE Solution O(n^3) time and space solution
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

// DP table O(n^2) time and space solution
class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        if(n == 1) return s;
        string result = "";
        vector<vector<bool>> dp(n , vector<bool> (n, false));
        // base case where i == j 
        for(int i = 0; i < n;i++){
            dp[i][i] = true;
        }
        // base case where i == j+1
        for(int i = 0; i < n-1;i++) dp[i][i+1] = (s[i] == s[i+1]);
        // we start from the end and fill the table from bottom to top
        for(int i = n-3; i>=0; --i){
            for(int j = i+2;j<n; ++j){
                // if the chars are equal and the substring between them is a palindrome
                dp[i][j] = (dp[i+1][j-1] && s[i] == s[j]);
            }
        }
        // find the longest palindrome
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
        while (left>= 0 && right < s.size() && s[left] == s[right]) {
            left--;
            right++;
        }
        return right - left- 1;
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

// greedy and fast where we skip duplicate chars O(n^2) time and O(1) space
class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        if(n == 1) return s;
        string result = "";
        int max = 0;
        for(int i = 0; i < n;){
            int j = i;
            int k = i;
            // skip duplicate chars
            while(k < n-1 && s[k] == s[k+1]) k++;
            i = k+1;
            // expand around center until it's not a palindrome
            while(j > 0 && k < n-1 && s[j-1] == s[k+1]){
                j--;
                k++;
            }
            // if length greater than previous length
            if(k-j+1 > max){
                max = k-j+1;
                result = s.substr(j,k-j+1);
            }
        }
        return result;
    }
};
