// 1971. Find if Path Exists in Graph

// Solution 1 using BFS
// Time complexity: O(n)
// Space complexity: O(n)
class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> adj(n);
        for(auto& edge: edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        queue<int> q;
        q.push(source);
        vector<bool> visited(n, false);
        visited[source] = true;
        while(!q.empty()){
            int curr = q.front();
            q.pop();
            if(curr == destination) return true;
            for(int& neighbor : adj[curr])
                if(!visited[neighbor]){
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
        }
        return false;
    }
};

// Solution 2 using DFS
// Time complexity: O(n)
// Space complexity: O(n)
class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> adj(n);
        for(auto& edge: edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        vector<bool> visited(n, false);
        return dfs(adj, visited, source, destination);
    }
    
    bool dfs(vector<vector<int>>& adj, vector<bool>& visited, int curr, int destination){
        if(curr == destination) return true;
        visited[curr] = true;
        for(int& neighbor : adj[curr])
            if(!visited[neighbor] && dfs(adj, visited, neighbor, destination))
                return true;
        return false;
    }
};

// Solution 3 using Union Find
// Time complexity: O(n)
// Space complexity: O(n)
class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<int> parent(n);
        iota(parent.begin(), parent.end(), 0);
        for(auto& edge: edges){
            int x = find(parent, edge[0]);
            int y = find(parent, edge[1]);
            if(x != y) parent[x] = y;
        }
        return find(parent, source) == find(parent, destination);
    }
    
    int find(vector<int>& parent, int x){
        return parent[x] == x ? x : parent[x] = find(parent, parent[x]);
    }
};