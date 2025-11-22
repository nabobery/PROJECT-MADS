// 3190. Find Minimum Operations to Make All Elements Divisible by Three

// Solution 1: Simple and Straightforward
// Time Complexity: O(n)
// Space Complexity: O(1)
// num% 3 has only three possible values: 0, 1, 2
// If num % 3 == 0, do nothing
// If num % 3 == 1 (subtract 1) or num % 3 == 2 (add 1), we need one operation to make it divisible by 3
class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int res = 0;
        for(int& num: nums) res += (num % 3 != 0);
        return res;
    }
};