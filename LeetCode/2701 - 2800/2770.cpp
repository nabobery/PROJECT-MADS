// 2770. Maximum Number of Jumps to Reach the Last Index

// Solution 1: Dynamic Programming
// Time Complexity: O(n^2)
// Space Complexity: O(n)
class Solution {
public:
    int maximumJumps(vector<int>& nums, int target) {
        int n = nums.size();
        // dp[i] = the maximum number of jumps to reach index i
        vector<int> dp(n, -1);
        // base case: the maximum number of jumps to reach index 0 is 0
        dp[0] = 0;
        // iterate through the array and update the dp array
        for(int j = 1; j < n;j++){
            // iterate through the previous indices and update the dp array
            for(int i = 0; i < j; i++){
                // if the absolute difference between nums[j] and nums[i] is less than or equal to target and dp[i] is not -1, update dp[j]
                if(abs(nums[j]-nums[i]) <= target && dp[i] != -1){
                    // update dp[j] to be the maximum of its current value and dp[i] + 1
                    // basically we can jump to j from i, so we add 1 to the number of jumps to reach i
                    dp[j] = max(dp[j], dp[i] + 1);
                }
            }
        }
        // return the maximum number of jumps to reach the last index, which is dp[n-1]
        return dp[n-1];
    }
};