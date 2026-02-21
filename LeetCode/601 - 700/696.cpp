// 696. Count Binary Substrings


// Solution 1: Count the number of consecutive 0's and 1's and add the minimum of the two counts to the result
// Time Complexity: O(n) where n is the length of the input string
// Space Complexity: O(1)
class Solution {
public:
    int countBinarySubstrings(string s) {
        int currNum = s[0] - '0', currCount = 1, n = s.size(), res = 0;
        int prevCount[2] = {-1, -1};
        for(int i = 1; i < n;i++){
            if(currNum == s[i] - '0') currCount++;
            else{
                if(prevCount[1-currNum] != -1) res += min(currCount, prevCount[1-currNum]);
                prevCount[currNum] = currCount;
                currNum = s[i] - '0';
                currCount = 1;
            }
        }
        if(prevCount[1-currNum] != -1) res += min(currCount, prevCount[1-currNum]);
        return res;
    }
};

// Solution 2: Simpler and Elegant version of Solution 1
// Time Complexity: O(n) where n is the length of the input string
// Space Complexity: O(1)
class Solution {
public:
    int countBinarySubstrings(string s) {
        int res = 0, prevCount = 0, currCount = 1;
        for (int i = 1; i < s.size(); ++i) {
            if (s[i] == s[i - 1]) {
                currCount++;
            } else {
                res += min(prevCount, currCount);
                prevCount = currCount;
                currCount = 1;
            }
        }
        return res + min(prevCount, currCount);
    }
};