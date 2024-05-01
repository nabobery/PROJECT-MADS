// 1992. Find All Groups of Farmland

// Solution 1 using BFS
// Time complexity: O(m*n)
// Space complexity: O(m*n)
class Solution {
public:
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        int m = land.size(), n = land[0].size();
        vector<vector<int>> res;
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        vector<vector<int>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(land[i][j] == 1 && !visited[i][j]) {
                    queue<pair<int, int>> q;
                    q.push({i, j});
                    visited[i][j] = true;
                    vector<int> farmland = {i, j, i, j};
                    while(!q.empty()) {
                        auto [x, y] = q.front();
                        q.pop();
                        for(auto dir : dirs) {
                            int nx = x + dir[0], ny = y + dir[1];
                            if(nx >= 0 && nx < m && ny >= 0 && ny < n && land[nx][ny] == 1 && !visited[nx][ny]) {
                                visited[nx][ny] = true;
                                q.push({nx, ny});
                                farmland[2] = max(farmland[2], nx);
                                farmland[3] = max(farmland[3], ny);
                            }
                        }
                    }
                    res.push_back(farmland);
                }
            }
        }
        return res;
    }
};


// Solution 2 using DFS
// Time complexity: O(m*n)
// Space complexity: O(m*n)

class Solution {
public:
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        int m = land.size(), n = land[0].size();
        vector<vector<int>> res;
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        vector<vector<int>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        function<void(int, int, vector<int>&)> dfs = [&](int x, int y, vector<int>& farmland) {
            visited[x][y] = true;
            farmland[2] = max(farmland[2], x);
            farmland[3] = max(farmland[3], y);
            for(auto dir : dirs) {
                int nx = x + dir[0], ny = y + dir[1];
                if(nx >= 0 && nx < m && ny >= 0 && ny < n && land[nx][ny] == 1 && !visited[nx][ny]) {
                    dfs(nx, ny, farmland);
                }
            }
        };
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(land[i][j] == 1 && !visited[i][j]) {
                    vector<int> farmland = {i, j, i, j};
                    dfs(i, j, farmland);
                    res.push_back(farmland);
                }
            }
        }
        return res;
    }
};


// Solution 3 using Greedy approach
// Time complexity: O(m*n)
// Space complexity: O(1)

class Solution {
public:
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        int m = land.size(), n = land[0].size();
        vector<vector<int>> res;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(land[i][j]) {
                    int x = i, y = j;
                    while(x < m && land[x][j] == 1) x++;
                    while(y < n && land[i][y] == 1) y++;
                    res.push_back({i, j, x - 1, y - 1});
                    for(int k = i; k < x; k++) 
                        for(int l = j; l < y; l++) 
                            land[k][l] = 0;
                }
            }
        }
        return res;
    }
};