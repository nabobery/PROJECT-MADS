// 576. Out of Boundary Paths

// Solution 1 using Recursion + Memoization
// Time Complexity: O(m*n*N)
// Space Complexity: O(m*n*N)
class Solution {
public:
    int m,n;
    int dp[51][51][51];
    const int mod = 1e9+7;
    const pair<int,int> dirs[4] = {{0,1}, {0,-1}, {1,0}, {-1,0}};
    bool check(int i, int j){
        return (i < 0 || i >= m || j < 0 || j >= n);
    }
    int helper(int i, int j, int moves){
        if(moves < 0) return 0;
        else if(check(i,j)) return 1;
        if(dp[i][j][moves] != -1) return dp[i][j][moves];
        long long res = 0;
        for(auto& d : dirs){
            res += helper(i+d.first, j+d.second, moves-1);
            res %= mod;
        }
        return dp[i][j][moves] = res;
    }
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        this->m = m;
        this->n = n;
        memset(dp, -1, sizeof(dp));
        return helper(startRow, startColumn, maxMove);
    }
};

// Solution 2 using Bottom Up DP
// Time Complexity: O(m*n*N)
// Space Complexity: O(m*n*N)
class Solution {
public:
    int m,n;
    const int mod = 1e9+7;
    const pair<int,int> dirs[4] = {{0,1}, {0,-1}, {1,0}, {-1,0}};
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        this->m = m;
        this->n = n;
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(maxMove+1, 0)));
        for(int moves = 1; moves <= maxMove; moves++){
            for(int i = 0; i < m; i++){
                for(int j = 0; j < n; j++){
                    for(auto& d : dirs){
                        int x = i + d.first;
                        int y = j + d.second;
                        if(x < 0 || x >= m || y < 0 || y >= n){
                            dp[i][j][moves] += 1;
                        }
                        else{
                            dp[i][j][moves] += dp[x][y][moves-1];
                        }
                        dp[i][j][moves] %= mod;
                    }
                }
            }
        }
        return dp[startRow][startColumn][maxMove];
    }
};

// Solution 3 using Bottom Up DP + Space Optimization
// Time Complexity: O(m*n*N)
// Space Complexity: O(m*n)
class Solution {
public:
    int m,n;
    const int mod = 1e9+7;
    const pair<int,int> dirs[4] = {{0,1}, {0,-1}, {1,0}, {-1,0}};
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        this->m = m;
        this->n = n;
        vector<vector<int>> dp(m, vector<int>(n, 0));
        vector<vector<int>> temp(m, vector<int>(n, 0));
        for(int moves = 1; moves <= maxMove; moves++){
            for(int i = 0; i < m; i++){
                for(int j = 0; j < n; j++){
                    for(auto& d : dirs){
                        int x = i + d.first;
                        int y = j + d.second;
                        if(x < 0 || x >= m || y < 0 || y >= n){
                            temp[i][j] += 1;
                        }
                        else{
                            temp[i][j] += dp[x][y];
                        }
                        temp[i][j] %= mod;
                    }
                }
            }
            dp = temp;
            temp = vector<vector<int>>(m, vector<int>(n, 0));
        }
        return dp[startRow][startColumn];
    }
};