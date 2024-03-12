// 417. Pacific Atlantic Water Flow

// Solution 1 using multi source bfs
// Time complexity: O(n * m)
// Space complexity: O(n * m)
class Solution {
public:
    const int dirs[5] = {0, 1, 0, -1, 0};
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>> res;
        unordered_set<int> p, a;
        queue<tuple<int,int,int>> q;
        int m = heights.size(), n = heights[0].size();
        for(int i = 0; i < m;i++){
            q.push({i,0, 1});
            p.insert(i*n);
            q.push({i, n-1, 0});
            a.insert(i*n + n-1);
        }
        for(int i = 0; i < n;i++){
            q.push({0, i, 1});
            p.insert(i);
            q.push({m-1, i, 0});
            a.insert((m-1)*n + i);
        }
        while(!q.empty()){
            auto curr = q.front();
            int i = get<0>(curr), j = get<1>(curr), b = get<2>(curr);
            q.pop();
            for(int d = 0; d < 4;d++){
                int x = i + dirs[d], y = j + dirs[d+1];
                if(x < 0 || x >= m || y < 0 || y >= n || heights[i][j] > heights[x][y]) continue;
                if(b == 1){
                    if(!p.count(x*n + y)){
                        p.insert(x*n + y);
                        q.push({x,y,b});
                    }
                }
                else{
                    if(!a.count(x*n + y)){
                        a.insert(x*n + y);
                        q.push({x,y,b});
                    }
                }
            }
        }
        for(int it : p)
            if(a.count(it))
                res.push_back({it/n, it%n});
        return res;
    }
};

// Solution 1 with 2d boolean array to store visited
// Time complexity: O(n * m)
// Space complexity: O(n * m)
class Solution {
public:
    const int dirs[5] = {0, 1, 0, -1, 0};
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>> res;
        int m = heights.size(), n = heights[0].size();
        vector<vector<bool>> p(m, vector<bool>(n, false)), a(m, vector<bool>(n, false));
        queue<tuple<int,int,int>> q;
        for(int i = 0; i < m;i++){
            q.push({i,0, 1});
            p[i][0] = true;
            q.push({i, n-1, 0});
            a[i][n-1] = true;
        }
        for(int i = 0; i < n;i++){
            q.push({0, i, 1});
            p[0][i] = true;
            q.push({m-1, i, 0});
            a[m-1][i] = true;
        }
        while(!q.empty()){
            auto curr = q.front();
            int i = get<0>(curr), j = get<1>(curr), b = get<2>(curr);
            q.pop();
            for(int d = 0; d < 4;d++){
                int x = i + dirs[d], y = j + dirs[d+1];
                if(x < 0 || x >= m || y < 0 || y >= n || heights[i][j] > heights[x][y]) continue;
                if(b == 1){
                    if(!p[x][y]){
                        p[x][y] = true;
                        q.push({x,y,b});
                    }
                }
                else{
                    if(!a[x][y]){
                        a[x][y] = true;
                        q.push({x,y,b});
                    }
                }
            }
        }
        for(int i = 0; i < m;i++)
            for(int j = 0; j < n;j++)
                if(p[i][j] && a[i][j])
                    res.push_back({i,j});
        return res;
    }
};