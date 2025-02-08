// 3105. Longest Strictly Increasing or Strictly Decreasing Subarray

// Solution 1: Straightforward by checking if the array is strictly increasing or strictly decreasing
// Time complexity: O(n)
// Space complexity: O(1)
class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int res = 1, i = 0, n = nums.size();
        while(i < n){
            int j = i+1;
            while(j < n && nums[j] > nums[j-1]) j++;
            res = max(res, j-i);
            i = j;
        }
        i = 0;
        while(i < n){
            int j = i+1;
            while(j < n && nums[j] < nums[j-1]) j++;
            res = max(res, j-i);
            i = j;
        }
        return res;
    }
};