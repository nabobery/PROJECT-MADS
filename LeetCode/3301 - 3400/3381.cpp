// 3381. Maximum Subarray Sum With Length Divisible by K

// Solution 1: Prefix Sum + Hash Map maintaining Modulo K 
// Time Complexity: O(N)
// Space Complexity: O(K)
class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        // Use a safe large number. 1e18 is often safer than LLONG_MAX 
        // to prevent overflow if you ever inadvertently add to it, 
        // though LLONG_MAX is fine with your current logic.
        vector<long long> minPrefix(k, 1e18); 
        
        long long currentPrefix = 0, maxSubSum = -1e18;
        
        // Base case: A prefix of length 0 has sum 0
        minPrefix[0] = 0;

        for (int i = 0; i < n; ++i) {
            currentPrefix += nums[i];
            
            // Explicitly define length to make the modulo logic clear
            int len = i + 1;
            int rem = len % k;

            // If we have seen a prefix with this remainder before,
            // we can form a valid subarray.
            if (minPrefix[rem] != 1e18) {
                maxSubSum = max(maxSubSum, currentPrefix - minPrefix[rem]);
            }

            // Update the minimum prefix sum for this remainder
            minPrefix[rem] = min(minPrefix[rem], currentPrefix);
        }

        return maxSubSum;
    }
};