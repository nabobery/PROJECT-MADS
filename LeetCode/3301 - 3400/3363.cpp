// 3363. Find the Maximum Number of Fruits Collected

// Solution 1: Using DFS with Memoization
// Time Complexity: O(n^2)
// Space Complexity: O(n^2)
// The idea is we know that the first child starting from (0, 0) can only go diagonally to reach the end in n-1 moves
// for the second child starting from (0, n - 1), it can go down, or down-right, or down-left
// for the third child starting from (n-1, 0), it can right-up, right or right-down
// so we can use DFS to explore all paths and memoize the results
class Solution {
public:
    int n;

    // DFS for the second child starting from (0, n - 1)
    // It can go down, down-left, or down-right
    int dfsPath1(int row, int col, vector<vector<int>>& grid, vector<vector<int>>& dp) {
        // Base case: if out of bounds
        if (row < 0 || col < 0 || row >= n || col >= n) return 0;
        // If already computed, return the stored result
        if (dp[row][col] != -1) return dp[row][col];
        // Get the current cell value
        int val = grid[row][col];
        int res = 0;
        // Depending on the position, decide the next moves
        // If on the main diagonal, move down-right
        if (row == col) {
            res = dfsPath1(row + 1, col + 1, grid, dp);
        // if the row is one less than the column, move down or down-right
        } else if (row == col - 1) {
            res = max(dfsPath1(row + 1, col, grid, dp), dfsPath1(row + 1, col + 1, grid, dp));
        // else just explore all three directions
        } else {
            res = max({dfsPath1(row + 1, col, grid, dp), dfsPath1(row + 1, col + 1, grid, dp), dfsPath1(row + 1, col - 1, grid, dp)});
        }
        return dp[row][col] = val + res;
    }

    // DFS for the third child starting from (n-1, 0)
    // It can go right, right-up, or right-down
    int dfsPath2(int row, int col, vector<vector<int>>& grid, vector<vector<int>>& dp) {
        // Base case: if out of bounds
        if (row < 0 || col < 0 || row >= n || col >= n) return 0;
        // If already computed, return the stored result
        if (dp[row][col] != -1) return dp[row][col];
        int val = grid[row][col];
        int res = 0;
        // Depending on the position, decide the next moves
        // If on the main diagonal, move down-right
        if (row == col) {
            res = dfsPath2(row + 1, col + 1, grid, dp);
        // if the row is one less than the column, move down or down-right
        } else if (row - 1 == col) {
            res = max(dfsPath2(row, col + 1, grid, dp), dfsPath2(row + 1, col + 1, grid, dp));
        // else just explore all three directions
        } else {
            res = max({dfsPath2(row, col + 1, grid, dp), dfsPath2(row + 1, col + 1, grid, dp), dfsPath2(row - 1, col + 1, grid, dp)});
        }
        return dp[row][col] = val + res;
    }

    int maxCollectedFruits(vector<vector<int>>& grid) {
        n = grid.size();
        int res = 0;
        // Collect fruits from the main diagonal
        // and reset the diagonal cells to 0 to avoid double counting
        for (int i = 0; i < n; i++) {
            res += grid[i][i];
            grid[i][i] = 0;
        }
        // use DFS to explore paths for the two other children
        vector<vector<int>> dp1(n, vector<int>(n, -1));
        // Third child starting from (n-1, 0)
        res += dfsPath2(n - 1, 0, grid, dp1);
        vector<vector<int>> dp2(n, vector<int>(n, -1));
        // Second child starting from (0, n - 1)
        res += dfsPath1(0, n - 1, grid, dp2);
        return res;
    }
};
