// 3578. Count Partitions With Max-Min Difference at Most K

// Solution 1: Using Sliding Window + Dynamic Programming + Monotonic Deque
// Time Complexity: O(n)
// Space Complexity: O(n)
class Solution {
public:
    const int mod = 1e9 + 7;
    int countPartitions(vector<int>& nums, int k) {
        int n = nums.size(), l = 0;
        
        // dp[i] denotes the number of ways to partition the prefix nums[0..i-1]
        // Size is n+1 because dp[0] represents an empty prefix.
        vector<int> dp(n+1, 0);
        
        // Base case: One way to partition an empty array (do nothing).
        dp[0] = 1;
        
        // prefixDp[i] denotes the sum of dp[0]...dp[i-1]
        // This allows us to calculate the sum of a range of dp values in O(1).
        // Size n+2 is used to handle indices comfortably up to dp[n].
        vector<int> prefixDp(n+2, 0);
        
        // Base case for prefix: prefixDp[1] holds the sum up to dp[0] (which is 1).
        prefixDp[1] = 1;
        
        // dqInc (Increasing): Front holds the index of the Minimum element in current window.
        // dqDec (Decreasing): Front holds the index of the Maximum element in current window.
        deque<int> dqInc, dqDec;
        
        // Sliding Window 
        for(int r = 0; r < n; r++){
            
            // 1. Maintain Monotonic Increasing Deque (for Min)
            // Remove elements from the back that are greater than the current element nums[r]
            // because they can never be the minimum as long as nums[r] is in the window.
            while(!dqInc.empty() && nums[dqInc.back()] > nums[r]){
                dqInc.pop_back();
            }
            
            // 2. Maintain Monotonic Decreasing Deque (for Max)
            // Remove elements from the back that are smaller than the current element nums[r]
            // because they can never be the maximum as long as nums[r] is in the window.
            while(!dqDec.empty() && nums[dqDec.back()] < nums[r]){
                dqDec.pop_back();
            }
            
            // Add current index to both deques
            dqInc.push_back(r);
            dqDec.push_back(r);
            
            // 3. Shrink window from the left if Invalid
            // Check if difference between current Max (dqDec.front()) and Min (dqInc.front()) > k
            while(nums[dqDec.front()] - nums[dqInc.front()] > k){
                l++; // Shrink window
                
                // Remove indices from the front of deques if they are now outside the window [l, r]
                while(!dqDec.empty() && dqDec.front() < l) dqDec.pop_front();
                while(!dqInc.empty() && dqInc.front() < l) dqInc.pop_front();
            }
            
            // At this point, any segment ending at 'r' and starting at any index 'start' 
            // where l <= start <= r is valid (max - min <= k).
            
            // If the last segment is nums[start...r], the previous partition must have ended at 'start-1'.
            // Valid 'start' indices are [l, l+1, ..., r].
            // Therefore, valid 'previous partition end' indices are [l-1, l, ..., r-1].
            // We need to sum: dp[l] + dp[l+1] + ... + dp[r].
            
            // Using the prefix sum array:
            // Sum(dp[l]...dp[r]) = prefixDp[r+1] - prefixDp[l].
            long curr = (long long)prefixDp[r+1] - prefixDp[l];
            
            // 4. Handle Modulo Arithmetic
            // Since subtraction can result in a negative value (due to modulo wrapping),
            // we apply (val % mod + mod) % mod to ensure a positive result.
            dp[r+1] = (curr % mod + mod) % mod;
            
            // 5. Update Prefix Sum for the NEXT iteration
            // We just calculated dp[r+1]. Now we update prefixDp[r+2] to include this new value.
            // prefixDp[r+2] = Sum(dp[0]...dp[r+1])
            prefixDp[r+2] = (prefixDp[r+1] + dp[r+1]) % mod;
        }
        
        return dp[n];
    }
};
