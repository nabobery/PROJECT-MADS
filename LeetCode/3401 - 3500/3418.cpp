// 3418. Maximum Amount of Money Robot Can Earn

// Solution 1 Using Dynamic Programming
// Time Complexity: O(m*n)
// Space Complexity: O(m*n)
class Solution {
public:
    int maximumAmount(vector<vector<int>>& coins) {
        int m = coins.size(), n = coins[0].size();
        vector<vector<vector<int>>> dp(
            m, vector<vector<int>>(n, vector<int>(3, -1e8)));
        dp[0][0][0] = coins[0][0];
        dp[0][0][1] = max(coins[0][0], 0);
        dp[0][0][2] = max(coins[0][0], 0);
        for (int i = 1; i < m; i++) {
            dp[i][0][0] = dp[i - 1][0][0] + coins[i][0];
            dp[i][0][1] = dp[i - 1][0][1] + coins[i][0];
            dp[i][0][2] = dp[i - 1][0][2] + coins[i][0];
            if (coins[i][0] < 0) {
                dp[i][0][1] = max(dp[i - 1][0][0], dp[i][0][1]);
                dp[i][0][2] = max(dp[i - 1][0][1], dp[i][0][2]);
            }
        }
        for (int j = 1; j < n; j++) {
            dp[0][j][0] = dp[0][j - 1][0] + coins[0][j];
            dp[0][j][1] = dp[0][j - 1][1] + coins[0][j];
            dp[0][j][2] = dp[0][j - 1][2] + coins[0][j];
            if (coins[0][j] < 0) {
                dp[0][j][1] =  max(dp[0][j - 1][0], dp[0][j][1]);
                dp[0][j][2] = max(dp[0][j - 1][1], dp[0][j][2]);
            }
        }
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                dp[i][j][0] =
                    max(dp[i][j - 1][0], dp[i - 1][j][0]) + coins[i][j];
                dp[i][j][1] = max(dp[i][j - 1][1], dp[i - 1][j][1]) + coins[i][j];
                dp[i][j][2] = max(dp[i][j - 1][2], dp[i - 1][j][2]) + coins[i][j];
                if (coins[i][j] < 0) {
                    dp[i][j][1] = max({dp[i][j - 1][0], dp[i - 1][j][0], dp[i][j][1]});
                    dp[i][j][2] = max({dp[i][j - 1][1], dp[i - 1][j][1], dp[i][j][2]});
                }
            }
        }
        return max(
            {dp[m - 1][n - 1][0], dp[m - 1][n - 1][1], dp[m - 1][n - 1][2]});
    }
};

// Solution 2 Using Dynamic Programming with Space Optimization
// Time Complexity: O(m*n)
class Solution {
public:
    int maximumAmount(vector<vector<int>>& coins) {
        int m = coins.size(), n = coins[0].size();
        vector<vector<int>> prev(n, vector<int>(3, -1e9));

        prev[0][0] = coins[0][0];
        prev[0][1] = max(0, coins[0][0]);
        prev[0][2] = max(0, coins[0][0]);

        for (int j = 1; j < n; j++) {
            prev[j][0] = prev[j - 1][0] + coins[0][j];
            prev[j][1] = max(prev[j - 1][1] + coins[0][j],
                             prev[j - 1][0] + max(0, coins[0][j]));
            if (coins[0][j] < 0)
                prev[j][1] = max(prev[j][1], prev[j - 1][0]);

            prev[j][2] = max(prev[j - 1][2] + coins[0][j],
                             prev[j - 1][1] + max(0, coins[0][j]));
            if (coins[0][j] < 0)
                prev[j][2] = max(prev[j][2], prev[j - 1][1]);
        }

        for (int i = 1; i < m; i++) {
            vector<vector<int>> curr(n, vector<int>(3, -1e9));

            curr[0][0] = prev[0][0] + coins[i][0];
            curr[0][1] = max(prev[0][1] + coins[i][0], prev[0][0]);
            curr[0][2] = max(prev[0][2] + coins[i][0], prev[0][1]);

            for (int j = 1; j < n; j++) {
                int c = coins[i][j];

                curr[j][0] = max(prev[j][0], curr[j - 1][0]) + c;

                curr[j][1] = max(prev[j][1], curr[j - 1][1]) + c;
                if (c < 0)
                    curr[j][1] = max({curr[j][1], prev[j][0], curr[j - 1][0]});

                curr[j][2] = max(prev[j][2], curr[j - 1][2]) + c;
                if (c < 0)
                    curr[j][2] = max({curr[j][2], prev[j][1], curr[j - 1][1]});
            }
            prev = move(curr);
        }

        return max({prev[n - 1][0], prev[n - 1][1], prev[n - 1][2]});
    }
};