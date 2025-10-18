// 3350. Adjacent Increasing Subarrays Detection II

// Solution 1: Straightforward Simulation Approach with HashMap
// Time Complexity: O(n)
// Space Complexity: O(n)
class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        int n = nums.size(), res = 1;
        // map to store the length of increasing subarray ending at each index
        vector<int> inc_len(n, 1);
        for (int i = 1; i < n; ++i) {
            if (nums[i] > nums[i - 1]) {
                inc_len[i] = inc_len[i-1] + 1;
                // update result if we broke the longest length found so far into two parts
                res = max(res, inc_len[i]/2);
                // check if we can form a longer pair based on previous lengths
                if(i >= inc_len[i] && inc_len[i-inc_len[i]] >= inc_len[i]) res = max(res, inc_len[i]);
            }
        }
        return res;
    }
};

// Solution 2: Optimized Simulation Approach without Extra Space
// Time Complexity: O(n)
// Space Complexity: O(1)
class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        int n = nums.size(), max_k = 0;
        int current_len = 1; // Length of the current increasing subarray
        int prev_len = 0;    // Length of the previous maximal increasing subarray

        for (int i = 1; i < n; ++i) {
            if (nums[i] > nums[i - 1]) {
                current_len++;
            } else {
                // The increasing sequence broke. Check for a "join".
                // The just-ended subarray (length current_len) and the one
                // before it (length prev_len) are adjacent.
                max_k = max(max_k, min(prev_len, current_len));
                
                // Update lengths for the next part of the array.
                prev_len = current_len;
                current_len = 1;
            }
            
            // At every step, check for the "split" case within the current subarray.
            max_k = max(max_k, current_len / 2);
        }
        
        // Final check after the loop for the last sequence in the array.
        max_k = max(max_k, min(prev_len, current_len));

        return max_k;
    }
};