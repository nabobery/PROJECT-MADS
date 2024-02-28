// 1129. Shortest Path with Alternating Colors

// Solution 1 using BFS and queue
// Time complexity: O(n + e) where n is the number of nodes and e is the number of edges
// Space complexity: O(n + e)
class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<int> res(n, -1);
        res[0] = 0;
        vector<vector<bool>> vis(n, vector<bool>(2, false));
        vector<vector<pair<int,bool>>> adj(n);
        for(auto& edge : redEdges) adj[edge[0]].push_back({edge[1], false});
        for(auto& edge : blueEdges) adj[edge[0]].push_back({edge[1], true});
        queue<pair<int, bool>> q;
        q.push({0, false});
        q.push({0, true});
        vis[0][0] = vis[0][1] = true;
        int dis = 0;
        while(!q.empty()){
            int s = q.size();
            for(int i = 0; i < s;i++){
                auto curr = q.front();
                q.pop();
                if(res[curr.first] == -1) res[curr.first] = dis; 
                for(auto& neighbour : adj[curr.first]){
                    if(curr.second != neighbour.second && !vis[neighbour.first][neighbour.second]){
                        q.push(neighbour);
                        vis[neighbour.first][neighbour.second] = true;
                    }
                }
            }
            dis++;
        }
        return res;
    }
};