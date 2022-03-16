// 312. Burst Balloons
//So we maintain a dp matrix where dp[i][j] is coins for balloon burst between ith index and jth index and we iterate from window size of 1 to nums size
class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        vector<vector<int>> dp(nums.size(), vector<int>(nums.size(), 0));
        for (int len = 1; len <= n; ++len)
            for (int left = 1; left <= n - len + 1; ++left) {
                int right = left + len - 1;
                for (int k = left; k <= right; ++k)
                    dp[left][right] = max(dp[left][right], nums[left-1]*nums[k]*nums[right+1] + dp[left][k-1] + dp[k+1][right]);
            }
        return dp[1][n];
    }
};

