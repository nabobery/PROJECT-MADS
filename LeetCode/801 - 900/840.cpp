// 840. Magic Squares In Grid

// Solution1: Simulation
// Time complexity: O(n^2)
// Space complexity: O(1)
class Solution {
public:
    bool isMagicSquare(const vector<vector<int>>& matrix, int i, int j) {
        vector<vector<int>> submatrix(3, vector<int>(3));
        for (int row = 0; row < 3; ++row) {
            for (int col = 0; col < 3; ++col) {
                submatrix[row][col] = matrix[i + row][j + col];
            }
        }
        set<int> uniqueNumbers;
        for (const auto& row : submatrix) {
            for (int num : row) {
                if (num < 1 || num > 9 || !uniqueNumbers.insert(num).second) {
                    return false;
                }
            }
        }
        int targetSum = submatrix[0][0] + submatrix[0][1] + submatrix[0][2];
        for (const auto& row : submatrix) {
            if (row[0] + row[1] + row[2] != targetSum) {
                return false;
            }
        }
        for (int col = 0; col < 3; ++col) {
            int colSum = submatrix[0][col] + submatrix[1][col] + submatrix[2][col];
            if (colSum != targetSum) {
                return false;
            }
        }
        int diag1Sum = submatrix[0][0] + submatrix[1][1] + submatrix[2][2];
        int diag2Sum = submatrix[0][2] + submatrix[1][1] + submatrix[2][0];
        if (diag1Sum != targetSum || diag2Sum != targetSum) {
            return false;
        }
        return true;
    }
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int res = 0, m = grid.size(), n = grid[0].size();
        for(int i = 0; i < m-2;i++){
            for(int j = 0; j < n-2;j++){
                if(isMagicSquare(grid, i, j)) res++;
            }
        }
        return res;
    }
};