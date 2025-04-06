// 2874. Maximum Value of an Ordered Triplet II

// Solution 1: Simple and Greedy Approach
// Time Complexity: O(n)
// Space Complexity: O(n)
class Solution {
    public:
        long long maximumTripletValue(vector<int>& nums) {
            long long res = 0;
            int n = nums.size();
            vector<int> maxdiff(n, 0);
            int mx = nums[0];
            // get max nums[i] for each j so we can calculate max(nums[i] - nums[j])
            for(int i = 1; i < n;i++){
                maxdiff[i] = max(maxdiff[i], mx - nums[i]);
                mx = max(nums[i], mx);
            }
            mx = maxdiff[1];
            // now for each j we can calculate max(nums[i] - nums[j]) for j > i
            for(int i = 2; i < n;i++){
                long long curr = mx;
                curr *= nums[i];
                res = max(res, curr);
                mx = max(mx, maxdiff[i]);
            }
            return res;
        }
};