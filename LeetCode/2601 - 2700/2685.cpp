// 2685. Count the Number of Complete Components

// Solution 1: BY finding components and check if they are complete or not
// Time complexity: O(n)
// Space complexity: O(n)
class Solution {
    public:
        // bfs to find the component
        vector<int> bfs(int u, vector<vector<int>>& adj, vector<bool>& visited){
            visited[u] = true;
            queue<int> q;
            q.push(u);
            vector<int> res;
            res.push_back(u);
            while(!q.empty()){
                auto curr = q.front();
                q.pop();
                for(auto v : adj[curr]){
                    if(!visited[v]){
                        visited[v] = true;
                        q.push(v);
                        res.push_back(v);
                    }
                }
            }
            return res;
        }
        // check if component is complete 
        bool isComplete(vector<int>& component, vector<vector<int>>& adj){
            int edges = component.size() - 1;
            for(auto& u : component){
                if(adj[u].size() < edges) return false;
            }
            return true;
        }
        int countCompleteComponents(int n, vector<vector<int>>& edges) {
            int res = 0;
            vector<bool> visited(n, false);
            vector<vector<int>> adj(n);
            vector<vector<int>> components;
            for(auto& edge : edges){
                adj[edge[0]].push_back(edge[1]);
                adj[edge[1]].push_back(edge[0]);
            }
            for(int i = 0; i < n;i++){
                if(!visited[i]){
                    components.push_back(bfs(i, adj, visited));
                }
            }
            for(auto& component : components){
                if(isComplete(component, adj)) res++;
            }
            return res;
        }
};

// Solution 2: BY doing it in one pass efficiently
// Time complexity: O(n)    
// Space complexity: O(n)
class Solution {
    public:
        int countCompleteComponents(int n, vector<vector<int>>& edges) {
            int res = 0;
            vector<bool> visited(n, false);
            vector<vector<int>> adj(n);
            vector<vector<int>> components;
            for(auto& edge : edges){
                adj[edge[0]].push_back(edge[1]);
                adj[edge[1]].push_back(edge[0]);
            }
            for(int i = 0; i < n;i++){
                if(!visited[i]){
                    queue<int> q;
                    q.push(i);
                    visited[i] = true;
                    vector<int> component;
                    component.push_back(i);
                    while(!q.empty()){
                        auto curr = q.front();
                        q.pop();
                        for(auto v : adj[curr]){
                            if(!visited[v]){
                                visited[v] = true;
                                q.push(v);
                                component.push_back(v);
                            }
                        }
                    }
                    int edges = component.size() - 1;
                    for(auto& u : component){
                        if(adj[u].size() < edges) {
                            res--;
                            break;
                        }
                    }
                    res++;
                }
            }
            return res;
        }
};