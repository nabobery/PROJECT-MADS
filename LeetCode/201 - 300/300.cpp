// 300. Longest Increasing Subsequence

// O(n^2) time and O(n) space Recursive with Memoization solution
class Solution {
public:
    int helper(int i,vector<int>& nums, vector<int>& dp){
        // base case
        if(i == 0) return dp[i] = 1;
        // return if already calculated
        if(dp[i] != -1) return dp[i];
        // initialize dp[i] to 1
        dp[i] = 1;
        // find the longest increasing subsequence ending at i
        for(int j = 0; j < i;j++)
            // if nums[j] < nums[i] then we can add nums[i] to the subsequence ending at nums[j]
            if(nums[j] < nums[i])
                dp[i] = max(dp[i], helper(j,nums, dp) + 1);
            // else we can't add nums[i] to the subsequence ending at nums[j] so we check for the longest subsequence ending at nums[j]
            else dp[j] = helper(j,nums,dp);
        // return the longest subsequence ending at i
        return dp[i];
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,-1);
        // find the longest increasing subsequence ending at each index
        helper(n-1,nums, dp);
        // find the longest increasing subsequence in the array
        int result = 1;
        for(auto i : dp){
            result=max(result,i);
        }
        return result;
    }
};

// O(n^2) time and O(n) space Iterative solution
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,1);
        // find the longest increasing subsequence ending at each index
        for(int i = 1; i < n; i++){
            for(int j = 0; j < i; j++){
                // if nums[j] < nums[i] then we can add nums[i] to the subsequence ending at nums[j]
                if(nums[j] < nums[i])
                    dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        // find the longest increasing subsequence in the array
        int result = 1;
        for(auto i : dp){
            result=max(result,i);
        }
        return result;
    }
};

// O(nlogn) time and O(n) space Iterative solution
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp;
        // find the longest increasing subsequence ending at each index
        for(int i = 0; i < n; i++){
            // find the iterator of the smallest number greater than nums[i]
            auto it = lower_bound(dp.begin(),dp.end(),nums[i]);
            // if the number is not present in the array then add it to the array
            if(it == dp.end()) dp.push_back(nums[i]);
            // else replace the number with nums[i]
            else *it = nums[i];
        }
        // return the length of the array
        return dp.size();
    }
};

