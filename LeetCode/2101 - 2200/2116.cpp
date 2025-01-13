// 2116. Check if a Parentheses String Can Be Valid

// Solution 1: O(n) using Greedy approach
// Time complexity: O(n)
// Space complexity: O(1)
// By iterating from left to right and right to left, we can check if the string can be valid
// If the number of open brackets is less than 0 at any point, then the string is invalid
// If the number of open brackets is less than 0 at any point, then the string is invalid
class Solution {
public:
    bool canBeValid(string s, string locked) {
        int cnt = 0, n = s.size();
        if(n % 2) return false;
        for(int i = 0; i < n;i++){
            if (locked[i] == '1') {
                if (s[i] == '(') ++cnt;
                else --cnt;
            } else ++cnt;
            if (cnt < 0) return false;
        }
        cnt = 0;
        for(int i = n-1; i >= 0;i--){
            if (locked[i] == '1') {
                if (s[i] == ')') ++cnt;
                else --cnt;
            } else ++cnt;
            if (cnt < 0) return false;
        }
        return true;
    }
};