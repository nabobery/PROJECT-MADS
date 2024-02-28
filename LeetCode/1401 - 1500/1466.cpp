// 1466. Reorder Routes to Make All Paths Lead to the City Zero

// Solution 1 using dfs by treating it as an undirected graph and counting the edges that need to be reversed
// Time complexity: O(nlogn)
// Space complexity: O(nlogn)

class Solution {
public:
    int res;
    void dfs(int u, vector<vector<int>>& adj, set<pair<int,int>>& connections, vector<bool>& visited){
        visited[u] = true;
        for(int v : adj[u]){
            if(!visited[v]){
                if(connections.count({u,v})) res++;
                dfs(v, adj, connections, visited);
            }
        }
    }
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<int>> adj(n);
        set<pair<int,int>> s;
        for(auto& edge : connections){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
            s.insert({edge[0], edge[1]});
        }
        vector<bool> visited(n, false);
        res = 0;
        dfs(0, adj, s, visited);
        return res;
    }
};

// A better and cleaned up DFS Solution
// Time complexity: O(n)
// Space complexity: O(n)

class Solution {
public:
    int res;
    void dfs(int u, vector<vector<pair<int,int>>>& adj, vector<bool>& visited){
        visited[u] = true;
        for(auto& [v, w] : adj[u]){
            if(!visited[v]){
                if(w) res++;
                dfs(v, adj, visited);
            }
        }
    }
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<pair<int,int>>> adj(n);
        for(auto& edge : connections){
            adj[edge[0]].push_back({edge[1], 1});
            adj[edge[1]].push_back({edge[0], 0});
        }
        vector<bool> visited(n, false);
        res = 0;
        dfs(0, adj, visited);
        return res;
    }
};

// Solution 2 using BFS
// Time complexity: O(n)
// Space complexity: O(n)

class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<pair<int,int>>> adj(n);
        for(auto& edge : connections){
            adj[edge[0]].push_back({edge[1], 1});
            adj[edge[1]].push_back({edge[0], 0});
        }
        queue<int> q;
        vector<bool> visited(n, false);
        q.push(0);
        visited[0] = true;
        int res = 0;
        while(!q.empty()){
            int u = q.front();
            q.pop();
            for(auto& [v, w] : adj[u]){
                if(!visited[v]){
                    res += w;
                    visited[v] = true;
                    q.push(v);
                }
            }
        }
        return res;
    }
};