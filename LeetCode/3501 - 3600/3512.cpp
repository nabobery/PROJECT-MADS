// 3512. Minimum Operations to Make Array Sum Divisible by K

// Solution 1: Simple Math
// Time Complexity: O(n)
// Space Complexity: O(1)
class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int sum = 0;
        for(int& num: nums) sum += num;
        return sum%k;
    }
};