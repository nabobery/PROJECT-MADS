// 2914. Minimum Number of Changes to Make Binary String Beautiful

// Solution 1: Greedy and Straight Forward
// Time complexity: O(n)
// Space complexity: O(1)
class Solution {
public:
    int minChanges(string s) {
        int n = s.size(), res = 0;
        // 11 or 00 consectuively
        for(int i = 1; i < n;i+= 2)
            if(s[i] != s[i-1]) res++;
        return res;
    }
};