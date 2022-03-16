// 215. Kth Largest Element in an Array
// my naive 2 liner solution
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        return nums[nums.size() -k];
    }
};
