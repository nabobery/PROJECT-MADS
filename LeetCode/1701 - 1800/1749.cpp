// 1749. Maximum Absolute Sum of Any Subarray

// Solution 1 using Prefix Sum and Store the minimum and maximum prefix sum enxountered so far
// Time Complexity: O(N)
// Space Complexity: O(1)
class Solution {
    public:
        int maxAbsoluteSum(vector<int>& nums) {
            int n = nums.size(), res = 0, mi = 0, mx = 0, prefix = 0;
            for(int i = 0; i < n;i++){
                prefix += nums[i];
                mx = max(mx, prefix);
                mi = min(mi, prefix);
                res = max(res, prefix - mi);
                res = max(res, mx - prefix);
            }
            return res;
        }
    };