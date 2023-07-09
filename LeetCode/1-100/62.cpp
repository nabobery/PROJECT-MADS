/* 62. Unique Paths

Initial solution : (m + n - 2)C(m - 1)
class Solution {
public:
    int uniquePaths(int m, int n) {
        int result = 1;
        for(int i = n; i < m + n - 1; i++){
            result *= i;
            result /= i - n + 1;
        }
        return result;
    }
};
*/

// O(mn) Time and O(mn) space solution using DP
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n,0));
        // base case
        dp[0][0] = 1;
        for(int i = 0; i < m;i++){
            for(int j = 0; j < n;j++){
                // if we are at the first row or first column, then we can only reach the current cell from the left or top cell
                if(i > 0) dp[i][j] += dp[i-1][j];
                if(j > 0) dp[i][j] += dp[i][j-1];
            }
        }
        // return the number of paths to reach the bottom right cell
        return dp[m-1][n-1];
    }
};

// O(mn) Time and O(n) space solution using DP
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> dp(n, 0);
        dp[0] = 1;
        for(int i = 0; i < m; i++){
            for(int j = 1; j < n; j++){
                dp[j] += dp[j - 1];
            }
        }
        return dp[n - 1];
    }
};
