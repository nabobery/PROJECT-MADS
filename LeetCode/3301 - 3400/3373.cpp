// 3373. Maximize the Number of Target Nodes After Connecting Trees II

// Solution 1: Naive BFS Approach (TLE) count number of even and odd distance nodes from each node in the first tree, then find the maximum number of odd distance nodes from the second tree and add it to each node's count in the first tree.
// This solution is not optimal and will likely result in a Time Limit Exceeded (TLE) error for larger inputs.
// Time Complexity: O(n^2)
// Space Complexity: O(n)
class Solution {
public:
    int bfs(int i, vector<vector<int>>& adj, bool odd){
        queue<int> q;
        int dist = 0, res = odd, n = adj.size();
        q.push(i);
        vector<bool> visited(n, false);
        visited[i] = true;
        while(!q.empty()){
            int s = q.size();
            for(int i = 0; i < s;i++){
                auto u = q.front();
                q.pop();
                for(auto& v: adj[u]){
                    if(!visited[v]){
                        q.push(v);
                        if(dist%2 != odd) res++;
                        visited[v] = true;
                    }
                }
            }
            dist++;
        }
        return res;
    }
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        int n = edges1.size()+1, m = edges2.size()+1;
        vector<vector<int>> adj1(n), adj2(m);
        vector<int> res(n);
        for(auto& edge : edges1){
            adj1[edge[0]].push_back(edge[1]);
            adj1[edge[1]].push_back(edge[0]);
        }
        for(auto& edge : edges2){
            adj2[edge[0]].push_back(edge[1]);
            adj2[edge[1]].push_back(edge[0]);
        }
        for(int i  = 0; i < n;i++) res[i] = bfs(i, adj1, false);
        int mx = 0;
        for(int i  = 0; i < m;i++) mx = max(mx, bfs(i, adj2, true));
        for(int i = 0; i < n;i++){
            res[i] += mx;
        }
        return res;
    }
};


// Solution 2: Using DFS and Graph Coloring
// Time Complexity: O(n + m)
// Space Complexity: O(n + m)
class Solution {
public:
    // Helper function to perform DFS and color the graph with 2 colors (0, 1)
    void dfs_color(int u, int c, vector<int>& color, vector<vector<int>>& adj, array<int,2>& cnt) {
        // Color the current node and count the number of nodes in each color
        color[u] = c;
        cnt[c]++;
        for (int v : adj[u]) {
            // If the adjacent node is not colored, color it with the opposite color
            if (color[v] == -1) {
                // Recursively call dfs_color for the adjacent node with the opposite color
                dfs_color(v, c ^ 1, color, adj, cnt);
            }
        }
    }

    // color = 0 means even distance nodes, color = 1 means odd distance nodes
    // odd distance nodes to odd nodes and even distance nodes to even nodes gives even distance
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        int n = edges1.size() + 1;
        int m = edges2.size() + 1;
        // Create adjacency lists for both trees
        vector<vector<int>> adj1(n), adj2(m);
        for (auto& e : edges1) {
            adj1[e[0]].push_back(e[1]);
            adj1[e[1]].push_back(e[0]);
        }
        for (auto& e : edges2) {
            adj2[e[0]].push_back(e[1]);
            adj2[e[1]].push_back(e[0]);
        }
        // Initialize color arrays and counters for both trees
        // color1 and color2 will store the color of each node in the respective trees
        vector<int> color1(n, -1), color2(m, -1), res(n);
        // cnt1 and cnt2 will count the number of nodes in each color (0 and 1) for both trees
        array<int,2> cnt1 = {0,0}, cnt2 = {0,0};
        // Start DFS from the root node (0) for both trees
        dfs_color(0, 0, color1, adj1, cnt1);
        dfs_color(0, 0, color2, adj2, cnt2);
        // Calculate the maximum number of target nodes for each node in the first tree
        for (int i = 0; i < n; i++) {
            // For each node in the first tree, count the number of nodes at even distance from the give node
            // for color 0, we count the nodes with color 0, and for color 1, we count the nodes with color 1
            // The result for each node is the count of nodes with the same color as the node itself
            res[i] = cnt1[color1[i] ^ 0];
        }
        // get the maximum count of nodes with color 0 and color 1 in the second tree which will give us the maximum number of target nodes that can be added to each node in the first tree
        int mx2 = max(cnt2[0], cnt2[1]);
        for (int i = 0; i < n; i++) {
            res[i] += mx2;
        }
        return res;
    }
};