// 1574. Shortest Subarray to be Removed to Make Array Sorted

// Solution 1: Two Pointers
// Time Complexity: O(n)
// Space Complexity: O(1)
class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int n = arr.size();
        int left = 0, right = n-1;
        // Find the longest non-decreasing prefix
        while (left + 1 < n && arr[left] <= arr[left + 1]) {
            ++left;
        }
        // If the array is already sorted
        if (left == n - 1) return 0;
        // Find the longest non-decreasing suffix
        while (right - 1 >= 0 && arr[right - 1] <= arr[right]) {
            --right;
        }
        // Keep only the sorted prefix or suffix
        int res = min(n - left - 1, right);
        // Merge the prefix and suffix and find the shortest subarray to remove
        for (int i = 0; i <= left; ++i) {
            // check if we have to move thr right pointer to include the current element of the prefix
            while (right < n && arr[i] > arr[right]) {
                ++right; 
            }
            // update the result
            res = min(res, right - i - 1);
        }
        return res;
    }
};