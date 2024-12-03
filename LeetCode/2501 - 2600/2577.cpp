// 2577. Minimum Time to Visit a Cell In a Grid

// Solution 1: Using Djikstra Agorithm 
// Time complexity: O(mnlog(mn))
// Space complexity: O(mn)
class Solution {
public:
    int minimumTime(vector<vector<int>>& grid) {
        // if the first cell is blocked or the second cell is blocked, then it is impossible to reach the destination return -1
        if (grid[0][1] > 1 && grid[1][0] > 1) {
            return -1;
        }

        int rows = grid.size(), cols = grid[0].size();
        // directions to move in the grid
        vector<vector<int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        // visited array to keep track of visited cells
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));

        // priority queue to store the cells in the order of time
        priority_queue<vector<int>, vector<vector<int>>, greater<>> pq;
        // push the first cell into the priority queue
        pq.push({grid[0][0], 0, 0});

        // loop until the priority queue is empty or the destination cell is reached
        while (!pq.empty()) {
            auto curr = pq.top();
            pq.pop();
            // extract the time, row and column of the current cell
            int time = curr[0], row = curr[1], col = curr[2];

            // if the destination cell is reached, return the time
            if (row == rows - 1 && col == cols - 1) {
                return time;
            }

            // if the cell is already visited, then skip it
            if (visited[row][col]) {
                continue;
            }
            // mark the cell as visited
            visited[row][col] = true;

            // loop through all the directions
            for (auto& d : directions) {
                // calculate the next row and column
                int nextRow = row + d[0], nextCol = col + d[1];
                // if the next cell is out of bounds, then skip it
                if (!isValid(visited, nextRow, nextCol)) {
                    continue;
                }

                // calculate the time to reach the next cell 
                // time required to reach the next cell is grid value + wait time (based on how you need to go back forth prev and current cell) or current time + 1
                int waitTime =
                    ((grid[nextRow][nextCol] - time) % 2 == 0) ? 1 : 0;
                int nextTime = max(grid[nextRow][nextCol] + waitTime, time + 1);
                pq.push({nextTime, nextRow, nextCol});
            }
        }
        return -1;
    }

private:
    bool isValid(vector<vector<bool>>& visited, int row, int col) {
        return row >= 0 && col >= 0 && row < visited.size() &&
               col < visited[0].size() && !visited[row][col];
    }
};
