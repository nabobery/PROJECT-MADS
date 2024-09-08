// 1514. Path with Maximum Probability

// Solution 1 using BFS
// Time complexity: O(n + m)
// Space complexity: O(n + m)
class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        vector<vector<pair<int,double>>> adj(n);
        for(int i = 0; i < edges.size();i++){
            adj[edges[i][0]].push_back({edges[i][1], succProb[i]});
            adj[edges[i][1]].push_back({edges[i][0], succProb[i]});
        }
        vector<double> dist(n,0);
        dist[start_node] = 1;
        queue<pair<int,double>> q;
        q.push({start_node, 1});
        while(!q.empty()){
            auto curr = q.front();
            q.pop();
            for(auto chi: adj[curr.first]){
                if(dist[chi.first] < curr.second*chi.second){
                    dist[chi.first] = curr.second*chi.second;
                    q.push({chi.first, dist[chi.first]});
                }
            }
        }
        return dist[end_node];
    }
};