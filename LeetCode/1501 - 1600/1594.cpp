// 1594. Maximum Non Negative Product in a Matrix

// Solution 1: Brute Force
// Time Complexity: O(2^(m+n))
// Space Complexity: O(m+n)
class Solution {
public:
    long long res;
    int m,n;
    const int mod = 1e9+7;
    void helper(int i, int j, vector<vector<int>>& grid, long long curr){
        if(i == m-1 && j == n-1){
            if(curr >= 0) res = max(res, curr);
            return;
        }
        if(i < m-1) helper(i+1, j, grid, curr*grid[i+1][j]);
        if(j < n-1) helper(i, j+1, grid, curr*grid[i][j+1]);
    }
    int maxProductPath(vector<vector<int>>& grid) {
        res = LLONG_MIN;
        m = grid.size();
        n = grid[0].size();
        helper(0, 0, grid, (long long)grid[0][0]);
        return res == LLONG_MIN ? -1 : res%mod;
    }
};

// Solution 2: Dynamic Programming
// Time Complexity: O(m*n)
// Space Complexity: O(m*n)
class Solution {
public:
    const int mod = 1e9 + 7;
    int maxProductPath(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        long long max_dp[m][n], min_dp[m][n];
        max_dp[0][0] = min_dp[0][0] = grid[0][0];

        for (int i = 1; i < m; i++) {
            max_dp[i][0] = min_dp[i][0] = max_dp[i - 1][0] * grid[i][0];
        }
        for (int j = 1; j < n; j++) {
            max_dp[0][j] = min_dp[0][j] = max_dp[0][j - 1] * grid[0][j];
        }

        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                long long v1 = max_dp[i - 1][j] * grid[i][j];
                long long v2 = min_dp[i - 1][j] * grid[i][j];
                long long v3 = max_dp[i][j - 1] * grid[i][j];
                long long v4 = min_dp[i][j - 1] * grid[i][j];

                max_dp[i][j] = max({v1, v2, v3, v4});
                min_dp[i][j] = min({v1, v2, v3, v4});
            }
        }
        long long res = max_dp[m - 1][n - 1];
        return res < 0 ? -1 : res % mod;
    }
};