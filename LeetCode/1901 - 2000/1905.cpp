// 1905. Count Sub Islands

// Naive DFS solution by marking visited nodes in grid2 and then checking if all nodes in the island are 1 in grid1
// Time complexity: O(n*m)
// Space complexity: O(n*m)
class Solution {
public:
    const int dirs[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    int m, n;
    void dfs(vector<vector<int>>& grid, int i, int j, set<int>& vis){
        if(i < 0 || i >= m || j < 0 || j >= n || grid[i][j] != 1) return;
        grid[i][j] = -1;
        vis.insert(i*n + j);
        for(auto dir : dirs){
            int x = i + dir[0], y = j + dir[1];
            dfs(grid,x,y, vis);
        }    
    }
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        m = grid1.size(); n = grid1[0].size();
        vector<set<int>> islands;
        set<int> vis;
        for(int i = 0; i < m;i++){
            for(int j = 0; j < n;j++){
                if(grid2[i][j] == 1){
                    dfs(grid2, i, j, vis);
                    islands.push_back(vis);
                    vis.clear();
                }
            }
        }
        int res = 0,i,j;
        for(auto it: islands){
            bool b = true;
            for(auto k : it){
                i = k/n, j = k % n;
                if(grid1[i][j] != 1){
                    b = false;
                    break;
                }
            }
            if(b) res++;
        }
        return res;
    }
};

// Solution 2 Optimized DFS (Flooding) solution
// Time complexity: O(n*m)
// Space complexity: O(n*m)
class Solution {
public:
    const int dirs[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    int m, n;
    void dfs(vector<vector<int>>& grid1, vector<vector<int>>& grid2, int i, int j, bool& b){
        if(i < 0 || i >= m || j < 0 || j >= n || grid2[i][j] != 1) return;
        grid2[i][j] = -1;
        if(grid1[i][j] != 1) b = false;
        for(auto dir : dirs){
            int x = i + dir[0], y = j + dir[1];
            dfs(grid1, grid2, x, y, b);
        }    
    }
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        m = grid1.size(); n = grid1[0].size();
        int res = 0;
        for(int i = 0; i < m;i++){
            for(int j = 0; j < n;j++){
                if(grid2[i][j] == 1){
                    bool b = true;
                    dfs(grid1, grid2, i, j, b);
                    if(b) res++;
                }
            }
        }
        return res;
    }
};