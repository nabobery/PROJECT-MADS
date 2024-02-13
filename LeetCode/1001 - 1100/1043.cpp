// 1043. Partition Array for Maximum Sum

// Solution 1 Top Down DP
// Time complexity: O(n*k)
// Space complexity: O(n)
// dp[i] indicates the maximum sum we can get from arr[i] to arr[n-1] if we partition the array starting from index i
class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n, -1);
        return helper(arr, k, 0, dp);
    }
    
    int helper(vector<int>& arr, int k, int i, vector<int>& dp){
        if(i == arr.size()) return 0;
        if(dp[i] != -1) return dp[i];
        int res = 0, maxVal = 0;
        for(int j = 1; j <= k && i+j <= arr.size();j++){
            maxVal = max(maxVal, arr[i+j-1]);
            // get max of the current partition and the maximum sum we can get from the rest of the array by partitioning it
            res = max(res, maxVal*j + helper(arr, k, i+j, dp));
        }
        return dp[i] = res;
    }
};

// Solution 2 Bottom Up DP
// Time complexity: O(n*k)
// Space complexity: O(n)
class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        int dp[n+1];
        memset(dp, 0, sizeof(dp));
        for(int i = n-1; i >= 0;i--){
            // cm is the maximum value in the current partition
            // end is the end index of the current partition
            int cm = 0, end = min(n, i+k);
            for(int j = i; j < end;j++){
                // update cm to the maximum value in the current partition
                cm = max(cm, arr[j]);
                // update dp[i] to the maximum sum we can get from arr[i] to arr[n-1] if we partition the array starting from index i
                dp[i] = max(dp[i], dp[j+1] + cm*(j-i+1));
            }
        }
        return dp[0];
    }
};