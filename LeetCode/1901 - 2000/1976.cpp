// 1976. Number of Ways to Arrive at Destination

// Solution 1: Using Bellman Ford Algorithm and DP
// Time Complexity: O(E * V)
// Space Complexity: O(V)
class Solution {
    public:
        int mod = 1e9 + 7;
        int helper(int u, vector<vector<pair<int, int>>>& adj, vector<int>& dp) {
            int n = adj.size();
            if (u == n - 1)
                return 1;
            if (dp[u] != -1)
                return dp[u];
            dp[u] = 0;
            for (auto& [v, w] : adj[u])
                dp[u] = (dp[u] + helper(v, adj, dp)) % mod;
            return dp[u];
        }
        int countPaths(int n, vector<vector<int>>& roads) {
            // use bellman ford to find the shortest path from node 0 to all other nodes
            vector<long long> time(n, 1e14);
            time[0] = 0;
            for (int k = 1; k < n; k++) {
                for (auto& road : roads) {
                    int u = road[0], v = road[1], w = road[2];
                    if (time[u] != 1e14 && time[v] > time[u] + w)
                        time[v] = time[u] + w;
                    if (time[v] != 1e14 && time[u] > time[v] + w)
                        time[u] = time[v] + w;
                }
            }
            // create a dag from the shortest path
            vector<vector<pair<int, int>>> adj(n);
            for (auto& road : roads) {
                int u = road[0], v = road[1], w = road[2];
                if (time[v] == time[u] + w)
                    adj[u].push_back({v, w});
                if (time[u] == time[v] + w)
                    adj[v].push_back({u, w});
            }
            // find the number of ways to reach the destination using dp from node 0
            vector<int> dp(n, -1);
            return helper(0, adj, dp);
        }
};

// Solution 2: Using Dijkstra Algorithm and DP
// Time Complexity: O(E * log(V))
// Space Complexity: O(E)
class Solution {
    public:
        int mod = 1e9 + 7;
        int helper(int u, vector<vector<pair<int, int>>>& adj, vector<int>& dp) {
            int n = adj.size();
            if (u == n - 1)
                return 1;
            if (dp[u] != -1)
                return dp[u];
            dp[u] = 0;
            for (auto& [v, w] : adj[u])
                dp[u] = (dp[u] + helper(v, adj, dp)) % mod;
            return dp[u];
        }
        int countPaths(int n, vector<vector<int>>& roads) {
            vector<vector<pair<int, int>>> graph(n);
            for (auto& road : roads) {
                int u = road[0], v = road[1], w = road[2];
                graph[u].push_back({v, w});
                graph[v].push_back({u, w});
            }
    
            vector<long long> time(n, 1e14);
            time[0] = 0;
            priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
            pq.push({0, 0});
            
            while (!pq.empty()) {
                auto [currTime, u] = pq.top();
                pq.pop();
                if (currTime > time[u])
                    continue;
                for (auto& [v, w] : graph[u]) {
                    if (time[v] > currTime + w) {
                        time[v] = currTime + w;
                        pq.push({time[v], v});
                    }
                }
            }
            vector<vector<pair<int, int>>> adj(n);
            for (auto& road : roads) {
                int u = road[0], v = road[1], w = road[2];
                if (time[v] == time[u] + w)
                    adj[u].push_back({v, w});
                if (time[u] == time[v] + w)
                    adj[v].push_back({u, w});
            }
            vector<int> dp(n, -1);
            return helper(0, adj, dp);
        }
};