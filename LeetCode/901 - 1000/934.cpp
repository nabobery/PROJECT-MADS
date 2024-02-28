// 934. Shortest Bridge

// Solution 1 using DFS to find one island and use BFS to find shortest distance between 2 islands
// Time complexity: O(n^2)
// Space complexity: O(n^2)
class Solution {
public:
    const int dirs[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    int shortestBridge(vector<vector<int>>& A) {
        int m = A.size(), n = A[0].size();
        queue<pair<int, int>> q;
        bool found = false;
        // find one island using dfs
        for(int i = 0; i < m;i++){
            if(found) break;
            for(int j = 0; j < n;j++){
                if(A[i][j] == 1){
                    dfs(A, i, j, q);
                    found = true;
                    break;
                }
            }
        }
        // multi source bfs to find shortest distance between 2 islands
        int res = 0;
        while(!q.empty()){
            int s = q.size();
            for(int i = 0; i < s;i++){
                auto curr = q.front();
                q.pop();
                for(auto dir : dirs){
                    int x = curr.first + dir[0], y = curr.second + dir[1];
                    if(x >= 0 && x < m && y >= 0 && y < n){
                        // if we find 1(reach the island), we return the result
                        if(A[x][y] == 1) return res;
                        // if we find 0, we mark it as 2 and push it into the queue
                        if(A[x][y] == 0){
                            A[x][y] = 2;
                            q.push({x, y});
                        }
                    }
                }
            }
            res++;
        }
        return -1;
    }
    
    // dfs to find one island by marking all cells of the island as 2 and pushing them into the queue
    // Marking them as 2 is to avoid visiting them again
    void dfs(vector<vector<int>>& A, int i, int j, queue<pair<int, int>>& q){
        int m = A.size(), n = A[0].size();
        if(i < 0 || i >= m || j < 0 || j >= n || A[i][j] != 1) return;
        A[i][j] = 2;
        q.push({i, j});
        for(auto dir : dirs){
            int x = i + dir[0], y = j + dir[1];
            dfs(A,x,y,q);
        }    
    }
};
    

// Solution 2 using BFS to find one island and use BFS to find shortest distance between 2 islands
// Time complexity: O(n^2)
// Space complexity: O(n^2)
class Solution {
public:
    const int dirs[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    int shortestBridge(vector<vector<int>>& A) {
        int m = A.size(), n = A[0].size();
        queue<pair<int, int>> q;
        bool found = false;
        // find one island using bfs
        for(int i = 0; i < m;i++){
            if(found) break;
            for(int j = 0; j < n;j++){
                if(A[i][j] == 1){
                    bfs(A, i, j, q);
                    found = true;
                    break;
                }
            }
        }
        // multi source bfs to find shortest distance between 2 islands
        int res = 0;
        while(!q.empty()){
            int s = q.size();
            for(int i = 0; i < s;i++){
                auto curr = q.front();
                q.pop();
                for(auto dir : dirs){
                    int x = curr.first + dir[0], y = curr.second + dir[1];
                    if(x >= 0 && x < m && y >= 0 && y < n){
                        // if we find 1(reach the island), we return the result
                        if(A[x][y] == 1) return res;
                        // if we find 0, we mark it as 2 and push it into the queue
                        if(A[x][y] == 0){
                            A[x][y] = 2;
                            q.push({x, y});
                        }
                    }
                }
            }
            res++;
        }
        return -1;
    }

    // bfs to find one island by marking all cells of the island as 2 and pushing them into the queue
    // Marking them as 2 is to avoid visiting them again
    void bfs(vector<vector<int>>& A, int i, int j, queue<pair<int, int>>& q){
        int m = A.size(), n = A[0].size();
        queue<pair<int, int>> q1;
        q1.push({i, j});
        A[i][j] = 2;
        while(!q1.empty()){
            auto curr = q1.front();
            q1.pop();
            q.push(curr);
            for(auto dir : dirs){
                int x = curr.first + dir[0], y = curr.second + dir[1];
                if(x >= 0 && x < m && y >= 0 && y < n && A[x][y] == 1){
                    A[x][y] = 2;
                    q1.push({x, y});
                }
            }
        }
    }
};