// 198. House Robber

// O(n) Time and Space Solution
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        vector<int> dp(n+1,0);
        dp[0] = 0, dp[1] = nums[0];
        for(int i = 2; i <= n;i++){
            dp[i] =  max(dp[i-2] + nums[i-1], dp[i-1]);
        }
        return dp[n];
    }
};

// O(n) Time and O(1) Space Solution
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        int t0 = 0, t1 = nums[0],temp;
        for(int i = 2; i <= n;i++){
            temp  = t1;
            t1 =  max(t0 + nums[i-1], t1);
            t0 = temp;
        }
        return t1;
    }
};