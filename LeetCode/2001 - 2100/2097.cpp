// 2097. Valid Arrangement of Pairs

// Solution 1 using Eulerian Path
// Time complexity: O(v + e) => O(n^2)
// Space complexity: O(v + e) => O(n^2)
class Solution {
public:
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        unordered_map<int, deque<int>> adj;
        unordered_map<int, int> inDegree, outDegree;

        // Create adjacency list and calculate in and out degree
        for (const auto& pair : pairs) {
            adj[pair[0]].push_back(pair[1]);
            outDegree[pair[0]]++;
            inDegree[pair[1]]++;
        }

        vector<int> path;
        // DFS to find Eulerian Path
        function<void(int)> dfs = [&](int node) {
            while (!adj[node].empty()) {
                int nextNode = adj[node].front();
                adj[node].pop_front();
                dfs(nextNode);
            }
            path.push_back(node);
        };

        // Find start node such that outDegree[node] = inDegree[node] + 1
        int startNode = -1;
        for (const auto& [node, outCount] : outDegree) {
            if (outCount == inDegree[node] + 1) {
                startNode = node;
                break;
            }
        }

        // If no such node found, then find choose any node
        if (startNode == -1) {
            startNode = pairs[0][0];
        }

        dfs(startNode);
        // Reverse the path to get the correct order
        reverse(path.begin(), path.end());

        vector<vector<int>> result;
        // Create pairs from the path
        for (int i = 1; i < path.size(); ++i) {
            result.push_back({path[i - 1], path[i]});
        }

        return result;
    }
};