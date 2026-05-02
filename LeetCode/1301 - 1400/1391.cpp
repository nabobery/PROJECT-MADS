// 1391. Check if There is a Valid Path in a Grid

// Solution 1: BFS
// Time Complexity: O(m*n)
// Space Complexity: O(m*n)
class Solution {
public:
    bool hasValidPath(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();

        // Directions: up, down, left, right
        vector<pair<int, int>> offsets = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};

        // Street connections based on street type
        vector<vector<int>> streetConnections = {
            {}, // Street type 0 (not used)
            {0, 1}, // Street type 1: left, right
            {2, 3},  // Street type 2: up, down
            {0, 3}, // Street type 3: left, down
            {1, 3}, // Street type 4: right, down
            {0, 2}, // Street type 5: left, up
            {1, 2} // Street type 6: right, up
        };

        // Reverse directions for checking if we can enter the next cell
        // 0: left, 1: right, 2: up, 3: down
        vector<int> reverseDir = {1, 0, 3, 2};

        // Visited array to keep track of visited cells
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        queue<pair<int, int>> q;

        // Start BFS from the top-left corner
        q.push({0, 0});
        visited[0][0] = true;

        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();

            // If we reach the bottom-right corner, return true
            if (r == m - 1 && c == n - 1)
                return true;

            // Get the current street type and its possible directions
            int streetType = grid[r][c];
            // Try to move in all possible directions based on the current street type
            for (int dir : streetConnections[streetType]) {
                int nr = r + offsets[dir].first;
                int nc = c + offsets[dir].second;

                if (nr < 0 || nr >= m || nc < 0 || nc >= n || visited[nr][nc])
                    continue;

                // Check if we can enter the next cell from the current direction
                int nextStreet = grid[nr][nc];
                int neededDir = reverseDir[dir];

                bool canEnter = false;
                // Check if the next street type allows entering from the needed direction
                for (int d : streetConnections[nextStreet]) {
                    // If the next street type has a connection in the needed direction, we can enter
                    if (d == neededDir) {
                        canEnter = true;
                        break;
                    }
                }

                // If we can enter the next cell, mark it as visited and add it to the queue
                if (canEnter) {
                    visited[nr][nc] = true;
                    q.push({nr, nc});
                }
            }
        }
        // If we exhaust the queue without reaching the bottom-right corner, return false
        return false;
    }
};