// 2270. Number of Ways to Split Array

// Solution 1: Using prefix sum
// Time complexity: O(n)
// Space complexity: O(n)
class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int n = nums.size();
        vector<long> prefix(n+1, 0);
        for(int i = 0; i < n;i++)
            prefix[i+1] = prefix[i] + nums[i];
        int res = 0;
        for(int i = 0; i < n-1;i++){
            long left = prefix[i+1] - prefix[0], right = prefix[n] - prefix[i+1];
            res += (left >= right);
        }
        return res;
    }
};