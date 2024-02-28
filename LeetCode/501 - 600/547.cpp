// 547. Number of Provinces

// Solution 1 using DFS and fining the number of Connected Components
// Time complexity: O(n^2)
// Space complexity: O(n)
class Solution {
public:
    void dfs(int u, vector<vector<int>>& adj, vector<bool>& visited){
        visited[u] = true;
        for(int i = 0; i < visited.size();i++)
            if(!visited[i] && adj[u][i])
                dfs(i, adj, visited);
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size(), res = 0;
        vector<bool> visited(n, false);
        for(int i = 0; i < n;i++){
            if(!visited[i]){
                dfs(i, isConnected, visited);
                res++;
            }
        }
        return res;
    }
};

// Solution 2 using BFS and fining the number of Connected Components
// Time complexity: O(n^2)
// Space complexity: O(n)
class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size(), res = 0;
        vector<bool> visited(n, false);
        queue<int> q;
        for(int i = 0; i < n;i++){
            if(!visited[i]){
                q.push(i);
                while(!q.empty()){
                    int u = q.front();
                    q.pop();
                    visited[u] = true;
                    for(int v = 0; v < n;v++)
                        if(!visited[v] && isConnected[u][v])
                            q.push(v);
                }
                res++;
            }
        }
        return res;
    }
};

// Solution 3 using Union Find
// Time complexity: O(n^2)
// Space complexity: O(n)
class Solution {
public:
    int find(vector<int>& parent, int u){
        if(parent[u] == u)
            return u;
        return parent[u] = find(parent, parent[u]);
    }
    void merge(vector<int>& parent, int u, int v){
        u = find(parent, u);
        v = find(parent, v);
        if(u != v)
            parent[u] = v;
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size(), res = 0;
        vector<int> parent(n);
        for(int i = 0; i < n;i++)
            parent[i] = i;
        for(int i = 0; i < n;i++)
            for(int j = 0; j < n;j++)
                if(isConnected[i][j])
                    merge(parent, i, j);
        for(int i = 0; i < n;i++)
            if(parent[i] == i)
                res++;
        return res;
    }
};