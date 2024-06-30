// 330. Patching Array

// Solution 1 using Greedy Approach
// Time complexity: O(logn)
// Space complexity: O(1)

// The idea is to keep track of the smallest sum that we can't make using the numbers we have seen so far.
// If the next number is less than or equal to the sum, we can make all the sums from 1 to sum + nums[i] - 1.
// If the next number is greater than the sum, we can't make the sum using the numbers we have seen so far.
// So, we add the sum to the array and increment the answer.
class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        long long miss = 1;
        int patches = 0, i = 0;
        while (miss <= n) {
            // If the next number is less than or equal to the sum, we can make all the sums from 1 to sum + nums[i] - 1.
            if (i < nums.size() && nums[i] <= miss) {
                miss += nums[i++];
            // If the next number is greater than the sum, we can't make the sum using the numbers we have seen so far.
            } else {
                // Add the sum to the array and increment the answer.
                miss += miss;
                patches++;
            }
        }
        return patches;
    }
};