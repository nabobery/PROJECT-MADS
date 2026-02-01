// 2977. Minimum Cost to Convert String II

// Solution 1: Using Dynamic Programming 
// Time Complexity: O(N * M^2 + K^2 * log K) where N is length of source, M is max length of patterns, K is number of unique strings
// Space Complexity: O(N + K^2)
class Solution {
public:
    long long minimumCost(string source, string target, vector<string>& original, vector<string>& changed, vector<int>& cost) {
        int n = source.size();
        // Map each unique string to a unique ID
        unordered_map<string, int> strToId;
        auto getID = [&](const string& s) {
            if (strToId.find(s) == strToId.end()) {
                int id = strToId.size();
                strToId[s] = id;
            }
            return strToId[s];
        };

        // Assign IDs to all original and changed strings
        for (int i = 0; i < original.size(); ++i) {
            getID(original[i]);
            getID(changed[i]);
        }

        int numNodes = strToId.size();
        // Build the graph as adjacency list
        vector<vector<pair<int, int>>> adj(numNodes);
        for (int i = 0; i < original.size(); ++i) {
            adj[strToId[original[i]]].push_back({strToId[changed[i]], cost[i]});
        }

        // Compute the minimum transformation cost between all pairs using Dijkstra's algorithm
        vector<vector<long long>> minTransCost(numNodes, vector<long long>(numNodes, LLONG_MAX));
        for (int i = 0; i < numNodes; ++i) {
            priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
            minTransCost[i][i] = 0;
            pq.push({0, i});
            while (!pq.empty()) {
                auto [d, u] = pq.top(); pq.pop();
                if (d > minTransCost[i][u]) continue;
                for (auto& edge : adj[u]) {
                    int v = edge.first;
                    if (minTransCost[i][v] > d + edge.second) {
                        minTransCost[i][v] = d + edge.second;
                        pq.push({minTransCost[i][v], v});
                    }
                }
            }
        }

        vector<long long> dp(n + 1, LLONG_MAX);
        // Base case
        dp[n] = 0;

        // Dynamic Programming to find minimum cost to convert source to target
        // Iterate from the end of the string to the beginning
        for (int i = n - 1; i >= 0; --i) {
            // If characters match, no cost is needed
            if (source[i] == target[i]) {
                dp[i] = dp[i + 1];
            }
            
            // Try all possible patterns to match from current position
            for (auto const& [pattern, u] : strToId) {
                int len = pattern.size();
                // Check if the pattern matches the source at position i
                if (i + len <= n && source.compare(i, len, pattern) == 0) {
                    for (auto const& [replacement, v] : strToId) {
                        // Check if the replacement matches the target at position i
                        if (minTransCost[u][v] != LLONG_MAX && target.compare(i, len, replacement) == 0) {
                            // Update dp[i] if we can transform pattern to replacement
                            if (dp[i + len] != LLONG_MAX) {
                                dp[i] = min(dp[i], minTransCost[u][v] + dp[i + len]);
                            }
                        }
                    }
                }
            }
        }

        // Return the result if possible, otherwise -1
        return dp[0] == LLONG_MAX ? -1 : dp[0];
    }
};