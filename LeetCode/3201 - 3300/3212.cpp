// 3212. Count Submatrices With Equal Frequency of X and Y

// Solution 1: Prefix Sum
// Time Complexity: O(m * n)
// Space Complexity: O(m * n)
class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int res = 0, m = grid.size(), n = grid[0].size();
        // prefixX[i][j] and prefixY[i][j] store the number of 'X' and 'Y' in the submatrix (0, 0, i, j)
        vector<vector<int>> prefixX(m, vector<int>(n, 0)),
            prefixY(m, vector<int>(n, 0));
        // calculate prefixX and prefixY
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                // calculate prefixX[i][j] and prefixY[i][j]
                prefixX[i][j] = grid[i][j] == 'X';
                prefixY[i][j] = grid[i][j] == 'Y';
                // add the number of 'X' and 'Y' in the submatrix (0, 0, i - 1, j) and (0, 0, i, j - 1)
                if (i > 0) {
                    prefixX[i][j] += prefixX[i - 1][j];
                    prefixY[i][j] += prefixY[i - 1][j];
                }
                if (j > 0) {
                    prefixX[i][j] += prefixX[i][j - 1];
                    prefixY[i][j] += prefixY[i][j - 1];
                }
                // subtract the number of 'X' and 'Y' in the submatrix (0, 0, i - 1, j - 1) because it is added twice
                if (i > 0 && j > 0) {
                    prefixX[i][j] -= prefixX[i - 1][j - 1];
                    prefixY[i][j] -= prefixY[i - 1][j - 1];
                }
                // if the number of 'X' and 'Y' in the submatrix (0, 0, i, j) is the same and number of X is greater than 0, then we can form a valid submatrix
                if (prefixX[i][j] > 0 && prefixX[i][j] == prefixY[i][j]) {
                    res++;
                }
            }
        }
        return res;
    }
};