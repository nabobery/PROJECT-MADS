// 2348. Number of Zero-Filled Subarrays

// Solution 1: Simple and Straight Forward (Math and counting)
// Time Complexity: O(n)
// Space Complexity: O(1)
class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long res = 0;
        int n = nums.size(), curr = 0;
        for(int i = 0; i < n;i++){
            if(nums[i] == 0) curr++;
            else curr = 0;
            res += curr;
        }
        return res;
    }
};