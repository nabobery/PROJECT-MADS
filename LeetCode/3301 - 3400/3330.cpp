// 3330. Find the Original Typed String I

// Solution 1: Simple and Straightforward approach
// Time Complexity: O(n)
// Space Complexity: O(1)
class Solution {
public:
    int possibleStringCount(string word) {
        int res = 1, n = word.size(), curr = 0;
        for(int i = 1; i < n;i++){
            if(word[i] == word[i-1]) curr++;
            else{
                res += curr;
                curr = 0;
            }
        }
        res += curr;
        return res;
    }
};