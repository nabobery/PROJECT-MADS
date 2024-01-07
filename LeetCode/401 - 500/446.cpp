// 446. Arithmetic Slices II - Subsequence

// Solution 1 using DP
// Time complexity: O(n^2)
// Space complexity: O(n^2)
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size(), result = 0;
        // dp[i][j] stores the number of arithmetic subsequences ending at i with difference j
        vector<unordered_map<int,int>> dp(n);
        // go through all i and j < i
        for(int i = 0; i < n;i++){
            for(int j = 0; j < i;j++){
                // calculate the difference
                long diff = (long)nums[i] - nums[j];
                // if the difference is out of range, skip
                if(diff <= INT_MIN || diff >= INT_MAX) continue;
                // find the number of arithmetic subsequences ending at j with difference diff and see if it can be included in the subsequences ending at i with difference diff
                int s1 = dp[i][diff], s2 = dp[j][diff];
                // update the result and dp[i][diff]
                dp[i][diff] = s1+s2+1;
                result += s2;
            }
        }
        return result;
    }
};