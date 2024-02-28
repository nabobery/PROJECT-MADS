// 1192. Critical Connections in a Network

// Solution 1 using Tarjan's algorithm
// Time complexity: O(V + E)
// Space complexity: O(V + E)
// We need to find the bridges in the graph which are the critical connections. We can use Tarjan's algorithm to find the bridges in the graph. The algorithm works as follows:
// The intuition behind the algorithm is that if we can reach a node v from a node u and we can't reach any node that can be reached from u from any other node, then the edge (u, v) is a critical connection. The algorithm works as follows:
// 1. We start from a node u and assign an id to it. We also assign a low value to it which is the lowest id of any node that can be reached from u.
// 2. We iterate through the neighbors of u. If a neighbor v is not visited, we visit it and run the algorithm on it. If v is visited, we update the low value of u.
// 3. If the id of u is less than the low value of v, then the edge (u, v) is a critical connection.
class Solution {
public:
    void dfs(int u, int parent, const vector<vector<int>>& adj, vector<int>& ids, vector<int>& low, vector<bool>& visited, vector<vector<int>>& result, int& id) {
        // set the id of the node u
        visited[u] = true;
        ids[u] = low[u] = id++;
        // iterate through the neighbors of u
        for (int v : adj[u]) {
            // if v is the parent of u, skip it
            if (v == parent) 
                continue;
            // if v is not visited, visit it
            if (!visited[v]) {
                // run dfs on v
                dfs(v, u, adj, ids, low, visited, result, id);
                // update the low[u] value
                low[u] = min(low[u], low[v]);
                // if the id of u is less than the low value of v, then the edge (u, v) is a critical connection
                if (ids[u] < low[v]) 
                    result.push_back({u, v});
            } 
            // if v is visited, update the low[u] value
            else low[u] = min(low[u], ids[v]);
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        // get the adjacency list of the graph
        vector<vector<int>> adj(n);
        for (const auto& connection : connections) {
            adj[connection[0]].push_back(connection[1]);
            adj[connection[1]].push_back(connection[0]);
        }
        // ids and low arrays for Tarjan's algorithm
        // ids[u] = the id of the node u
        // low[u] = the lowest id of any node that can be reached from u
        vector<int> ids(n, -1), low(n, -1);
        // visited array to keep track of visited nodes
        vector<bool> visited(n, false);
        // result array to store the critical connections
        vector<vector<int>> result;
        // id to keep track of the id of the nodes
        int id = 0;
        // run Tarjan's algorithm
        for (int i = 0; i < n; ++i) 
            if (!visited[i]) 
                dfs(i, -1, adj, ids, low, visited, result, id);
        return result;
    }
};