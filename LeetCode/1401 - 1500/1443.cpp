// 1443. Minimum Time to Collect All Apples in a Tree

class Solution {
public:
    int helper(int n, int p, vector<vector<int>>& adj, vector<bool>& hasApple){
        int total = 0, child = 0;
        for(auto c : adj[n]){
            if(c == p) continue;
            child = helper(c, n,adj,hasApple);
            if(child || hasApple[c]) total += child+2;
        }
        return total;
    }

    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vector<vector<int>> adj(n);
        for(auto edge : edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        return helper(0,-1,adj,hasApple);
    }
};
