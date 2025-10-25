// 3346. Maximum Frequency of an Element After Performing Operations I

// Solution 1: Straight Forward Simulation using Sorting and Binary Search
// Time Complexity: O(n log n)
// Space Complexity: O(1)
class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int min_target = nums[0] - k;
        int max_target = nums[n - 1] + k;
        int maxFreq = 0;

        for (int target = min_target; target <= max_target; ++target) {
            auto it_total_low = lower_bound(nums.begin(), nums.end(), target - k);
            auto it_total_high = upper_bound(nums.begin(), nums.end(), target + k);
            int totalCount = distance(it_total_low, it_total_high);

            auto it_exact_low = lower_bound(nums.begin(), nums.end(), target);
            auto it_exact_high = upper_bound(nums.begin(), nums.end(), target);
            int exactCount = distance(it_exact_low, it_exact_high);

            int availableCount = totalCount - exactCount;
            int currentFreq = exactCount + min(availableCount, numOperations);
            maxFreq = max(maxFreq, currentFreq);
        }
        return maxFreq;
    }
};