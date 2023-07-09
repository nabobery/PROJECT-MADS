// 45. Jump Game II

// Recursive DP solution O(n^2) time complexity and O(n) space complexity
class Solution {
public:
    int helper(vector<int>& nums, vector<int>& dp, int curr){
        // if we have reached the end, we don't need to make any more jumps
        if(curr >= nums.size()-1) return 0;
        // if we have already calculated the minimum number of jumps to reach the end from this index, we return it
        if(dp[curr] != 10001) return dp[curr];
        // we try all the possible jumps from this index and return the minimum number of jumps to reach the end
        for(int i = 1; i <= nums[curr];i++){
            dp[curr] = min(dp[curr], 1 + helper(nums, dp, curr + i));
        }
        // we return the minimum number of jumps to reach the end from this index
        return dp[curr];
    }

    int jump(vector<int>& nums) {
        vector<int> dp(nums.size(), 10001);
        return helper(nums,dp,0);
    }
};

// Iterative DP solution O(n^2) time complexity and O(n) space complexity
class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 10001);
        // we start from the end and try to reach the end from each index
        dp[n-1] = 0;
        for(int i = n-2; i >= 0;i--){
            for(int j = 1; j <= nums[i];j++)
            // we try all the possible jumps from this index and return the minimum number of jumps to reach the end
                dp[i] = min(dp[i], 1 + dp[min(n-1, i + j)]);
        }
        return dp[0];
    }
};

// Greedy BFS O(n) time solution
class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size(), result = 0, end = 0, far = 0;
        for(int i = 0; i < n-1;i++){
            // seeing what is the farthest we can go 
            far = max(far, i + nums[i]);
            // if we have reached the end of the current jump, we need to make another jump
            if(i == end){
                result++;
                end = far;
            }
        }
        return result;
    }
};



