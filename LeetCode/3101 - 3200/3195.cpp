// 3195. Find the Minimum Area to Cover All Ones I

// Solution 1: Simple and Straight Forward Greedy Approach by finding the bounding box of all 1's
// Time Complexity: O(n * m) where n is the number of rows and m is the number of columns in the grid
// Space Complexity: O(1) since we are using only a constant amount of extra space
class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int minRow = m, minCol = n, maxRow = -1, maxCol = -1;
        auto update = [&](int i, int j) {
            minRow = min(minRow, i);
            maxRow = max(maxRow, i);
            minCol = min(minCol, j);
            maxCol = max(maxCol, j);
        };
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (grid[i][j]) update(i, j);
        return (maxRow - minRow + 1) * (maxCol - minCol + 1);
    }
};
