// 377. Combination Sum IV

// O(n*target) time and O(target) space Top Down DP Solution (recursion + memoization)
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<unsigned int> dp(target+1, -1);
        // base case
        dp[0] = 1;
        return helper(nums, target, dp);
    }
    
    int helper(vector<int>& nums, int target, vector<unsigned int>& dp){
        // if already calculated return the result
        if(dp[target] != -1) return dp[target];
        // else calculate the result
        int res = 0;
        for(int num : nums){
            // if target is greater than or equal to num then add the result of target-num to the result
            if(target >= num) res += helper(nums, target-num, dp);
        }
        // store the result in dp and return
        dp[target] = res;
        return res;
    }
};

// O(n*target) time and O(target) space bottom up DP Solution
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        // dp array to store the result of subproblems dp[i] = number of ways to get sum i
        vector<unsigned int> dp(target+1, 0);
        // base case
        dp[0] = 1;
        // for each sum from 1 to target
        for(int i = 1; i <= target;i++){
            // for each number in nums 
            for(int num : nums){
                // if sum is greater than or equal to num then add the result of sum-num to the result
                if(i >= num) dp[i] += dp[i-num];
            }
        }
        // return the result for target
        return dp[target];
    }
};

// O(n*target) time and O(target) space bottom up DP Solution (Optimized)
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<unsigned int> dp(target+1, 0);
        dp[0] = 1;
        for(int i = 1; i <= target;i++){
            for(int num : nums){
                if(i >= num) dp[i] += dp[i-num];
                else break;
            }
        }
        return dp[target];
    }
};