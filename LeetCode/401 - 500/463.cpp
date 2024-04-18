// 463. Island Perimeter

// Naive Solution 1 by checking each land cell's neighbours and count the perimeter
// Time complexity: O(n^2)
// Space complexity: O(1)
class Solution {
public:
    vector<vector<int>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    int islandPerimeter(vector<vector<int>>& grid) {
        int res = 0, m = grid.size(), n = grid[0].size();
        for(int i = 0; i < m;i++){
            for(int j = 0; j < n;j++){
                if(grid[i][j] == 1){
                    for(auto& d : dirs){
                        int x = i+d[0], y = j + d[1];
                        if(x >= 0 && x < m && y >= 0 && y < n){
                            if(grid[x][y] == 0) res++;
                        }
                        else res++;
                    }
                }
            }
        }
        return res;
    }
};

// Solution 2 using DFS
// Time complexity: O(n^2)
// Space complexity: O(n)
class Solution {
public:
    vector<vector<int>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    int islandPerimeter(vector<vector<int>>& grid) {
        int res = 0, m = grid.size(), n = grid[0].size();
        for(int i = 0; i < m;i++){
            for(int j = 0; j < n;j++){
                if(grid[i][j] == 1){
                    res = dfs(grid, i, j);
                    break;
                }
            }
        }
        return res;
    }
    int dfs(vector<vector<int>>& grid, int i, int j){
        if(i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] == 0) return 1;
        if(grid[i][j] == 2) return 0;
        grid[i][j] = 2;
        int res = 0;
        for(auto& d : dirs){
            res += dfs(grid, i+d[0], j+d[1]);
        }
        return res;
    }
};

// Solution 3 using BFS
// Time complexity: O(n^2)
// Space complexity: O(n)
class Solution {
public:
    vector<vector<int>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    int islandPerimeter(vector<vector<int>>& grid) {
        int res = 0, m = grid.size(), n = grid[0].size();
        for(int i = 0; i < m;i++){
            for(int j = 0; j < n;j++){
                if(grid[i][j] == 1){
                    res = bfs(grid, i, j);
                    break;
                }
            }
        }
        return res;
    }
    int bfs(vector<vector<int>>& grid, int i, int j){
        queue<pair<int, int>> q;
        q.push({i, j});
        grid[i][j] = 2;
        int res = 0;
        while(!q.empty()){
            auto [x, y] = q.front();
            q.pop();
            for(auto& d : dirs){
                int nx = x + d[0], ny = y + d[1];
                if(nx >= 0 && nx < grid.size() && ny >= 0 && ny < grid[0].size()){
                    if(grid[nx][ny] == 0) res++;
                    else if(grid[nx][ny] == 1){
                        q.push({nx, ny});
                        grid[nx][ny] = 2;
                    }
                }
                else res++;
            }
        }
        return res;
    }
};