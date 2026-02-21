// 3719. Longest Balanced Subarray I

// Solution 1: Brute Force using Sliding Window
// Time Complexity: O(n^2)
// Space Complexity: O(1)
class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int n = nums.size(), res = 0;
        
        for (int i = 0; i < n; i++) {
            // To store the unique odd and even numbers in the current window
            unordered_set<int> odd, even;
            for (int j = i; j < n; j++) {
                // Insert the current number into the respective set based on its parity
                if (nums[j] % 2 != 0) odd.insert(nums[j]);
                // even numbers are inserted into the even set
                else even.insert(nums[j]);
                
                // If the number of unique odd and even numbers are the same, update the result
                if (odd.size() == even.size()) {
                    res = max(res, j - i + 1);
                }
            }
        }
        // Return the length of the longest balanced subarray
        return res;
    }
};