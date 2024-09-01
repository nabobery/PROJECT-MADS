// 885. Spiral Matrix III

// Solution 1: Simulation
// Time complexity: O(max(R, C)^2)
// Space complexity: O(R*C)
// The idea is to simulate the spiral path by moving in the four directions (right, down, left, up) and increasing the steps after moving in two directions.
// The simulation stops when we have visited all the cells.
class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        vector<vector<int>> result;
        int totalCells = rows * cols;
        int steps = 1; 
        int direction = 0; 
        int directions[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}}; 
        // Add the starting cell
        result.push_back({rStart, cStart});
        while (result.size() < totalCells) {
            // Move in the current direction for the current number of steps
            for (int i = 0; i < 2; ++i) { 
                // Move in the current direction for the current number of steps
                for (int j = 0; j < steps; ++j) {
                    rStart += directions[direction][0];
                    cStart += directions[direction][1];
                    // Add the cell if it is within the grid
                    if (rStart >= 0 && rStart < rows && cStart >= 0 && cStart < cols) {
                        result.push_back({rStart, cStart});
                    }
                }
                // Change the direction after moving in the current direction for the current number of steps
                direction = (direction + 1) % 4; 
            }
            // Increase the number of steps after moving in two directions
            ++steps; 
        }
        return result;
    }
};