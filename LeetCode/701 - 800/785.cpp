// 785. Is Graph Bipartite?

// Solution 1 using BFS and coloring the nodes
// Time complexity: O(V + E)
// Space complexity: O(V)
class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, 0);
        for (int i = 0; i < n; i++) {
            if (color[i] == 0) {
                queue<int> q;
                q.push(i);
                color[i] = 1;
                while (!q.empty()) {
                    int u = q.front();
                    q.pop();
                    for (int v : graph[u]) {
                        if (color[v] == 0) {
                            color[v] = -color[u];
                            q.push(v);
                        } else if (color[v] == color[u]) {
                            return false;
                        }
                    }
                }
            }
        }
        return true;
    }
};

// Solution 2 using DFS and coloring the nodes and mainaining visited array
// Time complexity: O(V + E)
// Space complexity: O(V)
class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, 0);
        vector<bool> visited(n, false);
        for (int i = 0; i < n; i++) {
            if (!visited[i] && !dfs(graph, color, visited, i, 1)) {
                return false;
            }
        }
        return true;
    }
    bool dfs(vector<vector<int>>& graph, vector<int>& color, vector<bool>& visited, int u, int c) {
        visited[u] = true;
        color[u] = c;
        for (int v : graph[u]) {
            if (!visited[v]) {
                if (!dfs(graph, color, visited, v, -c)) {
                    return false;
                }
            } else if (color[v] == color[u]) {
                return false;
            }
        }
        return true;
    }
};



