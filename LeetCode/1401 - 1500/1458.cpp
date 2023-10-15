// 1458. Max Dot Product of Two Subsequences

// Solution 1 using top-down DP (Recursion + Memoization)
// Time complexity: O(n*m)
// Space complexity: O(n*m)
class Solution {
public:
    vector<vector<int>> dp;
    int helper(vector<int>& nums1, vector<int>& nums2, int i, int j){
        // if we have reached the end of any of the arrays
        if(i == nums1.size() || j == nums2.size()){
            return 0;
        }
        // if we have already calculated the answer
        if(dp[i][j] != INT_MIN) return dp[i][j];
        int res = INT_MIN;
        // we don't include the current element of nums1
        res = max(res, helper(nums1, nums2, i, j+1));
        // we don't include the current element of nums2
        res = max(res, helper(nums1, nums2, i+1, j));
        // we include the current element of nums1 and nums2
        res = max(res, nums1[i]*nums2[j] + helper(nums1, nums2, i+1, j+1));
        return dp[i][j] = res;
    }

    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        // if all elements of nums1 are negative and all elements of nums2 are positive
        if(*max_element(nums1.begin(), nums1.end()) < 0 && *min_element(nums2.begin(), nums2.end())  > 0) return *max_element(nums1.begin(), nums1.end()) * *min_element(nums2.begin(), nums2.end());
        // if all elements of nums1 are positive and all elements of nums2 are negative
        if(*min_element(nums1.begin(), nums1.end()) > 0 && *max_element(nums2.begin(), nums2.end())  < 0) return *min_element(nums1.begin(), nums1.end()) * *max_element(nums2.begin(), nums2.end());
        // initialize dp array
        dp = vector<vector<int>>(501, vector<int>(501, INT_MIN));
        // return the answer
        return helper(nums1, nums2, 0, 0);
    }
};

// Solution 2 using bottom-up DP
// Time complexity: O(n*m)
// Space complexity: O(n*m)
// DP[i][j] as the maximum dot product of two subsequences starting in the position i of nums1 and position j of nums2.
class Solution {
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        // if all elements of nums1 are negative and all elements of nums2 are positive
        if(*max_element(nums1.begin(), nums1.end()) < 0 && *min_element(nums2.begin(), nums2.end())  > 0) return *max_element(nums1.begin(), nums1.end()) * *min_element(nums2.begin(), nums2.end());
        // if all elements of nums1 are positive and all elements of nums2 are negative
        if(*min_element(nums1.begin(), nums1.end()) > 0 && *max_element(nums2.begin(), nums2.end())  < 0) return *min_element(nums1.begin(), nums1.end()) * *max_element(nums2.begin(), nums2.end());
        int n = nums1.size(), m = nums2.size();
        // initialize dp array
        vector<vector<int>> dp(n+1, vector<int>(m+1, INT_MIN));
        for(int i = 0;i <= n;i++){
            for(int j = 0;j <= m;j++){
                // base case
                if(i == 0 || j == 0){
                    dp[i][j] = 0;
                }else{
                    // we don't include the current element of nums1
                    dp[i][j] = max(dp[i][j], dp[i-1][j]);
                    // we don't include the current element of nums2
                    dp[i][j] = max(dp[i][j], dp[i][j-1]);
                    // we include the current element of nums1 and nums2
                    dp[i][j] = max(dp[i][j], nums1[i-1]*nums2[j-1] + dp[i-1][j-1]);
                }
            }
        }
        // return the answer
        return dp[n][m];
    }
};

// Solution 3 using bottom-up DP (Space Optimized)
// Time complexity: O(n*m)
// Space complexity: O(m)
class Solution {
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        // if all elements of nums1 are negative and all elements of nums2 are positive
        if(*max_element(nums1.begin(), nums1.end()) < 0 && *min_element(nums2.begin(), nums2.end())  > 0) return *max_element(nums1.begin(), nums1.end()) * *min_element(nums2.begin(), nums2.end());
        // if all elements of nums1 are positive and all elements of nums2 are negative
        if(*min_element(nums1.begin(), nums1.end()) > 0 && *max_element(nums2.begin(), nums2.end())  < 0) return *min_element(nums1.begin(), nums1.end()) * *max_element(nums2.begin(), nums2.end());
        int n = nums1.size(), m = nums2.size();
        vector<int> dp(m+1, INT_MIN);
        for(int i = 0;i <= n;i++){
            // new row of dp array
            vector<int> new_dp(m+1, INT_MIN);
            for(int j = 0;j <= m;j++){
                // base case
                if(i == 0 || j == 0){
                    new_dp[j] = 0;
                }else{
                    // we don't include the current element of nums1
                    new_dp[j] = max(new_dp[j], dp[j]);
                    // we don't include the current element of nums2
                    new_dp[j] = max(new_dp[j], new_dp[j-1]);
                    // we include the current element of nums1 and nums2
                    new_dp[j] = max(new_dp[j], nums1[i-1]*nums2[j-1] + dp[j-1]);
                }
            }
            dp = new_dp;
        }
        return dp[m];
    }
};
