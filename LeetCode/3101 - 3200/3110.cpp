// 3110. Score of a String

// Solution 1 Simple Iteration
// Time complexity: O(n)
// Space complexity: O(1)
class Solution {
public:
    int scoreOfString(string s) {
        int n = s.size(), res = 0;
        for(int i = 1; i < n;i++) res += abs(s[i] - s[i-1]);
        return res;
    }
};
