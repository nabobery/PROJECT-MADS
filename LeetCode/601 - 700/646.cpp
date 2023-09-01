// 646. Maximum Length of Pair Chain

// Solution 1 greedy using sort
// Time complexity: O(nlogn)
// Space complexity: O(1)
class Solution {
public:
    static bool compare(vector<int>& a, vector<int>& b){
        if(a[1] != b[1]) return a[1] < b[1];
        return a[0] < b[0];
    }
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end(), compare);
        int result = 1, p = 0;
        for(int i = 1; i < pairs.size();i++){
            if(pairs[i][0] > pairs[p][1]){
                p = i;
                result++;
            }
            else continue;
        }
        return result;
    }
};

// Solution 2 using iterative dp
// Time complexity: O(n^2)
// Space complexity: O(n)
class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        // sort by first element
        sort(pairs.begin(), pairs.end());
        // dp[i] means the longest chain ends with pairs[i], we initialize it to 1
        vector<int> dp(pairs.size(), 1);
        // we initialize result to 1 because there's at least one pair in the chain
        int result = 1;
        // we start from the second pair in pairs and compare it with the previous pairs to find the longest chain
        for(int i = 1; i < pairs.size(); i++){
            for(int j = 0; j < i; j++){
                // if the first element of pairs[i] is greater than the second element of pairs[j]
                if(pairs[i][0] > pairs[j][1]){
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            // update result
            result = max(result, dp[i]);
        }
        return result;
    }
};