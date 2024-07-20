// 1509. Minimum Difference Between Largest and Smallest Value in Three Moves

// Solution 1 using Greedy Approach and Sorting
// Time Complexity: O(nlogn)
// Space Complexity: O(1)
// The idea is to sort the array and then try to remove 3 elements from the start or end and find the minimum difference between the largest and smallest element in the remaining array.
class Solution {
public:
    int minDifference(vector<int>& nums) {
        int n = nums.size();
        if (n <= 4) return 0;
        sort(nums.begin(), nums.end());
        int res = INT_MAX;
        for (int i = 0; i < 4; i++) 
            res = min(res, nums[n - 4 + i] - nums[i]);
        return res;
    }
};