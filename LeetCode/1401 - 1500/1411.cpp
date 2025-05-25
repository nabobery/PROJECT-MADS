// 1411. Number of Ways to Paint N × 3 Grid

// Solution 1 Using Dynamic Programming and BFS
// Time Complexity: O(n)
// Space Complexity: O(n)
class Solution {
public:
    const int mod = 1e9 + 7;
    bool isValidTransition(tuple<int, int, int> a, tuple<int, int, int> b) {
        return get<0>(a) != get<0>(b) && get<1>(a) != get<1>(b) &&
               get<2>(a) != get<2>(b);
    }
    int numOfWays(int n) {
        long res = 0;
        // 0 -> red, 1 -> yellow, 2 -> green
        int dp[n][3][3][3];
        memset(dp, 0, sizeof(dp));
        vector<tuple<int, int, int>> validStates;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                for (int k = 0; k < 3; k++) {
                    if (i != j && j != k) {
                        validStates.emplace_back(i, j, k);
                    }
                }
            }
        }
        // base case n = 1
        for (auto& [i, j, k] : validStates)
            dp[0][i][j][k] = 1;
        vector<vector<int>> adj(12);
        for (int i = 0; i < 12; ++i) {
            for (int j = 0; j < 12; ++j) {
                if (i == j)
                    continue;
                if (isValidTransition(validStates[i], validStates[j]))
                    adj[i].push_back(j);
            }
        }
        for (int idx = 1; idx < n; idx++) {
            for (int i = 0; i < 12; i++) {
                auto [ci, cj, ck] = validStates[i];
                for (int j : adj[i]) {
                    auto [ni, nj, nk] = validStates[j];
                    dp[idx][ni][nj][nk] =
                        ((long)dp[idx - 1][ci][cj][ck] + dp[idx][ni][nj][nk]) %
                        mod;
                }
            }
        }
        // calculate res
        for (auto& [i, j, k] : validStates)
            res = (res + dp[n - 1][i][j][k]) % mod;
        return res;
    }
};