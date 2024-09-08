// 947. Most Stones Removed with Same Row or Column

// Solution 1 using DFS
// Time complexity: O(n^2)
// Space complexity: O(n)
class Solution {
public:
    void dfs(int u, vector<unordered_set<int>>& adj, vector<bool>& visited, int& res){
        visited[u] = true;
        res++;
        for (auto v : adj[u]) {
            if (!visited[v]){
                dfs(v, adj, visited, res);
            }
        }
    }
    int helper(vector<unordered_set<int>>& adj){
        int n = adj.size();
        vector<bool> visited(n, false);
        int res = 0;
        for(int i = 0; i < n;i++){
            if(!visited[i]){
                dfs(i, adj, visited, res);
                res -= 1;
            }
        }
        return res;
    }
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        if(n < 2) return 0;
        unordered_map<int,set<int>> mp1, mp2;
        vector<unordered_set<int>> adj(n);
        for(int i = 0; i < n;i++){
            auto cord = stones[i];
            mp1[cord[0]].insert(i);
            mp2[cord[1]].insert(i);
        }
        for(auto it : mp1){
            for(auto i: it.second){
                for(auto j : it.second){
                    if(i != j){
                        adj[i].insert(j);
                        adj[j].insert(i);
                    }
                }
            }
        }
        for(auto it : mp2){
            for(auto i: it.second){
                for(auto j : it.second){
                    if(i != j){
                        adj[i].insert(j);
                        adj[j].insert(i);
                    }
                }
            }
        }
        return helper(adj);
    }
};

// Solution 2 using Union Find
// Time complexity: O(n^2)
// Space complexity: O(n)
class Solution {
public:
    vector<int> parent;
    int find(int x){
        if(parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }
    void unite(int x, int y){
        parent[find(x)] = find(y);
    }
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        if(n < 2) return 0;
        parent.resize(n);
        for(int i = 0; i < n;i++) parent[i] = i;
        for(int i = 0; i < n;i++){
            for(int j = i + 1; j < n;j++){
                if(stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1]){
                    unite(i,j);
                }
            }
        }
        int res = 0;
        for(int i = 0; i < n;i++){
            if(parent[i] == i) res++;
        }
        return n - res;
    }
};