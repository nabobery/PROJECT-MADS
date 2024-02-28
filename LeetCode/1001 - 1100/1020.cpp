// 1020. Number of Enclaves

// Solution 1 by treating grid as a graph and then applying dfs to count the number of closed enclaves
// Time complexity: O(m*n)
// Space complexity: O(m*n)
class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        function<void(int, int)> dfs = [&](int i, int j) {
            if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == 0) {
                return;
            }
            grid[i][j] = 0;
            for (auto& dir : dirs) {
                dfs(i + dir[0], j + dir[1]);
            }
        };
        // apply dfs from all boundaries and check all lands(cells with 1) we can reach and mark them as 0
        for (int i = 0; i < m; i++) {
            dfs(i, 0);
            dfs(i, n - 1);
        }
        for (int j = 0; j < n; j++) {
            dfs(0, j);
            dfs(m - 1, j);
        }
        // the unreachable lands are the enclaves so we count them
        int count = 0;
        for (int i = 1; i < m - 1; i++) {
            for (int j = 1; j < n - 1; j++) {
                count += grid[i][j];
            }
        }
        return count;
    }
};

// Cleaner solution 1 with visited set
class Solution {
public:
    unordered_set<int> visited;
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        function<void(int, int)> dfs = [&](int i, int j) {
            if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == 0 || visited.count(i * n + j))
                return;
            grid[i][j] = 0;
            visited.insert(i * n + j);
            for (auto& dir : dirs) 
                dfs(i + dir[0], j + dir[1]);
        };
        for (int i = 0; i < m; i++) {
            if (grid[i][0] == 1) 
                dfs(i, 0);
            if (grid[i][n - 1] == 1) 
                dfs(i, n - 1);
        }
        for (int j = 0; j < n; j++) {
            if (grid[0][j] == 1) 
                dfs(0, j);
            if (grid[m - 1][j] == 1) 
                dfs(m - 1, j);
        }
        int count = 0;
        for (int i = 1; i < m - 1; i++) 
            for (int j = 1; j < n - 1; j++) 
                count += grid[i][j];
        return count;
    }
};

// Solution 2 by treating grid as a graph and then applying bfs to count the number of enclaves with visited set
// Time complexity: O(m*n)
// Space complexity: O(m*n)
class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        queue<pair<int, int>> q;
        unordered_set<int> visited;
        for (int i = 0; i < m; i++) {
            if (grid[i][0] == 1) {
                q.push({i, 0});
                visited.insert(i * n);
            }
            if (grid[i][n - 1] == 1) {
                q.push({i, n - 1});
                visited.insert(i * n + n - 1);
            }
        }
        for (int j = 0; j < n; j++) {
            if (grid[0][j] == 1) {
                q.push({0, j});
                visited.insert(j);
            }
            if (grid[m - 1][j] == 1) {
                q.push({m - 1, j});
                visited.insert((m - 1) * n + j);
            }
        }
        while (!q.empty()) {
            auto [i, j] = q.front();
            q.pop();
            grid[i][j] = 0;
            for (auto& dir : dirs) {
                int x = i + dir[0], y = j + dir[1];
                if (x >= 0 && x < m && y >= 0 && y < n && grid[x][y] == 1 && !visited.count(x * n + y)) {
                    q.push({x, y});
                    visited.insert(x * n + y);
                }
            }
        }
        int count = 0;
        for (int i = 1; i < m - 1; i++) 
            for (int j = 1; j < n - 1; j++) 
                count += grid[i][j];
        return count;
    }
};


// TODO: Using Union Find