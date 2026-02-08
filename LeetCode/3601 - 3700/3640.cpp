// 3640. Trionic Array II

// Solution 1: Dynamic Programming
// Time Complexity: O(n)
// Space Complexity: O(n)
// The idea is to use three arrays to keep track of the maximum sums of increasing, decreasing, and increasing again subsequences. 
// We iterate through the input array and update these arrays based on the conditions for increasing and decreasing sequences. 
// Finally, we return the maximum value from the inc2 array, which represents the maximum sum of a trionic sub array.
class Solution {
public:
    long long maxSumTrionic(vector<int>& nums) {
        int n = nums.size();
        // We use a large negative value to initialize the arrays to handle cases where there are no valid subsequences.
        long long INF = 1e16;
        // inc1[i] will store the maximum sum of an increasing subsequence ending at index i
        // dec[i] will store the maximum sum of a decreasing subsequence ending at index i
        // inc2[i] will store the maximum sum of an increasing subsequence that comes after a decreasing subsequence ending at index i
        vector<long long> inc1(n, -INF), dec(n, -INF), inc2(n, -INF);   
        long long res = -INF;
        for (int i = 1; i < n; i++) {
            // If the current number is greater than the previous number, we can either start a new increasing subsequence with these two numbers or extend the existing increasing subsequence.
            if (nums[i] > nums[i - 1]) {
                inc1[i] = max((long long)nums[i] + nums[i - 1], inc1[i - 1] + nums[i]);
            }
            // If the current number is less than the previous number, we can either start a new decreasing subsequence with these two numbers or extend the existing decreasing subsequence.
            if (nums[i] < nums[i - 1]) {
                dec[i] = max(inc1[i - 1] + nums[i], dec[i - 1] + nums[i]);
            }
            // If the current number is greater than the previous number, we can either start a new increasing subsequence that comes after a decreasing subsequence with these two numbers or extend the existing increasing subsequence that comes after a decreasing subsequence.
            if (nums[i] > nums[i - 1]) {
                inc2[i] = max(dec[i - 1] + nums[i], inc2[i - 1] + nums[i]);
            }
            // We update the result with the maximum value from the inc2 array.
            res = max(res, inc2[i]);
        }
        // return the maximum sum of a trionic sub array
        return res; 
    }
};