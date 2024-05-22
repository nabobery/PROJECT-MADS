// 2812. Find the Safest Path in a Grid

// The safeness factor of a path is defined as the minimum Manhattan distance from any cell in the path to any thief in the grid
// We need to find the maximum safeness factor of all paths from the top-left cell to the bottom-right cell

// Solution 1 Greedy Aproach using BFS and Djikstra's Algorithm

// Time Complexity: O(n^2 logn)
// Space Complexity: O(n^2)
class Solution {
public:
    const int dirs[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();
        // d[i][j] stores the minimum manhattan distance of the nearest thief cell from cell (i, j)
        vector<vector<int>> d(n, vector<int>(n, -1));
        // multi source bfs from all thief cells
        queue<pair<int,int>> q;
        for(int i = 0; i < n;i++){
            for(int j = 0; j < n;j++) 
                if(grid[i][j]){
                    d[i][j] = 0;
                    q.push({i, j});
                }
        }
        // use bfs to find the safeness factor of all cells
        while(!q.empty()){
            int s = q.size();
            for(int i = 0; i < s;i++){
                auto curr = q.front();
                q.pop();
                for(auto& dir : dirs){
                    int x = curr.first + dir[0], y = curr.second + dir[1];
                    if(x >= 0 && y >= 0 && x < n && y < n && d[x][y] == -1){
                        d[x][y] = d[curr.first][curr.second] +1;
                        q.push({x,y});

                    }
                }
            }
        }
        // use priority queue to find the maximum safeness factors of cells in the path
        priority_queue<vector<int>> pq;
        // push the starting cell into the priority queue
        // each element in the priority queue is a vector of 3 elements [max safeness till now, x, y]
        pq.push(vector<int>{d[0][0], 0, 0});
        // mark the starting cell as visited
        d[0][0] = -1;
        // modified Djikstra's algorithm to find the maximum safeness factor of the optimal path
        while (!pq.empty()) {
            // get the cell with the maximum manhattan distance of the nearest thief cell
            auto curr = pq.top();
            pq.pop();
            // if we reach the destination cell, return the maximum manhattan distance of the nearest thief cell
            if (curr[1] == n - 1 && curr[2] == n - 1) 
                return curr[0];
            // push the neighbors of the current cell into the priority queue
            for (auto& dir : dirs) {
                int x = dir[0] + curr[1], y = dir[1] + curr[2];
                if (x >= 0 && y >= 0 && x < n && y < n && d[x][y] != -1) {
                    // push the cell with the min(parent cell distance, current cell distance) into the priority queue
                    // because safeness factor is the minimum manhattan distance of the nearest thief cell from any cell in the path
                    pq.push(vector<int>{min(curr[0], d[x][y]), x, y});
                    d[x][y] = -1;
                }
            }
        }
        return -1;
    }
};

// Solution 2 using BFS + Binary Search
// Time Complexity: O(n^2 logn)
// Space Complexity: O(n^2)
// The idea is to find safeness factor of all cells
// Then use binary search to find the maximum safeness factor of the optimal path

class Solution {
public:
    const int dirs[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();
        queue<pair<int,int>> q;
        for(int i = 0; i < n;i++){
            for(int j = 0; j < n;j++){
                if(grid[i][j]){
                    q.push({i, j});
                    grid[i][j] = 0;
                }
                else grid[i][j] = -1;
            }
        }
        while(!q.empty()){
            int s = q.size();
            for(int i = 0; i < s;i++){
                auto curr = q.front();
                q.pop();
                for(auto& dir : dirs){
                    int x = curr.first + dir[0], y = curr.second + dir[1];
                    if(x >= 0 && y >= 0 && x < n && y < n && grid[x][y] == -1){
                        grid[x][y] = grid[curr.first][curr.second] +1;
                        q.push({x,y});
                    }
                }
            }
        }
        int l = 0, r = 0;
        for(int i = 0; i < n;i++){
            for(int j = 0; j < n;j++) 
                r = max(r, grid[i][j]);
        }
        while(l <= r){
            int m = l + (r - l) / 2;
            if(canReach(grid, m)) l = m + 1;
            else r = m-1;
        }
        return l - 1;
    }

    bool canReach(vector<vector<int>>& grid, int m){
        int n = grid.size();
        if(grid[0][0] < m || grid[n - 1][n - 1] < m) return false;
        queue<pair<int,int>> q;
        q.push({0, 0});
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        visited[0][0] = true;
        while(!q.empty()){
            auto curr = q.front();
            q.pop();
            if(curr.first == n - 1 && curr.second == n - 1) return true;
            for(auto& dir : dirs){
                int x = curr.first + dir[0], y = curr.second + dir[1];
                if(x >= 0 && y >= 0 && x < n && y < n && !visited[x][y] && grid[x][y] >= m){
                    visited[x][y] = true;
                    q.push({x, y});
                }
            }
        }
        return false;
    }
};

