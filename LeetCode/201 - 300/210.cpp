// 210. Course Schedule II
class Solution {
public:
    // Graph Coloring(0 means unvisited, 1 means visiting, 2 means visited)
    bool helper(vector<vector<int>> &adj,vector<int>& visited, int v){
        if(visited[v] == 1)
            return true;
        if(visited[v] == 2)
            return false;
        visited[v] = 1;
        for(int i = 0; i < adj[v].size();i++){
            if(helper(adj,visited,adj[v][i])){
                return true;
            }
        }
        visited[v] = 2;
        return false;
    }
    // Cycle detection
    bool isCyclic(vector<vector<int>> &adj, int n){
        vector<int> visited(n,0);
        for(int i = 0; i < n; i++){
            if(!visited[i]){
                if(helper(adj,visited,i)){
                    return true;
                }
            }
        }
        return false;      
    }
    void dfs(vector<vector<int>> &adj, int v, vector<bool>& visited, stack<int>& stk){
        // mark true as we've visited now
        visited[v] = true;
        // check if the neighbour are visted or not and apply dfs(recurse)
        for(int i = 0; i < adj[v].size();i++){
            if(!visited[adj[v][i]]){
                dfs(adj,adj[v][i],visited, stk);
            }
        }
        // if no more outgoing edges or neighbours, push the node to stack
        stk.push(v);
    }
    
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int n = prerequisites.size();
        vector<vector int>> adj(numCourses);
        // Make Adjacency list
        for(int i = 0; i < n;i++)
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        vector<int> result;
        // check if the graph is cyclic or not
        if(isCyclic(adj, numCourses)){
            return result;
        }
        stack<int> stk;
        vector<bool> visited(numCourses, false);
        // topological sorting using dfs and stack
        for(int i = 0; i < numCourses; i++){
            if(!visited[i]){
                dfs(adj,i,visited, stk);
            }
        }
        // get the resultant ordering
        while(!stk.empty()){
            result.push_back(stk.top());
            stk.pop();
        }
        return result;      
    }
};
