// 2872. Maximum Number of K-Divisible Components

// Solution 1 using DFS
// Time complexity: O(n)
// Space complexity: O(n)
class Solution {
    public:
    int res;
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        vector<vector<int>> adj(n);
        for(auto& edge: edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        vector<bool> visited(n, false);
        res = 0;
        dfs(0, values, k, visited, adj);
        return res;
    }
    long long dfs(int node, vector<int>& values, int k, vector<bool>& visited, vector<vector<int>>& adj){
        visited[node] = true;
        long long sum = values[node];
        for(auto& neighbor: adj[node]){
            if(visited[neighbor]) continue;
            sum += dfs(neighbor, values, k, visited, adj);
        }
        if(sum % k == 0){
            res++;
            return 0;
        }
        return sum;
    }
};