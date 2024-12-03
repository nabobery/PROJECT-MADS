// 3243. Shortest Distance After Road Addition Queries I

// Solution 1: BFS
// Time complexity: O(n*q)
// Space complexity: O(n)
class Solution {
public:
    int bfs(vector<vector<int>>& adj){
        int n = adj.size();
        queue<int> q;
        vector<bool> visited(n, false);
        q.push(0);
        visited[0] = true;
        int dist = 0;
        while(!q.empty()){
            int s = q.size();
            for(int i = 0; i < s;i++){
                auto curr = q.front();
                q.pop();
                if(curr == n-1) return dist;
                for(auto node: adj[curr]){
                    if(!visited[node]){
                        q.push(node);
                        visited[node] = true;
                    }
                }
            }
            dist++;
        }
        return -1;
    }
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> adj(n);
        for(int i = 0; i < n-1;i++)
            adj[i].push_back(i+1);
        int q = queries.size();
        vector<int> res(q);
        for(int i = 0; i < q;i++){
            adj[queries[i][0]].push_back(queries[i][1]);
            res[i] = bfs(adj);
        }
        return res;
    }
};