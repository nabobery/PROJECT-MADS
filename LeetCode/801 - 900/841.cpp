// 841. Keys and Rooms

// Solution 1 usign DFS
// Time Complexity: O(V + E)
// Space Complexity: O(V)
class Solution {
public:
    void dfs(int u, vector<vector<int>>& adj, vector<bool>& visited){
        visited[u] = true;
        for(int v : adj[u])
            if(!visited[v]) dfs(v, adj, visited);
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<bool> visited(n, false);
        dfs(0, rooms, visited);
        for(bool b : visited)
            if(!b) return false;
        return true;
    }
};

// Solution 2 using BFS
// Time Complexity: O(V + E)
// Space Complexity: O(V)
class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<bool> visited(n, false);
        queue<int> q;
        q.push(0);
        visited[0] = true;
        while(!q.empty()){
            int u = q.front();
            q.pop();
            for(int v : rooms[u]){
                if(!visited[v]){
                    visited[v] = true;
                    q.push(v);
                }
            }
        }
        for(bool b : visited)
            if(!b) return false;
        return true;
    }
};