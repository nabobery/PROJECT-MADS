// 214. Shortest Palindrome

// Solution 1 using String matching 
// Time complexity: O(n)
// Space complexity: O(n)
class Solution {
public:
    string shortestPalindrome(string s) {
        // Add a special character to avoid overlapping
        string str = s + '#';
        int n = s.size(), j=0;
        // Reverse the string and append it to the original string
        for(int i = n-1; i >= 0; i--) str += s[i];
        vector<int> vec(str.size(), 0);
        for(int i = 1; i < str.size();i++){
            // Find the longest prefix that is also a suffix
            while(j > 0 && str[i] != str[j]) j = vec[j-1];
            // If the characters match, increment the counter
            if(str[j] == str[i]){
                j += 1;
                // Store the length of the longest prefix that is also a suffix
                vec[i] = j;
            }
            // If the characters do not match, reset the counter
            else vec[i] = 0;
        }
        // The length of the longest prefix that is also a suffix 
        n -= vec.back();
        // Add the remaining characters to the beginning of the string
        string add = s.substr(s.size() - n);
        // Reverse the string and append it to the original string
        reverse(add.begin(), add.end());
        // Return the result
        return add + s;
    }
};