// 1463. Cherry Pickup II

// Solution 1 using DP (maintaining a 3D array to store the maximum number of cherries that can be picked up from the grid)
// Time complexity: O(m*n^2)
// Space complexity: O(m*n^2)
class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(), res = 0;
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(n, -1)));
        dp[0][0][n-1] = grid[0][0] + grid[0][n-1];
        for(int i = 1; i < m;i++){
            for(int j = 0; j < n;j++){
                for(int k = 0; k < n;k++){
                    if(dp[i-1][j][k] != -1){
                        for(int p = -1; p <= 1;p++){
                            for(int q = -1; q <= 1;q++){
                                if(p+j >= 0 && p+j < n && q+k >= 0 && q+k < n){
                                    int curr = 0;
                                    if(p+j != k+q) curr = grid[i][p+j] + grid[i][q+k];
                                    else curr = grid[i][p+j];
                                    dp[i][p+j][k+q] = max(dp[i][p+j][k+q], curr + dp[i-1][j][k]);
                                }
                            }
                        }
                    }
                }
            }
        }
        for(int j = 0; j < n;j++){
            for(int k = 0; k < n;k++) res = max(res, dp[m-1][j][k]);
        }
        return res;
    }
};

