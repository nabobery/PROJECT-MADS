// 1376. Time Needed to Inform All Employees

// Solution 1 using BFS(Level Order Traversal)
// Time Complexity: O(n)
// Space Complexity: O(n)
class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<vector<int>> adj(n);
        for(int i = 0; i < n;i++)
            if(manager[i] != -1) adj[manager[i]].push_back(i);
        queue<pair<int,int>> q;
        q.push({headID, 0});
        int res = 0;
        while(!q.empty()){
            int s = q.size();
            for(int i = 0; i < s;i++){
                auto curr = q.front();
                res = max(res, curr.second);
                q.pop();
                for(auto node : adj[curr.first])
                    q.push({node, curr.second+informTime[curr.first]});
            }
        }
        return res;
    }
};

// Solution 2 using DFS
// Time Complexity: O(n)
// Space Complexity: O(n)
class Solution {
public:
    int dfs(int headID, vector<vector<int>>& adj, vector<int>& informTime){
        int res = 0;
        for(auto node : adj[headID])
            res = max(res, dfs(node, adj, informTime));
        return res + informTime[headID];
    }
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<vector<int>> adj(n);
        for(int i = 0; i < n;i++)
            if(manager[i] != -1) adj[manager[i]].push_back(i);
        return dfs(headID, adj, informTime);
    }
};