// 2467. Most Profitable Path in a Tree

// Solution 1 using DFS and BFS
// Time complexity: O(N)
// Space complexity: O(N)

// The idea is to find the path from bob node to 0 and store the steps in a map. 
// Then we can use DFS to find the most profitable path for Alice to reach leaf node.
// The DFS function will take the current node, current distance, amount array, current amount and visited set.
class Solution {
    public:
        unordered_map<int, vector<int>> adj;
        unordered_map<int,int> bobVisitedDist;
        int res;
        void dfs(int u, int currDist, vector<int>& amount, int currAmt, unordered_set<int>& vis){
            if(!bobVisitedDist.count(u)) currAmt += amount[u];
            else{
                int bobDist = bobVisitedDist[u];
                if(bobDist == currDist) currAmt += amount[u]/2;
                else if(bobDist > currDist) currAmt += amount[u];
            }
            vis.insert(u);
            bool isLeaf = true;
            for (int& v : adj[u]) {
                if (!vis.count(v)) {
                    isLeaf = false;
                    dfs(v, currDist + 1, amount, currAmt, vis);
                }
            }
            if (isLeaf) 
                res = max(res, currAmt);
    
        }
        int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
            int n = amount.size(), steps = 0;
            res = INT_MIN;
            for(auto& edge: edges){
                adj[edge[0]].push_back(edge[1]);
                adj[edge[1]].push_back(edge[0]);
            }
            unordered_map<int, int> parent;
            queue<int> q;
            q.push(bob);
            parent[bob] = -1; 
            while (!q.empty()) {
                int u = q.front();
                q.pop();
                if (u == 0) break;
    
                for (int& v : adj[u]) {
                    if (v != parent[u]) {
                        parent[v] = u;
                        q.push(v);
                    }
                }
            }
            int node = 0; 
            int dist = 0;
            while (node != -1) {
                bobVisitedDist[node] = dist++;
                node = parent[node]; 
            }
            for(auto& it: bobVisitedDist){
                it.second = bobVisitedDist.size() - it.second -1;
            }
            unordered_set<int> vis;
            dfs(0, 0, amount, 0, vis);
            return res;
        }
};