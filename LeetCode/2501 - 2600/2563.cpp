// 2563. Count the Number of Fair Pairs

// Solution 1 using Sorting and Binary Search
// Time complexity: O(nlogn)
// Space complexity: O(1)
class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        long long res = 0;
        // Sort the array
        sort(nums.begin(), nums.end());
        // Iterate through the array
        for(int i = 0; i < nums.size();i++){
            // Calculate the left and right values required to make the pair fair with the current element
            int left = lower - nums[i], right = upper - nums[i];
            auto lb = lower_bound(nums.begin() + i + 1, nums.end(), left);
            auto ub = upper_bound(nums.begin() + i + 1, nums.end(), right);
            // Add the number of fair pairs to the result
            res += distance(lb, ub);
        }
        return res;
    }
};