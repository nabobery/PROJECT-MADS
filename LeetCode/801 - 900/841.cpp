// 841. Keys and Rooms
// my dfs solution
class Solution {
public:
    void DFS(int v, vector<vector<int>>& adj, vector<bool>& visited){
        visited[v] = true;
        for(int u : adj[v]){
            if(!visited[u]){
                DFS(u,adj,visited);
            }
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<bool> visited(n,false);
        DFS(0,rooms,visited);
        for(bool b : visited){
            if(!b) return false;
        }
        return true;
    }
};
