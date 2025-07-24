// 2016. Maximum Difference Between Increasing Elements

// Solution 1: Simple and Straightforward approach
// Time Complexity: O(n)
// Space Complexity: O(1)
// The idea is to keep track of the minimum and maximum values seen so far and calculate the maximum difference
class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int res = -1, n = nums.size(), mi = nums[0], mx = nums[0];
        for(int i = 1; i < n;i++){
            if(nums[i] > mx){
                mx = nums[i];
                res = max(res, mx - mi);
            }
            else if(nums[i] < mi){
                mx = nums[i];
                mi = nums[i];
            }
        }
        return res;
    }
};