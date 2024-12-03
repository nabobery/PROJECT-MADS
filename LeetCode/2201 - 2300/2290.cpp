// 2290. Minimum Obstacle Removal to Reach Corner

// Solution 1: Using BFS to find the shortest path from the top-left corner to the bottom-right corner
// Time complexity: O(n^2)
// Space complexity: O(n^2)
// TLE 
class Solution {
    int minimumObstacles(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, INT_MAX));
        queue<pair<int, int>> q;
        q.push({0, 0});
        dp[0][0] = 0;
        vector<vector<int>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        while(!q.empty()){
            auto [x, y] = q.front();
            q.pop();
            for(auto [dx, dy]: dirs){
                int nx = x + dx, ny = y + dy;
                if(nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
                int cost = dp[x][y] + (grid[nx][ny] == 1);
                if(cost < dp[nx][ny]){
                    dp[nx][ny] = cost;
                    q.push({nx, ny});
                }
            }
        }
        return dp[m-1][n-1] == INT_MAX ? -1 : dp[m-1][n-1];
    }
};

// Optimized Solution 1 withut using dp
// Time complexity: O(n^2)
// Space complexity: O(n^2)
class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        queue<tuple<int, int, int>> q;
        q.push({0, 0, 0});
        vector<vector<int>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        while(!q.empty()){
            auto [x, y, cost] = q.front();
            q.pop();
            for(auto dir: dirs){
                int nx = x + dir[0], ny = y + dir[1];
                if(nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
                if(nx == m-1 && ny == n-1) return cost + (grid[nx][ny] == 1);
                q.push({nx, ny, cost + (grid[nx][ny] == 1)});
            }
        }
        return -1;
    }
};

// Solution 2: Using Dijkstra's algorithm to find the shortest path from the top-left corner to the bottom-right corner
// Time complexity: O(n^2 * log(n^2))
// Space complexity: O(n^2)
class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, INT_MAX));
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
        pq.push({0, 0, 0});
        dp[0][0] = 0;
        vector<vector<int>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        while(!pq.empty()){
            auto [cost, x, y] = pq.top();
            pq.pop();
            if(x == m-1 && y == n-1) return cost;
            for(auto& dir: dirs){
                int nx = x + dir[0], ny = y + dir[1];
                if(nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
                int new_cost = cost + (grid[nx][ny] == 1);
                if(new_cost < dp[nx][ny]){
                    dp[nx][ny] = new_cost;
                    pq.push({new_cost, nx, ny});
                }
            }
        }
        return -1;
    }
};

// Solution 3 : 0-1 BFS
// Time complexity: O(n^2)
// Space complexity: O(n^2)
class Solution {
public:
    vector<vector<int>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    int minimumObstacles(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        deque<array<int, 3>> dq;
        dq.push_back({0, 0, 0});
        vector<vector<int>> dp(m, vector<int>(n, INT_MAX));
        dp[0][0] = 0;
        while(!dq.empty()){
            auto [x, y, cost] = dq.front();
            dq.pop_front();
            for(auto& dir: dirs){
                int nx = x + dir[0], ny = y + dir[1];
                if(nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
                int new_cost = cost + (grid[nx][ny] == 1);
                if(dp[nx][ny] == INT_MAX){
                    dp[nx][ny] = new_cost;
                    if(grid[nx][ny] == 1) dq.push_back({nx, ny, new_cost});
                    else dq.push_front({nx, ny, new_cost});
                }
            }
        }
        return dp[m-1][n-1];
    }
};