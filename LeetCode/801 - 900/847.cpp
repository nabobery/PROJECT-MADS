// 847. Shortest Path Visiting All Nodes

// Solution 1
// DFS + Memoization (Top-Down DP) + Bit Manipulation
class Solution {
public:
    int endMask;
    int dp(int node, int mask,vector<vector<int>>& graph, vector<vector<int>>& cache){
        // as initially all are zero we return if state visited and return the best path length
        if(cache[node][mask] != 0)
            return cache[node][mask];
        // Base case - mask only has a single "1", which means that only one node is left (the current node)
        // so we return 0 as we don't need to visit any other node
        if((mask & (mask-1)) == 0)
            return 0;
        // Avoid infinite loop in recursion
        cache[node][mask] = INT_MAX - 1;
        for(int neighbor : graph[node]){
            // if neighbor is not visited we check using bitwise and
            if((mask & (1 << neighbor)) != 0){
                // not marking as visited and visiting other nodes by starting from neighbor
                int visited = dp(neighbor,mask,graph,cache);
                // marking as visited and visiting other nodes
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
        // number of states/paths possible = 2^n and we need to represent so we need 2^n-1 numbers
        // set ending mask as the state where all nodes are visited
        // 1111 for 4 nodes
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

// Solution 2
// BFS + Bit Manipulation
class Solution {
public:
    // class to store current state
    class State{
        public:
        // node - current node
        int node;
        // mask - to check if all nodes are visited
        int mask;
        // dist - distance travelled
        int dist;
        State(int node, int mask, int dist){
            this->node = node;
            this->mask = mask;
            this->dist = dist;
        }
    };
    int shortestPathLength(vector<vector<int>>& graph){
        // get size
        int n = graph.size();
        // set ending mask as the state where all nodes are visited
        int endMask = (1 << n) - 1;
        // boolean array to check if the current state is visited or not
        vector<vector<bool>> visited(n,vector<bool>(endMask+1,false));
        // queue to store the current state
        queue<State> q;
        // traversing all nodes and adding them to queue
        for(int node = 0; node < n; node++){
            q.push(State(node,1 << node,0));
            visited[node][1 << node] = true;
        }
        // traversing the queue
        while(!q.empty()){
            // get the current state
            State curr = q.front();
            q.pop();
            // if all nodes are visited return the distance travelled
            if(curr.mask == endMask)
                return curr.dist;
            // traversing all neighbors
            for(int neighbor : graph[curr.node]){
                // if neighbor is not visited
                if(!visited[neighbor][curr.mask | (1 << neighbor)]){
                    // mark as visited
                    visited[neighbor][curr.mask | (1 << neighbor)] = true;
                    // add to queue
                    q.push(State(neighbor,curr.mask | (1 << neighbor),curr.dist + 1));
                }
            }
        }
        return -1;
    }
};
