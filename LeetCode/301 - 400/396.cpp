// 396. Rotate Function

// Solution 1: Dynamic Programming
// Time Complexity: O(n)
// Space Complexity: O(1)
// The key idea is to find the relationship between F(k) and F(k-1).
// F(k) = F(k-1) + sum - n * nums[n-k]
// Example:
// F(0) = 0 * nums[0] + 1 * nums[1] + ... + (n-1) * nums[n-1]
// F(1) = 0 * nums[n-1] + 1 * nums[0] + 2 * nums[1] + ... + (n-1) * nums[n-2]
class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n = nums.size();
        int sum = 0, fk = 0, res = INT_MIN;
        // Calculate F(0) and sum of nums
        for (int i = 0; i < n; i++) {
            sum += nums[i];
            fk += (i * nums[i]);
        }
        res = max(res, fk);
        // Calculate F(k) for k = 1 to n-1 using the relationship with F(k-1)
        for (int k = 1; k < n; k++) {
            fk = fk + sum - n * nums[n - k];
            res = max(res, fk);
        }
        return res;
    }
};