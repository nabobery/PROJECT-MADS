// 2684. Maximum Number of Moves in a Grid

// Solution 1 Bruteforce 
// Time complexity: O(3^n)
// Space complexity: O(1)
class Solution {
public:
    int res, n, m;
    int directions[3][2] = {
        {-1, 1}, // (row - 1, col + 1)
        {0, 1},  // (row, col + 1)
        {1, 1}   // (row + 1, col + 1)
    };
    void helper(vector<vector<int>>& grid, int i, int j, int moves){
        if(i < 0 || i > m || j < 0 || j > n) return;
        res = max(res, moves);
        for(auto dir: directions){
            int nx = i + dir[0], ny = j + dir[1];
            if(nx >= 0 && nx < m && ny >= 0 && ny < n){
                if(grid[nx][ny] > grid[i][j]) helper(grid, nx, ny, moves+1);
            }
        }
    }
    int maxMoves(vector<vector<int>>& grid) {
        m = grid.size(); n = grid[0].size();
        res = 0;
        for(int i = 0; i < m;i++) helper(grid, i, 0, 0);
        return res;
    }
};

// Solution 2 Dynamic Programming
// Time complexity: O(n*m)
// Space complexity: O(n*m)
class Solution {
public:
    int n, m;
    int directions[3][2] = {
        {-1, 1}, // (row - 1, col + 1)
        {0, 1},  // (row, col + 1)
        {1, 1}   // (row + 1, col + 1)
    };
    vector<vector<int>> dp;
    int helper(vector<vector<int>>& grid, int i, int j){
        if(i < 0 || i > m || j < 0 || j > n) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int res = 0;
        for(auto dir: directions){
            int nx = i + dir[0], ny = j + dir[1];
            if(nx >= 0 && nx < m && ny >= 0 && ny < n){
                if(grid[nx][ny] > grid[i][j]){
                    res = max(res, helper(grid, nx, ny) + 1);
                }
            }
        }
        return dp[i][j] = res;
    }
    int maxMoves(vector<vector<int>>& grid) {
        m = grid.size(); n = grid[0].size();
        int res = 0;
        dp.resize(m, vector<int>(n, -1));
        for(int i = 0; i < m;i++) res = max(res, helper(grid, i, 0));
        return res;
    }
};