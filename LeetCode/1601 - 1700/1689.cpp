// 1689. Partitioning Into Minimum Number Of Deci-Binary Numbers

// Solution 1: Greedy and Straight Forward
// Time Complexity: O(n)
// Space Complexity: O(1)
// The observation was the first number in every string should be 1
// also, we can manipulate the string by setting zeroes and ones in the other part of string
// so the answer is the maximum digit in the string because we can set all the digits in the string to zero except the maximum digit and we can set it to one and we can repeat this process until we reach the original string.
class Solution {
public:
    int minPartitions(string n) {
        int res = 0;
        for(auto& ch : n) res = max(res, ch - '0');
        return res;
    }
};