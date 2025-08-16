// 808. Soup Servings

//Solution 1: Observations, Math and Dynamic Programming
// Time Complexity: O(n^2)
// Space Complexity: O(n^2)
class Solution {
public:
    double helper(int a, int b, vector<vector<double>>& dp){
        // base case
        if(a == 0 && b > 0) return dp[a][b] = 1;
        else if(b == 0 && a > 0) return dp[a][b] = 0;
        else if(a == 0 && b == 0) return dp[a][b] = 0.5;
        // if memozied, return it
        if(dp[a][b] != -1) return dp[a][b];
        double res = 0;
        // try out all 4 operations
        for(int i = 0; i < 4;i++){
            int na = max(a - (100 - 25*i), 0), nb = max(b - (25*i), 0);
            res += (0.25 * helper(na, nb, dp));
        }
        // store and return the result
        return dp[a][b] = res;
    }
    double soupServings(int n) {
        // After n > 4875, the result rounds off to 1 (as the difference is less than 1e-5)
        if(n >= 4875) return 1;
        vector<vector<double>> dp(n+1, vector<double>(n+1, -1));
        return helper(n, n, dp);
    }
};