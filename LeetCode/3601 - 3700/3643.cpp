// 3643. Flip Square Submatrix Vertically

// Solution 1: Brute Force
// Time Complexity: O(k^2)
// Space Complexity: O(m*n)
class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        vector<vector<int>> res = grid;
        for(int i = x; i < x+k;i++){
            for(int j = y; j < y+k;j++){
                res[i][j] = grid[2*x+k-i-1][j];
            }
        }
        return res;
    }
};

// Solution 2: In-place using swapping
// Time Complexity: O(k^2/2) = O(k^2)
// Space Complexity: O(1)
class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        for (int i = 0; i < k / 2; ++i) {
            for (int j = 0; j < k; ++j) {
                swap(grid[x + i][y + j], grid[x + k - 1 - i][y + j]);
            }
        }
        return grid;
    }
};