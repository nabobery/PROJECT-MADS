// 778. Swim in Rising Water

// Solution 1: Naive using BFS 
// Time Complexity: O(N^4)
// Space Complexity: O(N^2)
class Solution {
public:
    const int dirs[4][2] = {{0, -1}, {0, 1}, {1,0}, {-1, 0}};
    bool bfs(vector<vector<int>>& grid, int t, vector<vector<bool>>& visited){
        int n = grid.size();
        if(grid[0][0] > t) return false;
        queue<pair<int,int>> q;
        q.push({0, 0});
        visited[0][0] = true;
        while(!q.empty()){
            auto curr = q.front();
            q.pop();
            bool b = false;
            for(auto& dir: dirs){
                int nx = curr.first + dir[0], ny = curr.second + dir[1];
                if(nx >= 0 && nx < n && ny >= 0 && ny < n && !visited[nx][ny] && grid[nx][ny] <= t){
                    q.push({nx,ny});
                    visited[nx][ny] = true;
                    if(nx == n-1 && ny == n-1){
                        b = true;
                        break;
                    }
                }
            }
            if(b) return true;
        }
        return false;
    }
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size(), res = n*n;
        if(n == 1) return 0;
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        for(int i = 0; i <= n*n;i++){
            if(bfs(grid, i, visited)){
                res = i;
                break;
            }
            for (auto& row : visited) fill(row.begin(), row.end(), false);
        }
        return res;
    }
};

// Solution 2: Using Binary Search + BFS
// Time Complexity: O(N^2 logN)
// Space Complexity: O(N^2)
class Solution {
public:
    const int dirs[4][2] = {{0, -1}, {0, 1}, {1,0}, {-1, 0}};
    bool bfs(vector<vector<int>>& grid, int t, vector<vector<bool>>& visited){
        int n = grid.size();
        if(grid[0][0] > t) return false;
        queue<pair<int,int>> q;
        q.push({0, 0});
        visited[0][0] = true;
        while(!q.empty()){
            auto curr = q.front();
            q.pop();
            bool b = false;
            for(auto& dir: dirs){
                int nx = curr.first + dir[0], ny = curr.second + dir[1];
                if(nx >= 0 && nx < n && ny >= 0 && ny < n && !visited[nx][ny] && grid[nx][ny] <= t){
                    q.push({nx,ny});
                    visited[nx][ny] = true;
                    if(nx == n-1 && ny == n-1){
                        b = true;
                        break;
                    }
                }
            }
            if(b) return true;
        }
        return false;
    }
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size(), left = 0, right = n*n - 1, res = n*n - 1;
        if(n == 1) return 0;
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        while(left <= right){
            int mid = left + (right - left)/2;
            if(bfs(grid, mid, visited)){
                res = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
            for (auto& row : visited) fill(row.begin(), row.end(), false);
        }
        return res;
    }
};