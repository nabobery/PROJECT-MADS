// 3108. Minimum Cost Walk in Weighted Graph

// Solution 1: Using Union Find
// Time Complexity: O(ElogE)
// Space Complexity: O(E)
// Idea: THe miniumum cost walk is always the and of all the edges in the connected components if u,v are in the same connected component.
// else, the minimum cost walk would be -1 because there is no way to reach u from v.
class DSU {
public:
    vector<int> parent;
    
    DSU(int n) {
        parent.resize(n);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }
    
    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }
    
    void unionn(int a, int b) {
        a = find(a);
        b = find(b);
        if(a != b) {
            parent[b] = a;
        }
    }
    
    bool connected(int a, int b) {
        return find(a) == find(b);
    }
};
    
class Solution {
public:
    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
        // First, build overall DSU to find connected components.
        DSU overall(n);
        for (auto &edge : edges) {
            overall.unionn(edge[0], edge[1]);
        }
        
        // For each component, compute the bitwise AND of all edge weights in it.
        // Initialize with all 31 bits set.
        const int ALL_ONES = (1 << 31) - 1; // This represents all ones in the lower 31 bits.
        unordered_map<int, int> compAnd; 
        // We iterate over every edge and update the component's AND value.
        for (auto &edge : edges) {
            int u = edge[0], v = edge[1], w = edge[2];
            int rep = overall.find(u);
            if (compAnd.find(rep) == compAnd.end())
                compAnd[rep] = ALL_ONES;
            compAnd[rep] &= w;
        }
        
        // Answer each query: if s and t are connected, return the AND value for their component;
        // otherwise return -1.
        vector<int> ans;
        for (auto &q : query) {
            int s = q[0], t = q[1];
            if (!overall.connected(s, t)) {
                ans.push_back(-1);
            } else {
                int rep = overall.find(s);
                ans.push_back(compAnd[rep]);
            }
        }
        return ans;
    }
};
    