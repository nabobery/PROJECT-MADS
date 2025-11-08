// 3607. Power Grid Maintenance

// Solution 1 using BFS, Set and HashMap
// Time Complexity: O(C^2 + C + QlogC)
// Space Complexity: O(C^2)
class Solution {
public:
    set<int> bfs(int i, vector<vector<int>>& adj){
        set<int> visited;
        visited.insert(i);
        queue<int> q;
        q.push(i);
        while(!q.empty()){
            auto curr = q.front();
            q.pop();
            for(auto& neighbor: adj[curr]){
                if(!visited.count(neighbor)){
                    q.push(neighbor);
                    visited.insert(neighbor);
                }
            }
        }
        return visited;
    }
    vector<int> processQueries(int c, vector<vector<int>>& connections, vector<vector<int>>& queries) {
        vector<int> res;
        unordered_map<int,set<int>> gridToOnlineStations;
        vector<int> stationToGrid(c, -1);
        vector<vector<int>> adj(c);
        vector<bool> onlineStations(c, true);
        for(auto&connection : connections){
            int u = connection[0]-1, v = connection[1] - 1;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int q = queries.size(), grid = 1;
        for(int i = 0; i < c;i++){
            if(stationToGrid[i] == -1){
                set<int> stations = bfs(i, adj);
                gridToOnlineStations[grid] = stations;
                for(auto& station: stations) stationToGrid[station] = grid;
                grid++;
            }
        }
        for(int i = 0; i < q;i++){
            int op = queries[i][0], x = queries[i][1];
            if(op == 1){
                if(onlineStations[x-1]) res.push_back(x);
                else{
                    int grid = stationToGrid[x-1];
                    if(gridToOnlineStations[grid].empty()) res.push_back(-1);
                    else{
                        auto it = gridToOnlineStations[grid].begin();
                        res.push_back(*it +1);
                    }
                }
            }
            else{
                onlineStations[x-1] = false;
                gridToOnlineStations[stationToGrid[x-1]].erase(x-1);
            }
        }
        return res;
    }
};

// Solution 2 using Union Find
// Time Complexity: O((C + Q) α(C)) where α is the Inverse Ackermann function
// Space Complexity: O(C) 
/**
 * @brief A standard Union-Find (Disjoint Set Union) data structure.
 * It uses path compression and union by size for optimization.
 */
class DSU {
private:
    vector<int> parent;
    vector<int> sz; // 'sz' stores the size of the component

public:
    // Initialize DSU for 'n' elements, each in its own set.
    DSU(int n) {
        parent.resize(n);
        // std::iota fills the array with 0, 1, 2, ...
        iota(parent.begin(), parent.end(), 0);
        sz.assign(n, 1);
    }

    /**
     * @brief Find the representative (root) of the set containing element 'i'.
     * Uses path compression.
     */
    int find(int i) {
        if (parent[i] == i)
            return i;
        // Path compression
        return parent[i] = find(parent[i]);
    }

    /**
     * @brief Unite the sets containing elements 'i' and 'j'.
     * Uses union by size.
     */
    void unite(int i, int j) {
        int root_i = find(i);
        int root_j = find(j);
        if (root_i != root_j) {
            // Attach the smaller tree to the root of the larger tree
            if (sz[root_i] < sz[root_j])
                swap(root_i, root_j);
            parent[root_j] = root_i;
            sz[root_i] += sz[root_j];
        }
    }
};

class Solution {
public:
    vector<int> processQueries(int c, vector<vector<int>>& connections, vector<vector<int>>& queries) {
        // --- Initialization ---

        // 1. Use DSU to find all connected components (grids).
        // The DSU structure will handle all 'c' stations (0 to c-1).
        DSU dsu(c);
        for (auto& connection : connections) {
            // Problem is 1-indexed, our DSU is 0-indexed
            int u = connection[0] - 1;
            int v = connection[1] - 1;
            dsu.unite(u, v);
        }

        // 2. Track online stations.
        // We still need your 'onlineStations' vector for O(1) checks.
        vector<bool> onlineStations(c, true);

        // 3. Map each grid (represented by its DSU root) to its set of
        //    *currently online* stations.
        //    std::set automatically keeps elements sorted, so .begin()
        //    is always the smallest station ID.
        unordered_map<int, set<int>> gridToOnlineStations;
        for (int i = 0; i < c; ++i) {
            int grid_root = dsu.find(i);
            gridToOnlineStations[grid_root].insert(i);
        }

        vector<int> res;

        // --- Query Processing ---

        for (auto& query : queries) {
            int op = query[0];
            // Convert to 0-based indexing for internal logic
            int x = query[1] - 1; 

            if (op == 1) {
                // --- Type 1 Query: Maintenance Check ---
                if (onlineStations[x]) {
                    // Station is online, resolves by itself.
                    // Convert back to 1-based index for result.
                    res.push_back(x + 1);
                } else {
                    // Station is offline. Find the smallest online station in its grid.
                    int grid_root = dsu.find(x);
                    
                    if (gridToOnlineStations[grid_root].empty()) {
                        // No stations are online in this grid.
                        res.push_back(-1);
                    } else {
                        int smallest_online_station = *gridToOnlineStations[grid_root].begin();
                        // Convert back to 1-based index for result.
                        res.push_back(smallest_online_station + 1);
                    }
                }
            } else {
                // --- Type 2 Query: Go Offline ---
                
                // Only process if it's not already offline
                if (onlineStations[x]) {
                    onlineStations[x] = false;
                    int grid_root = dsu.find(x);
                    
                    // Remove the station from its grid's set of *online* stations.
                    // .erase() is O(logN) where N is the set size.
                    gridToOnlineStations[grid_root].erase(x);
                }
            }
        }

        return res;
    }
};