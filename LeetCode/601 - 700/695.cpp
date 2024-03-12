// 695. Max Area of Island

// Solution 1 using dfs and maintaining a visited hashset
// Time complexity: O(n*m)
// Space complexity: O(n*m)
class Solution {
public:
    int m, n;
    unordered_set<int> visited;
    const int dirs[5] = {0, 1, 0, -1, 0};
    void dfs(vector<vector<int>>& grid, int i, int j){
        if(i >= m || i < 0 || j >= n || j < 0 || grid[i][j] == 0) return;
        grid[i][j] = 0;
        visited.insert(i*n + j);
        for(int d = 0; d < 4;d++){
            int x = i + dirs[d], y = j+dirs[d+1];
            dfs(grid, x,y);
        }
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        m = grid.size(), n = grid[0].size();
        int prev = 0, res = 0;
        for(int i = 0; i < m;i++){
            for(int j = 0; j < n;j++){
                if(grid[i][j] == 1){
                    dfs(grid,i,j);
                    res = max(res, int(visited.size()) - prev);
                    prev = visited.size();
                }
            }
        }
        return res;
    }
};

// Solution 2 using dfs and without maintaining a visited hashset
// Time complexity: O(n*m)
// Space complexity: O(n*m) (dfs stack)
class Solution {
public:
    int m, n;
    const int dirs[5] = {0, 1, 0, -1, 0};
    int dfs(vector<vector<int>>& grid, int i, int j){
        if(i >= m || i < 0 || j >= n || j < 0 || grid[i][j] == 0) return 0;
        grid[i][j] = 0;
        int res = 1;
        for(int d = 0; d < 4;d++){
            int x = i + dirs[d], y = j+dirs[d+1];
            res += dfs(grid, x,y);
        }
        return res;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        m = grid.size(), n = grid[0].size();
        int res = 0;
        for(int i = 0; i < m;i++)
            for(int j = 0; j < n;j++)
                if(grid[i][j] == 1)
                    res = max(res, dfs(grid,i,j));
        return res;
    }
};

// Solution 3 using bfs and without maintaining a visited hashset
// Time complexity: O(n*m)
// Space complexity: O(n*m) queue
class Solution {
public:
    int m, n;
    const int dirs[5] = {0, 1, 0, -1, 0};
    int bfs(vector<vector<int>>& grid, int i, int j){
        queue<pair<int,int>> q;
        q.push({i,j});
        grid[i][j] = 0;
        int res = 1;
        while(!q.empty()){
            auto [x,y] = q.front();
            q.pop();
            for(int d = 0; d < 4;d++){
                int nx = x + dirs[d], ny = y+dirs[d+1];
                if(nx >= m || nx < 0 || ny >= n || ny < 0 || grid[nx][ny] == 0) continue;
                grid[nx][ny] = 0;
                q.push({nx,ny});
                res++;
            }
        }
        return res;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        m = grid.size(), n = grid[0].size();
        int res = 0;
        for(int i = 0; i < m;i++)
            for(int j = 0; j < n;j++)
                if(grid[i][j] == 1)
                    res = max(res, bfs(grid,i,j));
        return res;
    }
};