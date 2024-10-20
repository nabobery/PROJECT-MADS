// 2044. Count Number of Maximum Bitwise-OR Subsets

// Solution 1 using Bit manipulation
// Time complexity: O(2^n)
// Space complexity: O(1)
class Solution {
public:
    int res, mx;
    void helper(vector<int>& nums, int index, int curr){
        if(index == nums.size()){
            if (curr == mx) res++;
            return;
        }
        helper(nums, index+1, curr);
        helper(nums, index+1, curr |= nums[index]);
    }
    int countMaxOrSubsets(vector<int>& nums) {
        mx = 0;
        for(int num: nums) mx |= num;
        res = 0;
        helper(nums, 0, 0);
        return res;
    }
};