// 3203. Find Minimum Diameter After Merging Two Trees

// Solution 1: BFS
// Time complexity: O(n + m)
// Space complexity: O(n + m)
class Solution {
public:
    // Build adjacency list
    vector<vector<int>> buildAdj(int size, vector<vector<int>>& edges) {
        vector<vector<int>> adj(size);
        for (auto edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        return adj;
    }
    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        int n = edges1.size() + 1, m = edges2.size() + 1;
        // Build adjacency list
        vector<vector<int>> adj1 = buildAdj(n, edges1), adj2 = buildAdj(m, edges2);
        // Find the diameter of the 2 trees and the combined diameter
        int d1 = helper(n, adj1), d2 = helper(m, adj2);
        // minimum combined diameter = ceil(d1/2) + ceil(d2/2) + 1
        // To get minimum diameter, we need to merge the 2 trees at the middle of the path (Centroid)
        // As diameter is the longest path between 2 nodes, the middle of the path is the centroid
        int combinedD = ceil(d1 / 2.0) + ceil(d2 / 2.0) + 1;
        // Return the maximum path as diameter is the longest path between 2 nodes
        // The minimum possible diameter after merge is the maximum of the 3 diameters (possible paths)
        return max({d1, d2, combinedD});
    }
    // Helper function to find the diameter of the tree using BFS
    // Start from 0 here but can start from any node
    int helper(int n, vector<vector<int>>& adj) {
        auto [farthestNode, _] = bfs(n, adj, 0);
        auto [_, diameter] = bfs(n, adj, farthestNode);
        return diameter;
    }
    // BFS to find the farthest node i.e., the diameter of the tree from the source node
    pair<int, int> bfs(int n, vector<vector<int>>& adj, int src){
        queue<int> q;
        vector<bool> visited(n, false);
        q.push(src);
        visited[src] = true;

        int maximumDistance = 0, farthestNode = src;
        while(!q.empty()){
            int sz = q.size();
            for(int i = 0; i < sz;i++){
                int curr = q.front();
                q.pop();
                farthestNode = curr;
                for (int neighbor : adj[curr]) {
                    if (!visited[neighbor]) {
                        visited[neighbor] = true;
                        q.push(neighbor);
                    }
                }
            }
            if (!q.empty()) maximumDistance++;
        }
        return {farthestNode, maximumDistance};
    }
};