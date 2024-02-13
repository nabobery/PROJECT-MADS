// 2108. Find First Palindromic String in the Array

// Solution 1  checking palindrome using two pointers
// Time Complexity: O(n^2)
// Space Complexity: O(1)
class Solution {
public:
    bool isPalindrome(string& s){
        int n = s.size();
        for(int i = 0; i < n/2;i++)
            if(s[i] != s[n-i-1]) return false;
        return true;
    }
    string firstPalindrome(vector<string>& words) {
        for(string& word : words)
            if(isPalindrome(word)) return word;
        return "";
    }
};

// Solution 2 checking palindrome using string reversal
// Time Complexity: O(n^2)
// Space Complexity: O(n)
class Solution {
public:
    bool isPalindrome(string& s){
        string temp = s;
        reverse(temp.begin(), temp.end());
        return (temp == s);
    }
    string firstPalindrome(vector<string>& words) {
        for(string& word : words)
            if(isPalindrome(word)) return word;
        return "";
    }
};