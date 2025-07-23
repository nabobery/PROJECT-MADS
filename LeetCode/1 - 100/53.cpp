// 53. Maximum Subarray

// O(n) time and space DP solution (Recursive)
class Solution {
public:
    int helper(vector<int>& nums, int i, bool take, vector<vector<int>>& dp){
        if(i >= nums.size()) return take ? 0 : -1e4;
        if(dp[take][i] != -1) return dp[take][i];
        if(take) return dp[take][i] = max(0,nums[i] + helper(nums, i+1, true, dp));
        return dp[take][i] = max(helper(nums,i+1,false,dp), nums[i] + helper(nums,i+1,true,dp));
    }

    int maxSubArray(vector<int>& nums) {
        vector<vector<int>> dp(2, vector<int>(nums.size(), -1));
        return helper(nums, 0, false, dp);
    }
};

// O(n) time and space DP solution (Iterative)
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n);
        int result = nums[0];
        dp[0] = result;
        for(int i = 1; i < n;i++){
            dp[i] = max(nums[i] + dp[i-1], nums[i]);
            result = max(dp[i], result);
        }
        return result;
    }    
};

// O(n) time greedy solution using Kadane's Algo
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int result = INT_MIN, curr = 0;
        for(auto num : nums){
            curr += num;
            if(curr > result) result = curr;
            if(curr < 0) curr = 0;
        }
        return result;
    }
};



