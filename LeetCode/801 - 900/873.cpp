// 873. Length of Longest Fibonacci Subsequence

// Solution 1 by keeping track of number of fibonacci numbers ending at i and j
// Time Complexity: O(n^2)
// Space Complexity: O(n^2)
class Solution {
    public:
        int lenLongestFibSubseq(vector<int>& arr) {
            int n = arr.size(), res = 0;
            unordered_map<int,int> numToIndex;
            vector<vector<int>> dp(n, vector<int>(n, -1));
            for(int i = 0; i < n;i++) numToIndex[arr[i]] = i;
            for(int i = 1; i < n;i++){
                for(int j = 0; j < i;j++){
                    int pred = arr[i] - arr[j];
                    if(numToIndex.count(pred) && numToIndex[pred] < j){
                        int k = numToIndex[pred];
                        dp[j][i] = dp[k][j] + 1;
                    }
                    else dp[j][i] = 2;
                    res = max(res, dp[j][i]);
                    
                }
            }   
            return res > 2 ? res : 0;
        }
};