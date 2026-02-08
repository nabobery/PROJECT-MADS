// 3634. Minimum Removals to Balance 

// Solution 1: Sorting + Sliding Window
// Time Complexity: O(nlogn)
// Space Complexity: O(1)
class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        int n = nums.size(), res = n, l = 0;
        if(n == 1) return 0;
        sort(nums.begin(), nums.end());
        for(int r = 1; r < n;r++){
            while(l < r && nums[r] > (long)k*nums[l]) l++;
            res = min(res, n-(r-l+1));
        }
        return res;
    }
};