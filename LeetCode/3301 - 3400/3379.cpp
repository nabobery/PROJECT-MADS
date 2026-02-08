// 3379. Transformed Array

// Solution 1: Simple Simulation
// Time Complexity: O(n)
// Space Complexity: O(1) (ignoring the output array)
class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n, 0);
        for(int i = 0; i < n;i++)
            res[i] = nums[((i+nums[i])%n+n)%n];
        return res;
    }
};