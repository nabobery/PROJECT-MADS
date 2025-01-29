// 2658. Maximum Number of Fish in a Grid

// Solution 1 using BFS, getting the maximum number of fish in each connected component
// Time Complexity: O(n * m)
// Space Complexity: O(n * m)
class Solution {
public:
    int findMaxFish(vector<vector<int>>& grid) {
        int res = 0, m = grid.size(), n = grid[0].size();
        vector<vector<int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        queue<pair<int, int>> q;
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] != 0 && !visited[i][j]) {
                    int curr_res = 0;
                    q.push({i, j});
                    visited[i][j] = true;
                    
                    while(!q.empty()) {
                        auto curr = q.front();
                        q.pop();
                        
                        curr_res += grid[curr.first][curr.second];
                        
                        for(auto& dir : dirs) {
                            int nx = curr.first + dir[0], ny = curr.second + dir[1];
                            
                            if(nx >= 0 && nx < m && ny >= 0 && ny < n && grid[nx][ny] != 0 && !visited[nx][ny]) {
                                q.push({nx, ny});
                                visited[nx][ny] = true;
                            }
                        }
                    }
                    
                    res = max(curr_res, res);
                }
            }
        }
        
        return res;
    }
};


// Solution 2 using DFS
// Time Complexity: O(n * m)
// Space Complexity: O(n * m)
class Solution {
public:
    int findMaxFish(vector<vector<int>>& grid) {
        int res = 0, m = grid.size(), n = grid[0].size();
        vector<vector<int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        function<int(int, int)> dfs = [&](int x, int y) -> int {
            if(x < 0 || x >= m || y < 0 || y >= n || grid[x][y] == 0 || visited[x][y]) return 0;
            visited[x][y] = true;
            int res = grid[x][y];
            for(auto& dir: dirs){
                int nx = x + dir[0], ny = y + dir[1];
                res += dfs(nx, ny);
            }
            return res;
        };
        for(int i = 0; i < m;i++){
            for(int j = 0; j < n;j++){
                if(grid[i][j] != 0 && !visited[i][j]){
                    res = max(res, dfs(i, j));
                }
            }
        }
        return res;
    }
};