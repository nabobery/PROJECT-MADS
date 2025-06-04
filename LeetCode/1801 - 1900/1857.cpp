// 1857. Largest Color Value in a Directed Graph

// Solution 1: Using Coloring, DFS and indegree Count (TLE)
// This solution is not optimal and will likely result in a Time Limit Exceeded (TLE) error for larger inputs.
// Time Complexity: O(n*m) 
// Space Complexity: O(n + m)
class Solution {
public:
    int res;
    // Function to check if the directed graph has a cycle using Kahn's algorithm
    // O(n + m) time complexity, where n is the number of vertices and m is the number of edges
    bool isCyclicDirected(vector<vector<int>>& adj) {
        int V = adj.size();
        vector<int> indegree(V, 0);
        for (int u = 0; u < V; u++)
            for (int v : adj[u])
                indegree[v]++;

        queue<int> q;
        for (int i = 0; i < V; i++)
            if (indegree[i] == 0)
                q.push(i);

        int count = 0;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            count++;
            for (int v : adj[u]) {
                if (--indegree[v] == 0)
                    q.push(v);
            }
        }
        return (count != V);
    }

    // Helper function to perform DFS and count the maximum color value
    // starting from node i, using a map to count colors
    // O(m) time complexity for each DFS call, where m is the number of edges
    void helper(int i, string colors, vector<vector<int>>& adj,
                unordered_map<char, int>& cnt) {
        cnt[colors[i]]++;
        if (adj[i].empty()) {
            for (auto& it : cnt) {
                if (it.second > res) {
                    res = it.second;
                }
            }
            cnt[colors[i]]--;
            return;
        }
        for (auto& v : adj[i])
            helper(v, colors, adj, cnt);
        cnt[colors[i]]--;
    }

    // Main function to find the largest color value in a directed graph
    // It constructs the adjacency list, checks for cycles, and initiates DFS
    // from nodes with zero indegree, counting color occurrences
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n = colors.size();
        res = 0;
        vector<vector<int>> adj(n);
        vector<int> indegree(n, 0);
        for (auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            indegree[edge[1]]++;
        }
        if (isCyclicDirected(adj))
            return -1;
        for (int i = 0; i < n; i++) {
            if (!indegree[i]) {
                unordered_map<char, int> cnt;
                helper(i, colors, adj, cnt);
            }
        }
        return res;
    }
};

// Solution 2: Using DFS and Dynamic Programming
// This solution uses a topological sort approach to find the largest color value in a directed graph.
// Time Complexity: O(n + m) where n is the number of nodes and m is the number of edges
// Space Complexity: O(n + m) for the adjacency list and DP table
class Solution {
public:
    int n;
    vector<vector<int>> adj;
    string colors;
    vector<vector<int>> dp;
    vector<int> state;
    bool hasCycle = false;
    int answer = 0;

    // to detect if graph has cycle using DFS
    // state: 0 = unvisited, 1 = visiting, 2 = visited
    void detectCycle(int u) {
        state[u] = 1;
        for (int v : adj[u]) {
            if (state[v] == 0) {
                detectCycle(v);
                if (hasCycle) return;
            }
            else if (state[v] == 1) {
                hasCycle = true;
                return;
            }
        }
        state[u] = 2;
    }

    // to find the largest color value in the directed graph using DFS
    vector<int>& dfs(int u) {
        // if node u is already processed and has a valid dp value
        if (!dp[u].empty() && state[u] == 2)
            return dp[u];
        // else mark it as visiting
        state[u] = 1;
        // traverse all children of u
        for (int v : adj[u]) {
            // get the dp value of child v by processing it recursively
            auto& child = dfs(v);
            // update the dp value of u with the maximum color values from its children
            for (int c = 0; c < 26; c++)
                dp[u][c] = max(dp[u][c], child[c]);
        }
        // after processing all children, mark u as visited
        // and update the dp value for the color of u
        int myCol = colors[u] - 'a';
        dp[u][myCol] += 1;
        // update the global answer with the maximum color value found so far
        answer = max(answer, dp[u][myCol]);
        // mark u as fully processed
        state[u] = 2;
        // return the dp value for u
        return dp[u];
    }

    int largestPathValue(string _colors, vector<vector<int>>& edges) {
        colors = move(_colors);
        n = colors.size();
        // make adjacency list
        adj.assign(n, {});
        for (auto& e : edges)
            adj[e[0]].push_back(e[1]);
        state.assign(n, 0);
        // check if graph has cycle
        for (int i = 0; i < n; i++) {
            if (state[i] == 0) {
                detectCycle(i);
                if (hasCycle) return -1;
            }
        }
        // if no cycle, initialize dp and state arrays
        dp.assign(n, vector<int>(26, 0));
        state.assign(n, 0);
        for (int i = 0; i < n; i++)
            if (state[i] == 0)
                dfs(i);
        return answer;
    }
};