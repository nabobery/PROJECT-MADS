// 647. Palindromic Substrings

// Solution 1 using DP (maintaining a 2D array to store if the substring sl,.... sr is a palindrome or not)
// Time complexity: O(n^2)
// Space complexity: O(n^2)
class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size(), res = n;
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        for(int i = 0; i < n;i++) dp[i][i] = true;
        for(int l = n-2; l >= 0;l--){
            for(int r = l+1; r < n;r++){
                if(s[l] == s[r] && (r-l == 1 || dp[l+1][r-1])){
                    dp[l][r] = true;
                    res++;
                }
            }
        }
        return res;
    }
};

// Solution 2 using Expand Around Center
// By breaking the string into two cases, one is the palindrome has odd length and the other is the palindrome has even length
// Time complexity: O(n^2)
// Space complexity: O(1)
class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size(), res = 0;
        for(int i = 0; i < n;i++){
            res += countPalindromes(s, i, i);
            res += countPalindromes(s, i, i+1);
        }
        return res;
    }
    
    int countPalindromes(string s, int l, int r){
        int res = 0;
        while(l >= 0 && r < s.size() && s[l] == s[r]){
            l--;
            r++;
            res++;
        }
        return res;
    }
};

// Solution 3 using Manacher's Algorithm which is an algorithm that finds the longest palindromic substring in linear time
// The idea is to preprocess the string and insert special characters between each character and at the beginning and end of the string
// Then, we iterate through the string and for each character, we find the length of the longest palindromic substring with the character as the center
// We maintain a center c and a right boundary r and for each character i, we find the mirror of i with respect to c and use the previously calculated values to find the length of the longest palindromic substring with i as the center
// Time complexity: O(n)
// Space complexity: O(n)
class Solution {
public:
    int countSubstrings(string s) {
        string t = "$#";
        for(char c : s){
            t += c;
            t += '#';
        }
        t += '@';
        int n = t.size(), c = 0, r = 0;
        vector<int> p(n, 0);
        for(int i = 1; i < n-1;i++){
            int mirror = 2*c-i;
            if(i < r) p[i] = min(r-i, p[mirror]);
            while(t[i+(1+p[i])] == t[i-(1+p[i])]) p[i]++;
            if(i+p[i] > r){
                c = i;
                r = i+p[i];
            }
        }
        int res = 0;
        for(int i = 1; i < n-1;i++) res += (p[i]+1)/2;
        return res;
    }
};