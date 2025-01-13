// 3223. Minimum Length of String After Operations

// Solution 1: Greedy by checking parity
// Time complexity: O(n)
// Space complexity: O(1)
// The idea is to check the parity of the number of each character in the string. 
// If the number of a character is odd, we can remove all of them except one.
// If the number of a character is even, we can remove all of them except two.
class Solution {
public:
    int minimumLength(string s) {
        int res = s.size();
        vector<int> cnt(26, 0);
        for(char& ch : s) cnt[ch -'a']++;
        for(int i : cnt)
            if(i >= 3) res -= (i -1 - (i%2 == 0));
        return res;
    }
};