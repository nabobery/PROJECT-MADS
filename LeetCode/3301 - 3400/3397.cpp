// 3397. Maximum Number of Distinct Elements After Operations

// Solution 1: Greedy Approach using Sorting
// Time Complexity: O(nlogn)
// Space Complexity: O(1)
class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        int n = nums.size(), res = 1;
        sort(nums.begin(), nums.end());
        nums[0] -= k;
        int prev = nums[0];
        for(int i = 1; i < n;i++){
            int mx = max(nums[i] - k -1, prev);
            if(nums[i]+k > mx) nums[i]=mx+1;
            else nums[i] += k;
            if(prev != nums[i]) res++;
            prev = nums[i];
        }
        return res;
    }
};