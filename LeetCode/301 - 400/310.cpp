// 310. Minimum Height Trees

// A graph can have atmost 2 MHTs (Minimum Height Trees). 1 MHT if the number of nodes on the longest path is odd and 2 MHTs if the number of nodes on the longest path is even.
// The MHTs will be the center of the graph. The center of the graph is the middle node or nodes of the longest path in the graph.

// Solution 1 Naive Approach by finding height using BFS by taking each node as the root
// Time complexity: O(n^2)
// Space complexity: O(n)
class Solution {
public:
    map<int, vector<int>> mp;
    void bfs(int src, vector<vector<int>>& adj){
        queue<int> q;
        int res = 0;
        vector<bool> visited(adj.size(), false);
        q.push(src);
        while(!q.empty()){
            int s = q.size();
            for(int i = 0; i < s;i++){
                int curr = q.front();
                visited[curr] = true;
                q.pop();
                for(int n : adj[curr])
                    if(!visited[n]) q.push(n);
            }
            res++;
        }
        mp[res].push_back(src);
    }
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for(auto& edge : edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        for(int i = 0; i < n;i++) bfs(i, adj);
        return mp.begin()->second;
    }
};

// Solution 2 Using 2 time DFS and finding the middle nodes of the longest path
// Time complexity: O(n)
// Space complexity: O(n)
// The idea is to find the longest path in the graph and then find the middle nodes of the longest path 
// The middle nodes of the longest path will be the root of the Minimum Height Trees
// The longest path can be found by performing DFS from any node and then performing DFS from the node which is at the end of the longest path
// The path between the two nodes will be the longest path i.e the diameter of the tree. We can find the diameter of the tree by finding the longest path between 2 leaf nodes of the tree
// move is used to move the ownership of the vector from one variable to another and avoid copying and MLE
class Solution {
public:
    vector<vector<int>> adj;
    vector<bool> visited;
    vector<int> helper(int src){
        vector<int> longestPath, currPath;
        visited[src] = true;    
        for(int n : adj[src]){
            if(!visited[n]){
                currPath = helper(n);
                if(currPath.size() > longestPath.size())
                    longestPath = move(currPath);
            }
        }
        visited[src] = false;
        longestPath.push_back(src);
        return longestPath;
    }
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        adj.resize(n);
        visited.resize(n, false);
        for(auto& edge : edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        vector<int> longestPath = helper(helper(0)[0]);
        int len = longestPath.size();
        if(len % 2 == 0)
            return {longestPath[len/2], longestPath[len/2 - 1]};    
        return {longestPath[len/2]};
    }
};

// Solution 3 Using Topological Sort and BFS
// Time complexity: O(n)
// Space complexity: O(n)
class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        // If there is only one node, return it
        if(n == 1)
            return {0};
        // Create a vector to store the degree of each node
        vector<int> degree(n,0), result;
        vector<vector<int>> adj(n);
        // Create adjacency list and degree of each node
        for(auto &e : edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
            degree[e[0]]++;
            degree[e[1]]++;
        }
        // Create a queue to store the leaf nodes
        queue <int> q;
        for(int i = 0; i < n; i++)
            if(degree[i] == 1)
                q.push(i);
        // Perform BFS
        while(!q.empty()){
            result.clear();
            int s = q.size();
            // Store the leaf nodes in the result vector and reduce the degree of its neighbors by 1 and push them to the queue if their degree becomes 1
            // This will help in finding the next level of leaf nodes
            // Continue this process until we have only 2 or less nodes left
            for(int i = 0; i < s;i++){
                int curr = q.front();
                q.pop();
                result.push_back(curr);
                for(auto &neighbor : adj[curr]){
                    degree[neighbor]--;
                    if(degree[neighbor] == 1)
                        q.push(neighbor);
                }
            }
        }
        return result;  
    }
};

