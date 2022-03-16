// 207. Course Schedule
class Solution {
public:
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
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n = prerequisites.size();
        vector<vector <int>> adj(numCourses);
        for(int i = 0; i < n;i++)
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        if(isCyclic(adj, numCourses)){
            return false;
        }
        else{
            return true;
        }
    }
};