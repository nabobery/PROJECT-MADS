// 1368. Minimum Cost to Make at Least One Valid Path in a Grid

// Solution 1 using BFS
// Time Complexity: O(m*n)
// Space Complexity: O(m*n)
class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> cost(m, vector<int>(n, INT_MAX));
        queue<pair<int, int>> q;
        q.push({0, 0});
        cost[0][0] = 0;
        vector<vector<int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();
            for (int i = 0; i < 4; i++) {
                int nx = x + dirs[i][0];
                int ny = y + dirs[i][1];
                if (nx >= 0 && nx < m && ny >= 0 && ny < n) {
                    int newCost = cost[x][y] + (grid[x][y] != i + 1);
                    if (newCost < cost[nx][ny]) {
                        cost[nx][ny] = newCost;
                        q.push({nx, ny});
                    }
                }
            }
        }
        return cost[m - 1][n - 1];
    }
};