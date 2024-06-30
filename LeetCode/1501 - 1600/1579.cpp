// 1579. Remove Max Number of Edges to Keep Graph Fully Traversable

// Solution 1 using Disjoint Set Union
// The idea is to build graph for Alice and Bob separately and then return the edges which are not needed
// Time complexity: O(nlogn)
// Space complexity: O(n)
class DSU { 
    int* parent; 
    int* rank; 
    int n;
  
public: 
    DSU(int n){  
        this->n = n;
        parent = new int[n]; 
        rank = new int[n]; 
        for (int i = 0; i < n; i++) { 
            parent[i] = -1; 
            rank[i] = 1; 
        } 
    } 
    int find(int i) { 
        if (parent[i] == -1) 
            return i; 
        return parent[i] = find(parent[i]); 
    } 
    void unite(int x, int y) { 
        int a = find(x), b = find(y); 
        if (a != b) { 
            if (rank[a] < rank[b])
                swap(a, b);
            parent[b] = a;
            if (rank[a] == rank[b])
                rank[a]++;        
        } 
    } 

    bool isConnected(){
        int cnt = 0;
        for(int i = 0;i < n;i++)
            if(parent[i] == -1) cnt++;
        return (cnt == 1);
    }
}; 

class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        DSU a(n), b(n);
        // res is the total number of edges - the number of edges which are needed
        int res = edges.size();
        // add type 3 edges first
        for(auto edge : edges){
            if(edge[0] == 3){
                int from = edge[1]-1, to = edge[2]-1;
                bool used = false;
                if(a.find(from) != a.find(to)){
                    a.unite(from, to);
                    used = true;
                }
                if(b.find(from) != b.find(to)){
                    b.unite(from, to);
                    used = true;
                }
                if(used) res--;
            }
        }
        // add type1 and type2 edges if required
        for(auto edge : edges){
            int from = edge[1]-1, to = edge[2]-1;
            if(edge[0] == 1){
                if(a.find(from) != a.find(to)){
                    a.unite(from, to);
                    res--;
                }
            }
            else if(edge[0] == 2){
                if(b.find(from) != b.find(to)){
                    b.unite(from, to);
                    res--;
                }
            }
        }
        // if both graphs are connected return the result else return -1
        if(a.isConnected() && b.isConnected()) return res;
        return -1;
    }
};


