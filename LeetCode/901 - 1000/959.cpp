// 959. Regions Cut By Slashes

// Solution 1 using flood fill
// Time complexity: O(n^2)
// Space complexity: O(n^2)
// The basic idea is to expand the grid by 3 times and then fill the grid with 1 where the slashes are present.
// Then we can use flood fill to find the number of regions by changing the value of the cell to 1 and then recursively calling the function on the adjacent cells.
// The number of regions will be the number of times we call the flood fill function.
class Solution {
public:
    int regionsBySlashes(vector<string>& grid) {
        int n = grid.size();
        vector<vector<int>> g(3*n, vector<int>(3*n, 0));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == '/') {
                    g[3*i][3*j+2] = 1;
                    g[3*i+1][3*j+1] = 1;
                    g[3*i+2][3*j] = 1;
                } else if(grid[i][j] == '\\') {
                    g[3*i][3*j] = 1;
                    g[3*i+1][3*j+1] = 1;
                    g[3*i+2][3*j+2] = 1;
                }
            }
        }
        int ans = 0;
        for(int i = 0; i < 3*n; i++) {
            for(int j = 0; j < 3*n; j++) {
                if(g[i][j] == 0) {
                    dfs(g, i, j);
                    ans++;
                }
            }
        }
        return ans;
    }
    void dfs(vector<vector<int>>& g, int i, int j) {
        if(i < 0 || j < 0 || i >= g.size() || j >= g.size() || g[i][j] == 1) return;
        g[i][j] = 1;
        dfs(g, i+1, j);
        dfs(g, i-1, j);
        dfs(g, i, j+1);
        dfs(g, i, j-1);
    }
};

// Solution 2 using bfs
// Time complexity: O(n^2)
// Space complexity: O(n^2)
class Solution {
public:
    const int dx[4] = {0, 0, 1, -1};
    const int dy[4] = {1, -1, 0, 0};
    int regionsBySlashes(vector<string>& grid) {
        int n = grid.size();
        vector<vector<int>> g(3*n, vector<int>(3*n, 0));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == '/') {
                    g[3*i][3*j+2] = 1;
                    g[3*i+1][3*j+1] = 1;
                    g[3*i+2][3*j] = 1;
                } else if(grid[i][j] == '\\') {
                    g[3*i][3*j] = 1;
                    g[3*i+1][3*j+1] = 1;
                    g[3*i+2][3*j+2] = 1;
                }
            }
        }
        int ans = 0;
        for(int i = 0; i < 3*n; i++) {
            for(int j = 0; j < 3*n; j++) {
                if(g[i][j] == 0) {
                    bfs(g, i, j);
                    ans++;
                }
            }
        }
        return ans;
    }
    void bfs(vector<vector<int>>& g, int i, int j) {
        queue<pair<int, int>> q;
        q.push({i, j});
        g[i][j] = 1;
        while(!q.empty()) {
            auto [x, y] = q.front();
            q.pop();
            for(int k = 0; k < 4; k++) {
                int nx = x + dx[k];
                int ny = y + dy[k];
                if(nx < 0 || ny < 0 || nx >= g.size() || ny >= g.size() || g[nx][ny] == 1) continue;
                g[nx][ny] = 1;
                q.push({nx, ny});
            }
        }
    }
};
