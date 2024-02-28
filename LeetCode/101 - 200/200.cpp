// 200. Number of Islands

// Solution 1 using DFS
// Time complexity: O(m*n)
// Space complexity: O(m*n)
class Solution {
public:
    const int dirs[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size(), res = 0;
        for(int i = 0; i < m;i++){
            for(int j = 0; j < n;j++){
                if(grid[i][j] == '1'){
                    dfs(grid, i, j);
                    res++;
                }
            }
        }
        return res;
    }
    void dfs(vector<vector<char>>& grid, int i, int j){
        int m = grid.size(), n = grid[0].size();
        if(i < 0 || i >= m || j < 0 || j >= n || grid[i][j] != '1') return;
        grid[i][j] = '#';
        for(auto dir : dirs){
            int x = i + dir[0], y = j + dir[1];
            dfs(grid,x,y);
        }    
    }
};

// Solution 2 using BFS
// Time complexity: O(m*n)
// Space complexity: O(m*n)
class Solution {
public:
    const int dirs[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size(), res = 0;
        for(int i = 0; i < m;i++){
            for(int j = 0; j < n;j++){
                if(grid[i][j] == '1'){
                    bfs(grid, i, j);
                    res++;
                }
            }
        }
        return res;
    }
    void bfs(vector<vector<char>>& grid, int i, int j){
        int m = grid.size(), n = grid[0].size();
        queue<pair<int,int>> q;
        q.push({i,j});
        grid[i][j] = '#';
        while(!q.empty()){
            auto p = q.front();
            q.pop();
            for(auto dir : dirs){
                int x = p.first + dir[0], y = p.second + dir[1];
                if(x >= 0 && x < m && y >= 0 && y < n && grid[x][y] == '1'){
                    q.push({x,y});
                    grid[x][y] = '#';
                }
            }
        }
    }
};