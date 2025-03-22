#include <iostream>
#include <vector>

using namespace std;

#pragma GCC optimize("Ofast")

// check if graph has cycle
bool dfs(int curr, int parent, vector<vector<int>>& adj, vector<bool>& visited, vector<int>& path){
    visited[curr] = true;

    path.push_back(curr);

    for(auto neighbor: adj[curr]){
        if(neighbor == parent) continue;
        else{
            if(!visited[neighbor]){
                bool result = dfs(neighbor, curr, adj, visited, path);
                if(result) return true;
            }
            else{
                int index = -1;
                for(int i = 0; i < path.size();i++){
                    if(path[i] == neighbor){
                        index = i;
                        break;
                    }
                }
                cout<<path.size()-index+1<<"\n";
                for(int i = index;i < path.size();i++)
                    cout<<path[i]+1<<" ";
                cout<<neighbor+1<<"\n";
                return true;
            }
        }
    }
    path.pop_back();
    return false;
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
    bool possible = false;
    vector<bool> visited(n, false);
    for(int i = 0; i < n;i++){
        if(!visited[i]){
            vector<int> path;
            if(dfs(i, -1, adj, visited, path)){
                possible = true;
                break;
            }
        }
    }
    if(!possible) cout<<"IMPOSSIBLE\n";
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
