// 2033. Minimum Operations to Make a Uni-Value Grid

// Solution 1: Using Sorting and Selecting Median Element as the uni-value
// Time Complexity: O(m*n log m*n)
// Space Complexity: O(m*n)
class Solution {
    public:
        int minOperations(vector<vector<int>>& grid, int x) {
            int res = -1, m = grid.size(), n = grid[0].size();
            vector<int> nums(m*n);
            for (int i = 0; i < m; i++)
                for (int j = 0; j < n; j++)
                    nums[i*n + j] = grid[i][j];
            sort(nums.begin(), nums.end());
            int median = nums[m * n / 2], curr = 0;
            bool b = true;
            long sum = 0;
            for (int& num : nums) {
                int diff = abs(median - num);
                sum += diff;
                if (diff % x != 0) {
                    b = false;
                    break;
                }
                curr += (diff / x);
            }
            if (b)
                res = curr;
            return res;
        }
};