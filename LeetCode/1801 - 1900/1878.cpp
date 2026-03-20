// 1878. Get Biggest Three Rhombus Sums in a Grid

// Solution 1: Brute Force
// Time Complexity: O(m * n * s) where s is the maximum size of the rhombus
// Space Complexity: O(m * n) for storing unique sums
class Solution {
public:
    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        // Use a set to store unique sums
        set<int> uniqueSums;

        // Iterate through each cell as the top vertex of the rhombus
        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                // Add the single cell value as a rhombus of size 0
                uniqueSums.insert(grid[r][c]);
                // Try to form larger rhombuses
                for (int s = 1; ; ++s) {
                    // Check if the rhombus of size s can fit in the grid
                    if (r + 2 * s >= m || c - s < 0 || c + s >= n) break;
                    int currentSum = 0;
                    // Calculate the sum of the rhombus perimeter
                    for (int i = 0; i < s; ++i) {
                        currentSum += grid[r + i][c + s - (s - i)]; // Top to Right
                        currentSum += grid[r + s + i][c + s - i]; // Right to Bottom
                        currentSum += grid[r + 2 * s - i][c - i]; // Bottom to Left
                        currentSum += grid[r + s - i][c - s + i]; // Left to Top
                    }
                    // Add the current sum to the set of unique sums
                    uniqueSums.insert(currentSum);
                }
            }
        }
        vector<int> result;
        auto it = uniqueSums.rbegin();
        // Get the top three unique sums
        for (int i = 0; i < 3 && it != uniqueSums.rend(); ++i, ++it) 
            result.push_back(*it);
        return result;
    }
};