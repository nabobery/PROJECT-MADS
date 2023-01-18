// 918. Maximum Sum Circular Subarray

class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int curr_max = 0, curr_min = 0, sum = 0, max_sum = nums[0], min_sum = nums[0];
        for (int num : nums) {
            curr_max = max(curr_max, 0) + num;
            max_sum = max(max_sum, curr_max);
            curr_min = min(curr_min, 0) + num;
            min_sum = min(min_sum, curr_min);
            sum += num;
        }
        return sum == min_sum ? max_sum : max(max_sum, sum - min_sum);
    }
};


