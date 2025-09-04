// 3446. Sort Matrix by Diagonals

// Solution 1: Simple and StraightForward (Using BFS and Sorting)
// Time Complexity: O(n^2 + nlogn)
// Space Complexity: O(n^2)
class Solution {
public:
    int dirs[2][2] = {{0,-1}, {1, 0}};
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n = grid.size(), p = 0;
        vector<vector<int>> res(n, vector<int>(n));
        unordered_set<int> visited;
        queue<int> q;
        q.push(n-1);
        visited.insert(n-1);
        while(!q.empty()){
            int l = q.size();
            set<int> pos;
            vector<int> s;
            for(int i = 0; i < l;i++){
                auto front = q.front();
                q.pop();
                int x = front/n, y = front%n;
                s.push_back(grid[x][y]);
                pos.insert(front);
                for(auto& dir: dirs){
                    int nx = x + dir[0], ny = y + dir[1];
                    if(nx >= 0 && nx < n && ny >=0 && ny < n && !visited.count(nx*n + ny)){
                        q.push(nx*n + ny);
                        visited.insert(nx*n + ny);
                    }
                }
            }
            int k = 0;
            sort(s.begin(), s.end());
            if(p >= n-1) reverse(s.begin(), s.end());
            for(auto i: pos){
                int x = i/n, y = i % n;
                res[x][y] = s[k++];
            }
            p++;
        }
        return res;
    }
};

// Simpler and Cleaner Solution 2
// Time Complexity: O(n^2 + nlogn)
// Space Complexity: O(n^2)
class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> res(n, vector<int>(n));
        
        // Collect diagonals by (i - j)
        unordered_map<int, vector<int>> diag;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                diag[i - j].push_back(grid[i][j]);
            }
        }
        
        // Sort diagonals
        for (int d = n - 1; d >= -(n - 1); d--) {
            auto& v = diag[d];
            sort(v.begin(), v.end());
            if (d < 0) reverse(v.begin(), v.end()); // alternate order
        }
        
        // Refill matrix
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                auto& v = diag[i - j];
                res[i][j] = v.back();
                v.pop_back();
            }
        }
        return res;
    }
};
