// 3392. Count Subarrays of Length Three With a Condition

// Solution 1: Straightforward approach
// Time Complexity: O(n)
// Space Complexity: O(1)
class Solution {
    public:
        int countSubarrays(vector<int>& nums) {
            int res = 0, n = nums.size();
            for(int i = 0; i < n-2;i++){
                if(2*(nums[i] + nums[i+2]) == nums[i+1]) res++;
            }
            return res;
        }
};