//  834. Sum of Distances in Tree

// Solution 1: DFS + DP
// Time complexity: O(n)
// Space complexity: O(n)
class Solution {
public:
    vector<int> res, count;
    vector<vector<int>> adj;
    int n;
    // count[i] = number of nodes in the subtree rooted at i
    // res[i] = sum of distances from i to all other nodes
    // Post-order traversal to calculate count and res
    // count[node] = sum of count[child] + 1
    // res[node] = sum of res[child] + count[child]
    void dfs(int node, int parent){
        for(int child: adj[node]){
            if(child == parent) continue;
            dfs(child, node);
            count[node] += count[child];
            res[node] += res[child] + count[child];
        }
    }
    // Pre-order traversal to calculate res
    // res[node] = res[parent] - count[node] + n - count[node]
    // The sum of distances from node to all other nodes is the sum of distances from parent to all other nodes - count[node] + n - count[node]
    void dfs2(int node, int parent){
        for(int child: adj[node]){
            if(child == parent) continue;
            res[child] = res[node] - count[child] + n - count[child];
            dfs2(child, node);
        }
    }
    vector<int> sumOfDistancesInTree(int N, vector<vector<int>>& edges) {
        n = N;
        adj.resize(N);
        res.resize(N, 0);
        count.resize(N, 1);
        for(auto edge: edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        dfs(0, -1);
        dfs2(0, -1);
        return res;
    }
};