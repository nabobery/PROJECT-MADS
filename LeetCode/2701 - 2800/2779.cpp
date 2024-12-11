// 2779. Maximum Beauty of an Array After Applying Operation

// Solution 1: Using sorting and sliding window
// Time Complexity: O(nlogn)
// Space Complexity: O(n)
class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int res = 0, l = 0, n = nums.size();
        for(int r = 0; r < n;r++){
            if(nums[r] - nums[l] > 2*k){
                while(nums[r] - nums[l] > 2*k) l++;
            }
            res = max(res, r-l+1);
        }
        return res;
    }
};