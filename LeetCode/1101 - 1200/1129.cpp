// 1129. Shortest Path with Alternating Colors

class Solution
{
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>> &redEdges, vector<vector<int>> &blueEdges)
    {
        vector<int> result(n, -1);
        vector<vector<bool>> vis(n, vector<bool>(2));
        vector<vector<pair<int, bool>>> adj(n);
        for (auto &edge : redEdges)
        {
            adj[edge[0]].push_back({edge[1], true});
        }
        for (auto &edge : blueEdges)
        {
            adj[edge[0]].push_back({edge[1], false});
        }
        queue<pair<int, bool>> q;
        q.push({0, true});
        q.push({0, false});
        int distance = 0;
        pair<int, bool> curr;
        vis[0][0] = vis[0][1] = true;
        while (!q.empty())
        {
            int s = q.size();
            for (int i = 0; i < s; i++)
            {
                curr = q.front();
                if (result[curr.first] == -1)
                    result[curr.first] = distance;
                q.pop();
                for (auto &node : adj[curr.first])
                {
                    if (curr.second != node.second && !vis[node.first][node.second])
                    {
                        q.push(node);
                        vis[node.first][node.second] = true;
                    }
                }
            }
            distance++;
        }
        return result;
    }
};