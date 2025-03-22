#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#pragma GCC optimize("Ofast")


// Breadth First Search to find connected components
vector<int> bfs(int node,  vector<vector<int>>& adj, vector<bool>& visited){
    queue<int> q;
    q.push(node);
    visited[node] = true;
    vector<int> nodes;
    while(!q.empty()){
        auto u = q.front();
        q.pop();
        nodes.push_back(u);
        for(auto v : adj[u]){
            if(!visited[v]){
                q.push(v);
                visited[v] = true;
            }
        }
    }
    return nodes;
}


void solve() {
    int n, m, a, b;
    cin >> n >> m;
    vector<vector<int>> adj(n);
    for(int i = 0; i < m;i++){
        cin >> a >> b;
        adj[a-1].push_back(b-1);
        adj[b-1].push_back(a-1);
    }
    vector<bool> visited(n, false);
    int res = 0;
    vector<vector<int>> components;
    for(int i = 0; i < n;i++){
        if(!visited[i]){
            components.push_back(bfs(i, adj, visited));
            res++;
        }
    }
    cout<<res-1<<"\n";
    // Print the roads to connect the components
    for(int i = 1; i < res;i++)
        cout<<components[i][0]+1<<" "<<components[i-1][0]+1<<"\n";
}



int main() {
    ios_base::sync_with_stdio(false);
    int t = 1;
    // cin >> t;
    while(t--){
        solve();
    }
    return 0;
}




