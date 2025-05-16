// 1920. Build Array from Permutation

// Solution 1: Simple Iteration
// Time Complexity: O(n)
// Space Complexity: O(n)
class Solution {
    public:
        vector<int> buildArray(vector<int>& nums) {
            int n = nums.size();
            vector<int> res(n);
            for(int i = 0; i < n;i++) res[i] = nums[nums[i]];
            return res;
        }
    };