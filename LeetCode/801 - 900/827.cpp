// 827. Making A Large Island

// Solution 1: Brute Force (TLE)
// Time Complexity: O(n^4)
// Space Complexity: O(n^2)
class Solution {
public:
    int islandSize(vector<vector<int>>& grid) {
        int n = grid.size();
        queue<int> q;
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        auto bfs = [&](int startX, int startY) {
            int size = 0;
            queue<pair<int, int>> q;
            q.push({startX, startY});
            visited[startX][startY] = true;

            while (!q.empty()) {
                auto [x, y] = q.front();
                q.pop();
                size++;
                for (auto [dx, dy] : directions) {
                    int nx = x + dx;
                    int ny = y + dy;

                    if (nx >= 0 && nx < n && ny >= 0 && ny < n &&
                        !visited[nx][ny] && grid[nx][ny] == 1) {
                        visited[nx][ny] = true;
                        q.push({nx, ny});
                    }
                }
            }

            return size;
        };
        int maxSize = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1 && !visited[i][j]) {
                    maxSize = max(maxSize, bfs(i, j));
                }
            }
        }

        return maxSize;
    }
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size(), res = islandSize(grid);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) {
                    grid[i][j] = 1;
                    res = max(res, islandSize(grid));
                    grid[i][j] = 0;
                }
            }
        }
        return res;
    }
};

// Solution 2: By pre computing the size of each island and then checking the size of the island after changing 0 to 1
// Time Complexity: O(n^2)
// Space Complexity: O(n^2)
class Solution {
public:
    int islandSize(vector<vector<int>>& grid, vector<vector<int>>& islandId, int x, int y, int islandLabel) {
        int n = grid.size();
        int size = 0;
        queue<pair<int, int>> q;
        q.push({x, y});
        islandId[x][y] = islandLabel;

        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        
        while (!q.empty()) {
            auto [cx, cy] = q.front();
            q.pop();
            size++;
            for (auto& [dx, dy] : directions) {
                int nx = cx + dx, ny = cy + dy;
                if (nx >= 0 && nx < n && ny >= 0 && ny < n &&
                    grid[nx][ny] == 1 && islandId[nx][ny] == 0) {
                    islandId[nx][ny] = islandLabel;
                    q.push({nx, ny});
                }
            }
        }
        
        return size;
    }

    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> islandId(n, vector<int>(n, 0)); 
        unordered_map<int, int> islandSizes;
        int islandLabel = 1;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1 && islandId[i][j] == 0) {
                    int size = islandSize(grid, islandId, i, j, islandLabel);
                    islandSizes[islandLabel] = size;
                    islandLabel++;
                }
            }
        }
        int maxSize = 0;
        for (const auto& entry : islandSizes) {
            maxSize = max(maxSize, entry.second);
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 0) {
                    unordered_set<int> neighboringIslands;
                    int potentialSize = 1;  
                    vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
                    for (auto& [dx, dy] : directions) {
                        int nx = i + dx, ny = j + dy;
                        if (nx >= 0 && nx < n && ny >= 0 && ny < n && grid[nx][ny] == 1) {
                            int neighborIsland = islandId[nx][ny];
                            if (neighborIsland != 0 && neighboringIslands.find(neighborIsland) == neighboringIslands.end()) {
                                neighboringIslands.insert(neighborIsland);
                                potentialSize += islandSizes[neighborIsland];
                            }
                        }
                    }

                    maxSize = max(maxSize, potentialSize);
                }
            }
        }

        return maxSize;
    }
};