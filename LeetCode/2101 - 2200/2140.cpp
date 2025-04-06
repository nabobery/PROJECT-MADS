// 2140. Solving Questions With Brainpower

// Solution 1: Using Recursion and Memoization 
// Time complexity: O(n)
// Space complexity: O(n)
class Solution {
    public:
        long long helper(vector<vector<int>>& questions, int ind, vector<long long>& dp){
            if(ind >= questions.size())
                return 0;
            if(dp[ind] != -1) return dp[ind];
            dp[ind] = max(helper(questions, ind+1, dp), dp[ind]);
            dp[ind] = max(helper(questions, questions[ind][1] + ind + 1, dp) + questions[ind][0], dp[ind]);
            return dp[ind];
        }
        long long mostPoints(vector<vector<int>>& questions) {
            long long res = 0;
            int n = questions.size();
            vector<long long> dp(n, -1);
            return helper(questions, 0, dp);
        }
};

// Solution 2: Using Dynamic Programming (Iterative)
// Time complexity: O(n)
// Space complexity: O(n)
class Solution {
    public:
        long long mostPoints(vector<vector<int>>& questions) {
            int n = questions.size();
            vector<long long> dp(n+1, 0);  
            for(int i = n-1; i >= 0; i--){
                dp[i] = max(dp[i+1], questions[i][0] + dp[min(n, i + questions[i][1] + 1)]);
            }
            return dp[0];
        }
};

