// 2421. Number of Good Paths
class Solution {
public:
    vector <int> p, rank;
    int find(int x){
        if(p[x] != x){
            p[x] = find(p[x]);
        }
        return p[x];
    }
    void Union(int x, int y){
        x = find(x), y = find(y);
        if(x == y) return;
        else if (rank[x] < rank[y]){
            p[x] = y;
        }
        else if(rank[y] > rank[x]){
            p[y] = x;
        }
        else{
            p[y] = x;
            rank[x]++;
        }
    }
    int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
        int n = vals.size();
        vector<vector<int>> adj(n);
        p.resize(n);
        rank.resize(n,0);
        for(int i = 0;i < n;i++) p[i] = i;
        for(auto edge : edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        map<int, vector<int>> mp;
        for(int i = 0;i < n;i++){
            mp[vals[i]].push_back(i);
        }
        int result = 0;
        for(auto itr : mp){
            for(int node : itr.second){
                for(auto neighbor : adj[node]){
                    if(vals[node] >= vals[neighbor]){
                        Union(node, neighbor);
                    }
                }
            }
            unordered_map<int, int> components;
            for(int node : itr.second){
                components[find(node)]++;
            }
            for(auto it : components) result += (it.second *(it.second+1))/2;
        }
        return result;
    }
};

