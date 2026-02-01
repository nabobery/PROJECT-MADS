// 1984. Minimum Difference Between Highest and Lowest of K Scores

// Solution 1 Using Sorting and Sliding Window (AC)
// Time Complexity: O(N log N)
// Space Complexity: O(1)
class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        if(k == 1) return 0;
        sort(nums.begin(), nums.end());
        int res = INT_MAX, n = nums.size();
        for(int i = k-1; i < n;i++){
            res = min(res, nums[i] - nums[i-k+1]);
        }
        return res;
    }
};