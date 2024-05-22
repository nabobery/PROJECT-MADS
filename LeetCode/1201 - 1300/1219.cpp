// 1219. Path with Maximum Gold

// Solution 1 using Recursion and Backtracking
// Time Complexity: O(4^N)
// Space Complexity: O(N)
class Solution {
public:
    int res,m,n;
    bool visited[15][15];
    const int dirs[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    void dfs(pair<int,int> p, int curr, vector<vector<int>>& grid){
        res = max(res, curr);
        visited[p.first][p.second] = true;
        for(auto dir : dirs){
            int x = p.first + dir[0], y = p.second + dir[1];
            if(x >= 0 && x < m && y >= 0 && y < n && grid[x][y] && !visited[x][y]){
                dfs({x,y}, curr + grid[x][y], grid);
                visited[x][y] = false;
            }
        }
    }
    
    int getMaximumGold(vector<vector<int>>& grid) {
        res = 0; m = grid.size(); n = grid[0].size();
        for(int i = 0; i < m;i++){
            for(int j = 0; j < n;j++){
                if(grid[i][j]){
                    memset(visited, false, sizeof(visited));
                    dfs({i,j}, grid[i][j], grid);
                    
                }
            }
        }
        return res;
    }
};

// Solution 2 using Recursion and Backtracking  Optimized and Clean
// Time Complexity: O(4^N)
// Space Complexity: O(N)

class Solution {
public:
    int res,m,n;
    const int dirs[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    void dfs(pair<int,int> p, int curr, vector<vector<int>>& grid){
        res = max(res, curr);
        int x,y;
        grid[p.first][p.second] = -grid[p.first][p.second];
        for(auto dir : dirs){
            x = p.first + dir[0], y = p.second + dir[1];
            if(x >= 0 && x < m && y >= 0 && y < n && grid[x][y] > 0){
                dfs({x,y}, curr + grid[x][y], grid);
            }
        }
        grid[p.first][p.second] = -grid[p.first][p.second];
    }
    
    int getMaximumGold(vector<vector<int>>& grid) {
        res = 0; m = grid.size(); n = grid[0].size();
        for(int i = 0; i < m;i++)
            for(int j = 0; j < n;j++)
                if(grid[i][j])
                    dfs({i,j}, grid[i][j], grid);
        return res;
    }
};