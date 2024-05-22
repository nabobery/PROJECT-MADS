// 3068. Find the Maximum Sum of Node Values

// The idea to the below Solution is that we can xor any 2 nodes in the graph as all nodes are connected
// and num[u] xor k xor k = num[u] which means we can xor any node with k and then xor it with k again to get the original value

// Solution 1 using DP
// Time Complexity: O(2*n) = O(n)
// Space Complexity: O(2*n) = O(n)

class Solution {
public:
    // dp[i][j] = maximum sum of nodes from i to n-1 with j as the parity whether xor is done at ith node or not
    vector<vector<long long>> dp;
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        // initialize dp with -1
        dp.resize(nums.size(), vector<long long>(2, -1));
        // return the maximum sum of nodes from 0 to n-1 with 1 as the parity which means no xor is done
        return maxSumOfNodes(0, 1, nums, k);
    }
        
    long long maxSumOfNodes(int index, int isEven, vector<int>& nums, int k) {
        // if we have reached the end return 0 if isEven is 1 else return INT_MIN
        if (index == nums.size()) 
            return isEven == 1 ? 0 : INT_MIN;
        // if the value is already calculated return it
        if (dp[index][isEven] != -1) 
            return dp[index][isEven];
        // calculate the maximum sum of nodes from index to n-1 with isEven as the parity
        long long noXorDone = nums[index] + maxSumOfNodes(index + 1, isEven, nums, k);
        // calculate the maximum sum of nodes from index to n-1 with !isEven as the parity
        long long xorDone = (nums[index] ^ k) + maxSumOfNodes(index + 1, isEven ^ 1, nums, k);
        // return the maximum of both
        return dp[index][isEven] = max(xorDone, noXorDone);
    }
};


// Solution 2 using DP (Tabulation)
// Time Complexity: O(n)
// Space Complexity: O(n)

class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        int n = nums.size();
        vector<vector<long long>> dp(n+1, vector<long long>(2, 0));
        dp[n][1] = 0;
        dp[n][0] = INT_MIN;
        for (int i = n-1; i >= 0; i--) {
            for(int isEven = 0; isEven < 2; isEven++) {
                long long noXorDone = nums[i] + dp[i+1][isEven];
                long long xorDone = (nums[i] ^ k) + dp[i+1][isEven ^ 1];
                dp[i][isEven] = max(xorDone, noXorDone);
            }
        }
        return dp[0][1];
    }
};
