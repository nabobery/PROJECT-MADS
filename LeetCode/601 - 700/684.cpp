// 684. Redundant Connection

// Solution 1 using BFS
// The idea is to remove each edge and check if the graph is connected or not
// Time Complexity: O(n^2)
// Space Complexity: O(n)
class Solution {
public:
    bool isConnected(vector<vector<int>>& edges, int index){
        int n = edges.size();
        vector<vector<int>> adj(n);
        for(int i = 0; i < n;i++){
            if(i != index){
                int u = edges[i][0], v = edges[i][1];
                adj[u-1].push_back(v-1);
                adj[v-1].push_back(u-1);
            }
        }
        vector<bool> visited(n, false);
        queue<int> q;
        q.push(0);
        visited[0] = true;
        while(!q.empty()){
            auto u = q.front();
            q.pop();
            for(int v : adj[u]){
                if(!visited[v]){
                    q.push(v);
                    visited[v] = true;
                }
            }
        }
        for(bool b : visited){
            if(!b) return false;
        }
        return true;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> res;
        for(int i = n-1; i >= 0;i--){
            if(isConnected(edges, i)){
                res = edges[i];
                break;
            }
        }
        return res;
    }
};


// Solution 2 using Union Find
// The idea is to use Union Find to check if the graph is connected or not and remove the duplicate edge if it already connected
// Time Complexity: O(nlogn)
// Space Complexity: O(n)
class UnionFind {
public:
    vector<int> parent;
    vector<int> rank;

    UnionFind(int size) : parent(size), rank(size, 0) {
        for (int i = 0; i < size; ++i)
            parent[i] = i;
    }

    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]); // Path compression
        return parent[x];
    }

    void unite(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);

        if (rootX != rootY) {
            // Union by rank
            if (rank[rootX] > rank[rootY])
                parent[rootY] = rootX;
            else if (rank[rootX] < rank[rootY])
                parent[rootX] = rootY;
            else {
                parent[rootY] = rootX;
                rank[rootX]++;
            }
        }
    }

    bool isConnected(int x, int y) {
        return find(x) == find(y);
    }
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        UnionFind uf(n + 1); 

        for (const auto& edge : edges) {
            int u = edge[0], v = edge[1];
            if (uf.isConnected(u, v)) {
                return {u, v}; 
            } else {
                uf.unite(u, v);
            }
        }

        return {}; 
    }
};