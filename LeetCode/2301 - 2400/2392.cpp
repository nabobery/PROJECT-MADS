// 2392. Build a Matrix With Conditions

// Solution 1 using Topological Sort and DFS
// Time complexity: O(max(k^2, n)
// Space complexity: O(max(k^2, n)
// The idea is to build the matrix by using topological sort on the row and column conditions.
// We can build the matrix by iterating over the row order and column order and filling the matrix with the common elements.
// If there is a cycle in the graph, we return an empty matrix.
class Solution {
    public:
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        vector<int> row_order = topologicalSort(rowConditions, k);
        vector<int> col_order = topologicalSort(colConditions, k);
        if(row_order.empty() || col_order.empty()) return {};
        vector<vector<int>> matrix(k, vector<int>(k, 0));
        // build the matrix by iterating over the row order and column order and filling the matrix with the elements that satisfy both the row and column conditions
        for(int i = 0; i < k; i++) {
            for(int j = 0; j < k; j++) {
                if(row_order[i] == col_order[j]) {
                    matrix[i][j] = row_order[i];
                    break;
                }
            }
        }
        return matrix;
    }
    vector<int> topologicalSort(vector<vector<int>>& conditions, int k) {
        // order stores the topological order of the nodes
        vector<int> order(k, 0);
        //  adj stores the adjacency list of the graph
        vector<vector<int>> adj(k+1);
        // visited stores the visited status of the nodes
        vector<int> visited(k+1, 0);
        bool cycle = false;
        // build the adjacency list of the graph so that we can perform topological sort
        // node i comes before node j in the topological order if there is a condition i -> j
        for(auto& condition : conditions) 
           adj[condition[0]].push_back(condition[1]);
        // perform topological sort on the graph
        for(int i = 1; i <= k; i++) {
            // if the node is not visited, perform dfs on the node
            if(visited[i] == 0) {
                dfs(i, adj, visited, order, cycle);
                if(cycle) return {};
            }
        }
        // reverse the order to get the topological order
        reverse(order.begin(), order.end());
        return order;
    }
    // perform dfs on the node
    void dfs(int u, vector<vector<int>>& adj, vector<int>& visited, vector<int>& order, bool& cycle) {
        // mark the node as visited
        visited[u] = 1;
        // visit the neighbours of the node
        for(int v : adj[u]) {
            // if the neighbour is not visited, perform dfs on the neighbour
            if(visited[v] == 0) {
                dfs(v, adj, visited, order, cycle);
                if(cycle) return;
            } 
            // if the neighbour is already in the visiting state, there is a cycle in the graph
            else if(visited[v] == 1) {
                cycle = true;
                return;
            }
        }
        // mark the node as visited
        visited[u] = 2;
        order.push_back(u);
    }
};