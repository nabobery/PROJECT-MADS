// 918. Maximum Sum Circular Subarray

// O(n) time, O(1) space solution
class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int curr_max = 0, curr_min = 0, sum = 0, max_sum = nums[0], min_sum = nums[0];
        for (int num : nums) {
            // Kadane's algorithm for max subarray sum for the max subarray in the middle case
            curr_max = max(curr_max, 0) + num;
            max_sum = max(max_sum, curr_max);
            // Kadane's algorithm for min subarray sum for the max subarray split across the end and start of the array case
            curr_min = min(curr_min, 0) + num;
            min_sum = min(min_sum, curr_min);
            // Total sum of the array
            sum += num;
        }
        return sum == min_sum ? max_sum : max(max_sum, sum - min_sum);
    }
};




