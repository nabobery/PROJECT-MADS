// 410. Split Array Largest Sum
// Top Down DP O(n^2m) time and O(nm) space Solution
class Solution {
public:
    // dp table to store the values
    int dp[1001][51];
    int getMinLargestSplitSum(vector<int>& prefixSum, int currIndex, int subarrayCount){
        // get number of elements
        int n = prefixSum.size() - 1;
        // if value already calculated, just return it
        if(dp[currIndex][subarrayCount] != -1){
            return dp[currIndex][subarrayCount];
        }
        // if number of sub arrays left is just 1, just return sum[currIndex,n]
        if(subarrayCount == 1){
            return dp[currIndex][subarrayCount] = prefixSum[n] - prefixSum[currIndex];
        }
        // minimum split sum initialised as integer max
        int result = INT_MAX;
        // split into sub arrays from current index
        for(int i = currIndex;i <= n - subarrayCount;i++){
            // first subarray sum for index i
            int firstSplitSum = prefixSum[i+1] - prefixSum[currIndex];
            // largest sub array sum for this config by getting max of first sub array and other sub array sum
            int largestSplitSum = max(firstSplitSum, getMinLargestSplitSum(prefixSum, i + 1, subarrayCount - 1));
            // get the minimum of all largest split sum
            result = min(result,largestSplitSum);
            // if firstSplitSum > largestSplitSum , we can break as we will be getting larger split sum from now and there's no need of computing anymore
            if(firstSplitSum >= largestSplitSum) break;
        }
        return dp[currIndex][subarrayCount] = result;
    }

    int splitArray(vector<int>& nums, int m) {
        // set everything of dp to -1
        memset(dp, -1,sizeof(dp));
        int n = nums.size();
        vector<int> prefixSum(n+1,0);
        // calculate prefix sum
        for(int i = 0; i < n;i++){
            prefixSum[i+1] = prefixSum[i] + nums[i];
        }
        return getMinLargestSplitSum(prefixSum,0,m);
    }
};

