// 3423. Maximum Difference Between Adjacent Elements in a Circular Array

// Solution 1: Easy and Straight Forward
// Time Complexity: O(n)
// Space Complexity: O(1)
class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        int n = nums.size(), res = abs(nums[0] - nums[n-1]);
        for(int i = 1; i < n;i++) res = max(res, abs(nums[i] - nums[i-1]));
        return res;
    }
};