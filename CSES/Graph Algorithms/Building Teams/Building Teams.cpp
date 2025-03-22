#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#pragma GCC optimize("Ofast")

// check if graph is bipartite
void solve() {
    int n, m, a, b;
    cin >> n >> m;
    vector<vector<int>> adj(n);
    for(int i = 0; i < m;i++){
        cin >> a >> b;
        adj[a-1].push_back(b-1);
        adj[b-1].push_back(a-1);
    }
    queue<int> q;
    vector<int> colors(n, -1);
    bool possible = true;
    for(int i = 0; i < n;i++){
        if(colors[i] == -1){
            colors[i] = 0;
            q.push(i);
            while(!q.empty()){
                auto curr = q.front();
                q.pop();
                for(auto v: adj[curr]){
                    if(colors[v] == -1){
                        q.push(v);
                        colors[v] = 1 - colors[curr];
                    }
                    else{
                        if(colors[curr] == colors[v]){
                            possible = false;
                            break;
                        }
                    }
                }
            }
        }
        if(!possible) break;
    }
    if(!possible) cout<<"IMPOSSIBLE\n";
    else{
        for(int& c : colors) cout<<c+1<<" ";
        cout<<"\n";
    }
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




