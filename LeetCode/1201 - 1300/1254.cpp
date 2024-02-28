// 1254. Number of Closed Islands

// An island is a maximal 4-directionally connected group of 0s and a closed island is an island totally (all left, top, right, bottom) surrounded by 1s

// Solution 1 using DFS
// Time complexity: O(m*n)
// Space complexity: O(m*n)
// We first exclude the islands that are connected to the boundary because they are not closed islands. 
// Then we use DFS to find the closed islands(connected zeros) and count them.
class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        // DFS to find the connected zeros and return true if it is a closed island
        function<bool(int, int)> dfs = [&](int i, int j) {
            if (i < 0 || i >= m || j < 0 || j >= n) 
                return false;
            if (grid[i][j] == 1) 
                return true;
            grid[i][j] = 1;
            bool res = true;
            for (auto& dir : dirs) 
                res &= dfs(i + dir[0], j + dir[1]);
            return res;
        };
        int count = 0;
        // exclude the islands that are connected to the boundary
        for (int i = 0; i < m; i++) {
            if (grid[i][0] == 0) 
                dfs(i, 0);
            if (grid[i][n - 1] == 0) 
                dfs(i, n - 1);
        }
        for (int j = 0; j < n; j++) {
            if (grid[0][j] == 0) 
                dfs(0, j);
            if (grid[m - 1][j] == 0) 
                dfs(m - 1, j);
        }
        // count the connected zeros
        for (int i = 1; i < m - 1; i++) 
            for (int j = 1; j < n - 1; j++) 
                if (grid[i][j] == 0) 
                    count += dfs(i, j);
        return count;
    }
};

// Solution 2 using BFS
// Time complexity: O(m*n)
// Space complexity: O(m*n)

class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        // BFS to find the connected zeros and return true if it is a closed island
        function<bool(int, int)> bfs = [&](int i, int j) {
            queue<pair<int, int>> q;
            q.push({i, j});
            bool res = true;
            while (!q.empty()) {
                auto [x, y] = q.front();
                q.pop();
                if (x < 0 || x >= m || y < 0 || y >= n) 
                    res = false;
                else if (grid[x][y] == 0) {
                    grid[x][y] = 1;
                    for (auto& dir : dirs) 
                        q.push({x + dir[0], y + dir[1]});
                }
            }
            return res;
        };
        int count = 0;
        // exclude the islands that are connected to the boundary
        for (int i = 0; i < m; i++) {
            if (grid[i][0] == 0) 
                bfs(i, 0);
            if (grid[i][n - 1] == 0) 
                bfs(i, n - 1);
        }
        for (int j = 0; j < n; j++) {
            if (grid[0][j] == 0) 
                bfs(0, j);
            if (grid[m - 1][j] == 0) 
                bfs(m - 1, j);
        }
        // count the connected zeros
        for (int i = 1; i < m - 1; i++) 
            for (int j = 1; j < n - 1; j++) 
                if (grid[i][j] == 0) 
                    count += bfs(i, j);
        return count;
    }
};