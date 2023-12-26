// 1422. Maximum Score After Splitting a String

// Solution 1 by maintaing count of 0's and 1's
// Time complexity: O(n)
// Space complexity: O(1)
class Solution {
public:
    int maxScore(string s) {
        int ones = 0, zeroes = 0, result;
        for(char ch : s) if(ch == '1') ones++;
        if(s[0] == '0') zeroes++;
        else ones--;
        result = zeroes+ones;
        for(int i = 1; i < s.size()-1;i++){
            if(s[i] == '0') zeroes++;
            else ones--;
            result = max(zeroes+ones, result);
        }
        return result;
    }
};