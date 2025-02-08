// 1800. Maximum Ascending Subarray Sum

// Solution 1:Easy Straightforward Approach
// Time complexity: O(n)
// Space complexity: O(1)
class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int res = 0, n = nums.size(), i = 0;
        while(i < n){
            int curr = nums[i];
            int j = i+1;
            while(j < n && nums[j] > nums[j-1]){
                curr += nums[j];
                j++;
            }
            res = max(curr, res);
            i = j;
        }
        return res;
    }
};