// 1914. Cyclically Rotating a Grid

// Solution 1: Layer by Layer Rotation
// Time Complexity: O(m*n) where m and n are the dimensions of the grid
// Space Complexity: O(m+n) for storing the elements of each layer
class Solution {
public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        // The number of layers is determined by the smaller dimension of the grid
        int layers = min(m / 2, n / 2);

        // Rotate each layer of the grid
        for (int layer = 0; layer < layers; ++layer) {
            // Store the elements of the current layer in a temporary vector
            vector<int> elements;

            // Traverse the current layer and store its elements
            // Top row
            for (int j = layer; j < n - layer - 1; ++j)
                elements.push_back(grid[layer][j]);
            // Right column
            for (int i = layer; i < m - layer - 1; ++i)
                elements.push_back(grid[i][n - layer - 1]);
            // Bottom row
            for (int j = n - layer - 1; j > layer; --j)
                elements.push_back(grid[m - layer - 1][j]);
            // Left column
            for (int i = m - layer - 1; i > layer; --i)
                elements.push_back(grid[i][layer]);

            // Calculate the effective rotation by taking the modulus with the total number of elements in the layer
            int total = elements.size();
            int idx = k % total;

            // Place the rotated elements back into the grid
            for (int j = layer; j < n - layer - 1; ++j)
                grid[layer][j] = elements[idx++ % total];
            for (int i = layer; i < m - layer - 1; ++i)
                grid[i][n - layer - 1] = elements[idx++ % total];
            for (int j = n - layer - 1; j > layer; --j)
                grid[m - layer - 1][j] = elements[idx++ % total];
            for (int i = m - layer - 1; i > layer; --i)
                grid[i][layer] = elements[idx++ % total];
        }

        return grid;
    }
};