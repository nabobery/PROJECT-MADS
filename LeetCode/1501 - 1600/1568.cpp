// 1568. Minimum Number of Days to Disconnect Island

// Solution 1 using DFS
// Time complexity: O(n^2)
// Space complexity: O(n^2)
// The idea is to check if the given grid has more than one island or not. If there is only one island, then the answer is 0. If there are more than one island, then we need to check if we can disconnect any one island and make the grid have only one island. If we can disconnect any one island, then the answer is 1. If we can't disconnect any one island, then the answer is 2.
// To check if we can disconnect any one island, we can iterate over all the lands and try to disconnect each land and check if the grid has only one island or not. If the grid has only one island, then we can disconnect that land and the answer is 1. If we can't disconnect any land, then the answer is 2.
// We require 2 lands at max to disconect because by removing 2 lands we can isolate the island and make it disconnected
class Solution {
public:
    void dfs(vector<vector<int>>& grid, vector<vector<bool>>& visited, int x, int y) {
        int directions[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        visited[x][y] = true;
        for (const auto& dir : directions) {
            int newX = x + dir[0], newY = y + dir[1];
            if (newX >= 0 && newX < grid.size() && newY >= 0 && newY < grid[0].size() &&
                grid[newX][newY] == 1 && !visited[newX][newY]) {
                dfs(grid, visited, newX, newY);
            }
        }
    }
    bool isDisconnectedIsland(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        bool foundLand = false;
        bool disconnected = false;
        
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (grid[i][j] == 1 && !visited[i][j]) {
                    if (foundLand) {
                        disconnected = true;
                        break;
                    }
                    dfs(grid, visited, i, j);
                    foundLand = true;
                }
            }
            if (disconnected) {
                break;
            }
        }
        if(!foundLand) return true;
        return disconnected;
    }
    int minDays(vector<vector<int>>& grid) {
        if(isDisconnectedIsland(grid)) return 0;
        vector<pair<int,int>> lands;
        for(int i = 0; i < grid.size();i++)
            for(int j = 0; j < grid[0].size();j++)
                if(grid[i][j]) lands.push_back({i,j});
        for(auto land : lands){
            grid[land.first][land.second] = 0;
            if(isDisconnectedIsland(grid)) return 1;
            grid[land.first][land.second] = 1;
        }
        return 2;
    }
};

// Solution 2 using BFS
// Time complexity: O(n^2)
// Space complexity: O(n^2)
class Solution {
public:
    bool isDisconnectedIsland(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        bool foundLand = false;
        bool disconnected = false;
        
        queue<pair<int,int>> q;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (grid[i][j] == 1 && !visited[i][j]) {
                    if (foundLand) {
                        disconnected = true;
                        break;
                    }
                    q.push({i,j});
                    visited[i][j] = true;
                    while(!q.empty()){
                        auto [x,y] = q.front();
                        q.pop();
                        int directions[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
                        for (const auto& dir : directions) {
                            int newX = x + dir[0], newY = y + dir[1];
                            if (newX >= 0 && newX < grid.size() && newY >= 0 && newY < grid[0].size() &&
                                grid[newX][newY] == 1 && !visited[newX][newY]) {
                                q.push({newX,newY});
                                visited[newX][newY] = true;
                            }
                        }
                    }
                    foundLand = true;
                }
            }
            if (disconnected) {
                break;
            }
        }
        if(!foundLand) return true;
        return disconnected;
    }
    int minDays(vector<vector<int>>& grid) {
        if(isDisconnectedIsland(grid)) return 0;
        vector<pair<int,int>> lands;
        for(int i = 0; i < grid.size();i++)
            for(int j = 0; j < grid[0].size();j++)
                if(grid[i][j]) lands.push_back({i,j});
        for(auto land : lands){
            grid[land.first][land.second] = 0;
            if(isDisconnectedIsland(grid)) return 1;
            grid[land.first][land.second] = 1;
        }
        return 2;
    }
};


