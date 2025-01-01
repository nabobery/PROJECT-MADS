// 2466. Count Ways To Build Good Strings

// Solution 1: Using Recursion and Memoization
// Time Complexity: O(high)
// Space Complexity: O(high)
class Solution {
public:
    const int mod = 1e9 + 7;
    int helper(int curr, int& low, int& high, int& zeroes, int& ones,
               vector<int>& dp) {
        if (curr > high)
            return 0;
        if (dp[curr] != -1)
            return dp[curr];
        long res = helper(curr + zeroes, low, high, zeroes, ones, dp) % mod;
        res = (res + helper(curr + ones, low, high, zeroes, ones, dp) % mod) %
                  mod;
        res += (curr >= low && curr <= high);
        return dp[curr] = res % mod;
    }
    int countGoodStrings(int low, int high, int zero, int one) {
        vector<int> dp(high + 1, -1);
        return helper(0, low, high, zero, one, dp);
    }
};

// Solution 2: Using Iterative DP
// Time Complexity: O(high)
// Space Complexity: O(high)
class Solution {
public:
    const int mod = 1e9 + 7;
    int countGoodStrings(int low, int high, int zero, int one) {
        vector<int> dp(high + 1, 0);
        // dp[i] = number of strings of length i
        // base case
        dp[0] = 1;
        // build dp array
        // dp[i] = dp[i - zero] + dp[i - one]
        for (int i = 1; i <= high; i++) {
            if(i >= zero) dp[i] = (dp[i] + dp[i - zero]) % mod;
            if(i >= one) dp[i] = (dp[i] + dp[i - one]) % mod;
        }
        // get all the good strings in the range [low, high]
        int res = 0;
        for (int i = low; i <= high; i++) 
            res = (res + dp[i]) % mod;
        return res;
    }
};