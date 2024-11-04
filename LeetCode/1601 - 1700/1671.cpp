// 1671. Minimum Number of Removals to Make Mountain Array

// Solution 1 by getting the longest mountain array possible
// The idea is to get the longest mountain array possible and then subtract it from the total length of the array
// We can get the longest mountain array by using the longest increasing subsequence algorithm
// Time complexity: O(n^2)
// Space complexity: O(n)
class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        int n = nums.size(), res = n;
        vector<int> left(n, 1), right(n, 1);
        // Longest increasing subsequence from left
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[i] > nums[j]) {
                    left[i] = max(left[i], left[j] + 1);
                }
            }
        }
        // Longest increasing subsequence from right
        for (int i = n-2; i >= 0; i--) {
            for (int j = n-1; j > i; j--) {
                if (nums[i] > nums[j]) {
                    right[i] = max(right[i], right[j] + 1);
                }
            }
        }
        // Find the longest mountain array
        for(int i = 1; i < n-1;i++){
            // If the current element is the peak of the mountain
            if(left[i] > 1 && right[i] > 1)
                res = min(res, n - left[i] - right[i]+1);
        }
        return res;
    }
};