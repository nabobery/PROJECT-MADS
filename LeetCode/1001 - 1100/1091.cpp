// 1091. Shortest Path in Binary Matrix

// Solution 1 using BFS to find shortest path
// Time complexity: O(n^2)
// Space complexity: O(n^2)
class Solution {
public:
    const int dirs[8][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if(grid[0][0]) return -1;
        int n = grid.size(), res = 1;
        queue<pair<int,int>> q;
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        visited[0][0] = true;
        q.push({0,0});
        while(!q.empty()){
            int s = q.size();
            for(int i = 0; i < s;i++){
                auto curr = q.front();
                q.pop();
                if(curr.first == curr.second && curr.first == n-1) return res;
                for(auto dir : dirs){
                    int x = curr.first + dir[0], y = curr.second + dir[1];
                    if(x >= 0 && x < n && y >=0 && y < n && !visited[x][y] && !grid[x][y]){
                        q.push({x,y});
                        visited[x][y] = true;
                    }
                }
            }
            res++;
        }
        return -1;
    }
};


// Cleaned up way and early return after finding the destination
class Solution {
public:
    const int dirs[8][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if(grid[0][0]) return -1;
        int n = grid.size(), res = 1;
        queue<pair<int,int>> q;
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        visited[0][0] = true;
        q.push({0,0});
        while(!q.empty()){
            int s = q.size();
            for(int i = 0; i < s;i++){
                auto curr = q.front();
                q.pop();
                if(curr.first == curr.second && curr.first == n-1) return res;
                for(auto dir : dirs){
                    int x = curr.first + dir[0], y = curr.second + dir[1];
                    if(x >= 0 && x < n && y >=0 && y < n && !visited[x][y] && !grid[x][y]){
                        q.push({x,y});
                        visited[x][y] = true;
                        if(x == n-1 && y == n-1) return res+1;
                    }
                }
            }
            res++;
        }
        return -1;
    }
};