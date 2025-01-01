// 494. Target Sum

// Solution 1: Recursion
// Time complexity: O(2^n)
// Space complexity: O(n)
class Solution {
public:
    int res = 0;
    void helper(int index, vector<int>& nums, int& target, int sum){
        if(index >= nums.size()){
            if(sum == target) res++;
            return;
        }
        helper(index+1, nums, target, sum + nums[index]);
        helper(index+1, nums, target, sum - nums[index]);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        res = 0;
        helper(0, nums, target, 0);
        return res;
    }
};

// Solution 2: Recursion with memoization
// Time complexity: O(n*sum)
// Space complexity: O(n*sum)
class Solution {
public:
    int memo[21][2001];
    int helper(int index, vector<int>& nums, int target, int sum){
        if(index >= nums.size()){
            if(sum == target) return 1;
            return 0;
        }
        if(memo[index][sum+1000] != -1) return memo[index][sum+1000];
        int add = helper(index+1, nums, target, sum + nums[index]);
        int sub = helper(index+1, nums, target, sum - nums[index]);
        memo[index][sum+1000] = add + sub;
        return memo[index][sum+1000];
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        memset(memo, -1, sizeof(memo));
        return helper(0, nums, target, 0);
    }
};