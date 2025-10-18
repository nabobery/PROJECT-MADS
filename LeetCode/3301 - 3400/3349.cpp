// 3349. Adjacent Increasing Subarrays Detection I

// Solution 1: Simple and Straightforward
// Time Complexity: O(n*k)
// Space Complexity: O(1)
class Solution {
public:
    bool isIncreasing(vector<int>& nums, int start, int k){
        if(start + k > nums.size()) return false;
        for(int i = start+1;i < start+k;i++){
            if(nums[i-1] >= nums[i]) return false;
        }
        return true;
    }
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        for(int i = k ; i <= n-k;i++){
            if(isIncreasing(nums, i-k, k) && isIncreasing(nums, i, k)) return true;
        }
        return false;
    }
};

// Solution 2: Optimized using Incremental Check
// Time Complexity: O(n)
// Space Complexity: O(1)
class Solution {
public:
    bool hasIncreasingSubarrays(std::vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> inc_len(n, 1);
        inc_len[0] = 1;
        // Pre-calculate the lengths of all increasing subarrays.
        for (int i = 1; i < n; ++i) {
            if (nums[i] > nums[i - 1]) {
                inc_len[i] = inc_len[i - 1] + 1;
            }
        }
        // Check for two adjacent k-length increasing subarrays.
        for (int i = 0; i <= n - 2 * k; ++i) {
            bool first_is_increasing = (inc_len[i + k - 1] >= k);
            bool second_is_increasing = (inc_len[i + 2 * k - 1] >= k);

            if (first_is_increasing && second_is_increasing) {
                return true;
            }
        }
        return false;
    }
};
