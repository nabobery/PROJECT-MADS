// 847. Shortest Path Visiting All Nodes
// DFS + Memoization (Top-Down DP) + Bit Manipulation
class Solution {
public:
    int endMask;
    int dp(int node, int mask,vector<vector<int>>& graph, vector<vector<int>>& cache){
        // as initially all are zero we return if state visited
        if(cache[node][mask] != 0)
            return cache[node][mask];
        // Base case - mask only has a single "1", which means
        // that only one node has been visited (the current node)
        if((mask & (mask-1)) == 0)
            return 0;
        // Avoid infinite loop in recursion
        cache[node][mask] = INT_MAX - 1;
        for(int neighbor : graph[node]){
            // if neighbor is not visited
            if((mask & (1 << neighbor)) != 0){
                // if already visited get the path length
                int visited = dp(neighbor,mask,graph,cache);
                // if not visited get the path length
                int notVisited = dp(neighbor,mask ^ (1 << node),graph,cache);
                // get the shorter path
                int better = min(visited,notVisited);
                // update the cache
                cache[node][mask] = min(cache[node][mask], 1 + better);
            }
        }
        return cache[node][mask];
    }

    int shortestPathLength(vector<vector<int>>& graph) {
        // get size
        int n = graph.size();
        // set ending mask as all are visited
        endMask = (1 << n) - 1;
        // initialize the dp array
        vector<vector<int>> cache(n+1, vector<int>(endMask+1,0));
        // setting shortest path length to INT_MAX initially
        int best = INT_MAX;
        // traversing all paths and find the shortest length
        for(int node = 0; node < n;node++){
            // updating best using best and the path with node as it's start
            best = min(best,dp(node,endMask,graph,cache));
        }
        return best;
    }
};
