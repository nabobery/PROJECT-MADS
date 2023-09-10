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
        if(n == 1 || m == 1) return 1;
       vector<vector<int>> dp(m, vector<int>(n, 0));
       for(int i = 0; i < m;i++) dp[i][0] = 1;
       for(int i = 0; i < n;i++) dp[0][i] = 1;
       for(int i = 1; i < m;i++){
           for(int j = 1; j < n;j++){
               dp[i][j] = dp[i-1][j] + dp[i][j-1];
           }
       }
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

// Solution using Combinatorics
// We have m - 1 down and n - 1 right moves to make
// So total moves = m + n - 2
// We have to choose m - 1 moves to go down
// So total ways = (m + n - 2)C(m - 1)
class Solution {
public:
    int uniquePaths(int m, int n) {
        int N = n + m - 2;
        int r = m - 1;
        double res = 1;
        for(int i = 1; i <= r; i++){
            res = res * (N - r + i) / i;
        }
        return (int)res;
    }
};
