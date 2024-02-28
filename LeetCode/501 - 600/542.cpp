// 542. 01 Matrix

// Bruteforce approach by performing BFS from each 1 cell (TLE)
// Time complexity: O(n^4)
// Space complexity: O(n^2)
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vector<vector<int>> res(m, vector<int>(n, 0));
        vector<vector<int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        for(int i = 0; i < m;i++){
            for(int j = 0; j < n;j++){
                if(mat[i][j] == 0) continue;
                queue<pair<int, int>> q;
                q.push({i, j});
                int dist = 0;
                vector<vector<bool>> visited(m, vector<bool>(n, false));
                while(!q.empty()){
                    int s = q.size();
                    for(int k = 0; k < s;k++){
                        auto curr = q.front();
                        q.pop();
                        visited[curr.first][curr.second] = true;
                        if(mat[curr.first][curr.second] == 0){
                            res[i][j] = dist;
                            break;
                        }
                        for(auto dir : dirs){
                            int x = curr.first + dir[0], y = curr.second + dir[1];
                            if(x >= 0 && x < m && y >= 0 && y < n && !visited[x][y]){
                                q.push({x, y});
                            }
                        }
                    }
                    if(res[i][j] != 0) break;
                    dist++;
                }
            }
        }
        return res;
    }
};

// Solution 1 using Multi Source BFS and traversing from 0 cells and update distance from them to nearest 1 cell
// Time complexity: O(n^2)
// Space complexity: O(n^2)
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vector<vector<int>> res(m, vector<int>(n, 1e5));
        vector<vector<int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        queue<pair<int, int>> q;
        for(int i = 0; i < m;i++){
            for(int j = 0; j < n;j++){
                if(mat[i][j] == 0){
                    res[i][j] = 0;
                    q.push({i, j});
                }
            }
        }
        while(!q.empty()){
            auto curr = q.front();
            q.pop();
            for(auto dir : dirs){
                int x = curr.first + dir[0], y = curr.second + dir[1];
                if(x >= 0 && x < m && y >= 0 && y < n && res[x][y] > res[curr.first][curr.second] + 1){
                    res[x][y] = res[curr.first][curr.second] + 1;
                    q.push({x, y});
                }
            }
        }
        return res;
    }
};

// Solution 2 using Dynamic Programming and traversing from 0 cells and update distance from them to nearest 1 cell
// Time complexity: O(n^2)
// Space complexity: O(n^2)
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vector<vector<int>> res(m, vector<int>(n, 1e5));
        // fill all the 0 cells with 0 distance
        for(int i = 0; i < m;i++){
            for(int j = 0; j < n;j++){
                if(mat[i][j] == 0){
                    res[i][j] = 0;
                }
            }
        }
        // fill the base case distance for adjacent 1 cells to 0
        for(int i = 0; i < m;i++){
            for(int j = 0; j < n;j++){
                if(i > 0) res[i][j] = min(res[i][j], res[i - 1][j] + 1);
                if(j > 0) res[i][j] = min(res[i][j], res[i][j - 1] + 1);
            }
        }
        // calculate the minimum distance for each cell to reach 0
        for(int i = m - 1; i >= 0;i--){
            for(int j = n - 1; j >= 0;j--){
                if(i < m - 1) res[i][j] = min(res[i][j], res[i + 1][j] + 1);
                if(j < n - 1) res[i][j] = min(res[i][j], res[i][j + 1] + 1);
            }
        }
        return res;
    }
};