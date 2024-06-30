// 2192. All Ancestors of a Node in a Directed Acyclic Graph

// Solution 1 using DFS by reversing the edges and using set to store ancestors
// Time Complexity: O(n^2logn)
// Space Complexity: O(n)
class Solution {
public:
    void dfs(int i, vector<vector<int>>& adj, vector<bool>& visited, vector<set<int>>& res){
        visited[i] = true;
        for(auto v : adj[i]){
            res[i].insert(v);
            if(!visited[v]) dfs(v, adj,visited,  res);
            res[i].insert(res[v].begin(), res[v].end());
        }
    }

    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n), res(n);
        vector<set<int>> temp(n);
        for(auto edge: edges) adj[edge[1]].push_back(edge[0]);
        vector<bool> visited(n, false);
        for(int i = 0; i < n;i++)
            if(!visited[i]) dfs(i, adj, visited, temp);
        for(int i = 0; i < n;i++) res[i] = vector<int>(temp[i].begin(), temp[i].end()); 
        return res;
    }
};

// Solution 2 using DFS without graph reversal and using vector to store ancestors
// Time Complexity: O(n^2 + nm)
// Space Complexity: O(n)
class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n), res(n);
        for(auto edge: edges) adj[edge[0]].push_back(edge[1]);
        for(int i = 0; i < n;i++)
            dfs(i, adj, i, res);
        return res;
    }
    void dfs(int i, vector<vector<int>>& adj, int node, vector<vector<int>>& res){
        for(auto v : adj[node]){
            if(res[v].empty() || res[v].back() != i){
                res[v].push_back(i);
                dfs(i, adj, v, res);
            }
        }
    }
};

// Solution 3 using BFS
// Time Complexity: O(n^2 + nm)
// Space Complexity: O(n)
class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n), res(n);
        for(auto edge: edges) adj[edge[0]].push_back(edge[1]);
        for(int i = 0; i < n;i++)
            bfs(i, adj, res);
        return res;
    }
    void bfs(int i, vector<vector<int>>& adj, vector<vector<int>>& res){
        queue<int> q;
        q.push(i);
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(auto v : adj[node]){
                if(res[v].empty() || res[v].back() != i){
                    res[v].push_back(i);
                    q.push(v);
                }
            }
        }
    }
};

// Solution 4 using Topological Sort(BFS) and Sorting the ancestors
// Time Complexity: O(n^2logn + nm)
// Space Complexity: O(n)
class Solution {
    public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n), res(n);
        vector<int> indegree(n, 0);
        for(auto edge: edges){
            adj[edge[0]].push_back(edge[1]);
            indegree[edge[1]]++;
        }
        queue<int> q;
        for(int i = 0; i < n;i++)
            if(indegree[i] == 0) q.push(i);
        vector<int> topoOrder;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            topoOrder.push_back(node);
            for(auto v : adj[node]){
                indegree[v]--;
                if(indegree[v] == 0) q.push(v);
            }
        }
        vector<set<int>> temp(n);
        for(int n : topoOrder){
            for(auto v : adj[n]){
                temp[v].insert(temp[n].begin(), temp[n].end());
                temp[v].insert(n);
            }
        }
        for(int i = 0; i < n;i++) res[i] = vector<int>(temp[i].begin(), temp[i].end());
        return res;
    }
};


