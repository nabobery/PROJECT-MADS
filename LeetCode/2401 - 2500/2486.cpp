// 2486. Append Characters to String to Make Subsequence

// Solution 1 Simple Traversal and checking util which index subsequence is present
// Time complexity: O(n)
// Space complexity: O(1)
class Solution {
public:
    int appendCharacters(string s, string t) {
        int n = t.size(), p = 0;
        for(char ch : s){
            if(p >= n) break;
            if(ch == t[p]) p++;
        }
        return (n-p);
    }
};

// Cleaner version of Solution 1
class Solution {
public:
    int appendCharacters(string s, string t) {
        int n = t.size(), p = 0;
        for(char ch : s)
            if(p < n && ch == t[p]) p++;
        return (n-p);
    }
};