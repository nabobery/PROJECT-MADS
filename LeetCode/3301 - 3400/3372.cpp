// 3372. Maximize the Number of Target Nodes After Connecting Trees I

// Solution 1: Using BFS
// Time Complexity: O(n^2)
// Space Complexity: O(n)
class Solution {
public:
    int bfs(int i, vector<vector<int>>& adj, int k){
        queue<int> q;
        int dist = 0, res = 1, n = adj.size();
        q.push(i);
        vector<bool> visited(n, false);
        visited[i] = true;
        while(!q.empty() && dist < k){
            int s = q.size();
            for(int i = 0; i < s;i++){
                auto u = q.front();
                q.pop();
                for(auto& v: adj[u]){
                    if(!visited[v]){
                        q.push(v);
                        res++;
                        visited[v] = true;
                    }
                }
            }
            dist++;
        }
        return res;
    }
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k) {
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
        for(int i  = 0; i < n;i++) res[i] = bfs(i, adj1, k);
        int mx = 0;
        for(int i  = 0; i < m;i++) mx = max(mx, bfs(i, adj2, k-1));
        for(int i = 0; i < n;i++){
            // cout<<res[i]<<" "<<mx<<"\n";
            if(k >= 1) res[i] += mx;
        }
        return res;
    }
};