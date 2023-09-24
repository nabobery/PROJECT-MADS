// 1584. Min Cost to Connect All Points

// Solution1 Prim's Algorithm with Priority Queue (Min Heap)
// Prims seems to be faster than Kruskal's
// Time Complexity O(N^2logN)
// Space Complexity O(N^2)
class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<vector<pair<int,int>>> adj(n , vector<pair<int,int>>(n));
        for(int i = 0; i < n-1;i++){
            adj[i][i] = {i,0};
            for(int j = i+1; j < n;j++){
                int temp  = abs(points[i][1] - points[j][1]) + abs(points[i][0] - points[j][0]);
                adj[i][j] = {j, temp};
                adj[j][i] = {i, temp};
            }
        }
        priority_queue< pair<int,int>, vector <pair<int,int>> , greater<pair<int,int>> > pq;
        int src = 0;
        vector<int> key(n, 1e7);
        vector<bool> inMST(n, false);
        pq.push(make_pair(0, src));
        key[src] = 0;
        int result = 0;
        while (!pq.empty()){
            int u = pq.top().second;
            pq.pop();
            if(inMST[u] == true){
                continue;
            }
            inMST[u] = true;
            for (auto it : adj[u])
            {
                int v = it.first;
                int weight = it.second;
                if (inMST[v] == false && key[v] > weight)
                {
                    key[v] = weight;
                    pq.push(make_pair(key[v], v));
                }
            }
        }
        for(auto it : key) result += it;
        return result;
    }
};


// Solution2 Kruskal's Algorithm with Union Find
// Time Complexity O(N^2logN)
// Space Complexity O(N^2)
class Solution {
public:
    int find(vector<int>& parent, int i){
        if(parent[i] == -1) return i;
        return find(parent, parent[i]);
    }
    void Union(vector<int>& parent, int x, int y){
        int xset = find(parent, x);
        int yset = find(parent, y);
        if(xset != yset){
            parent[xset] = yset;
        }
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<vector<pair<int,int>>> adj(n , vector<pair<int,int>>(n));
        for(int i = 0; i < n-1;i++){
            adj[i][i] = {i,0};
            for(int j = i+1; j < n;j++){
                int temp  = abs(points[i][1] - points[j][1]) + abs(points[i][0] - points[j][0]);
                adj[i][j] = {j, temp};
                adj[j][i] = {i, temp};
            }
        }
        vector<int> parent(n, -1);
        vector<pair<int, pair<int,int>>> edges;
        for(int i = 0; i < n-1;i++){
            for(int j = i+1; j < n;j++){
                edges.push_back({adj[i][j].second, {i,j}});
            }
        }
        sort(edges.begin(), edges.end());
        int result = 0;
        for(auto it : edges){
            int u = it.second.first;
            int v = it.second.second;
            int set_u = find(parent, u);
            int set_v = find(parent, v);
            if(set_u != set_v){
                result += it.first;
                Union(parent, set_u, set_v);
            }
        }
        return result;
    }
};