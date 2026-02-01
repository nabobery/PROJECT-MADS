// 1895. Largest Magic Square

// Solution 1: Prefix Sums and Checking All possible Squares
// Time Complexity: O(min(m, n) * m * n)
// Space Complexity: O(m * n)
class Solution {
public:
    int largestMagicSquare(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        // 1. Precompute Prefix Sums
        vector<vector<int>> rowSum(m, vector<int>(n + 1, 0));
        vector<vector<int>> colSum(n, vector<int>(m + 1, 0));
        vector<vector<int>> diagSum(m + 1, vector<int>(n + 1, 0));
        vector<vector<int>> antiDiagSum(m + 1, vector<int>(n + 1, 0));

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                rowSum[i][j + 1] = rowSum[i][j] + grid[i][j];
                colSum[j][i + 1] = colSum[j][i] + grid[i][j];
                diagSum[i + 1][j + 1] = diagSum[i][j] + grid[i][j];
                antiDiagSum[i + 1][j] = antiDiagSum[i][j + 1] + grid[i][j];
            }
        }

        // 2. Iterate from largest possible side k down to 2
        for (int k = min(m, n); k > 1; --k) {
            for (int i = 0; i <= m - k; ++i) {
                for (int j = 0; j <= n - k; ++j) {
                    if (isMagic(grid, i, j, k, rowSum, colSum, diagSum, antiDiagSum)) {
                        return k;
                    }
                }
            }
        }

        return 1; // Default case for any 1x1 square
    }

private:
    bool isMagic(const vector<vector<int>>& grid, int r, int c, int k,
                 const vector<vector<int>>& rowSum, const vector<vector<int>>& colSum,
                 const vector<vector<int>>& diagSum, const vector<vector<int>>& antiDiagSum) {
        
        // Target sum is the sum of the first row of this sub-square
        int target = rowSum[r][c + k] - rowSum[r][c];

        // Check Rows
        for (int i = r + 1; i < r + k; ++i) {
            if (rowSum[i][c + k] - rowSum[i][c] != target) return false;
        }

        // Check Columns
        for (int j = c; j < c + k; ++j) {
            if (colSum[j][r + k] - colSum[j][r] != target) return false;
        }

        // Check Main Diagonal: (r, c) to (r+k-1, c+k-1)
        if (diagSum[r + k][c + k] - diagSum[r][c] != target) return false;

        // Check Anti-Diagonal: (r, c+k-1) to (r+k-1, c)
        if (antiDiagSum[r + k][c] - antiDiagSum[r][c + k] != target) return false;

        return true;
    }
};