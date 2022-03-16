// 310. Minimum Height Trees
class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n == 0){
            return {};
        }
        if(n == 1){
            return {0};
        }
        vector<int> degree(n,0), result;
        vector<vector<int>> adj(n);
        for(auto &e : edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
            degree[e[0]]++;
            degree[e[1]]++;
        }
        queue <int> q;
        for(int i = 0; i < n; i++){
            if(degree[i] == 1)
                q.push(i);
        }
        while(!q.empty()){
            result.clear();
            int s = q.size();
            for(int i = 0; i < s;i++){
                int curr = q.front();
                q.pop();
                result.push_back(curr);
                for(auto &neighbor : adj[curr]){
                    degree[neighbor]--;
                    if(degree[neighbor] == 1)
                        q.push(neighbor);
                }
            }
        }
        return result;
        
    }
};