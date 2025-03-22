#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

#pragma GCC optimize("Ofast")

// find shortest path in unweighted graph using BFS from source 0 to destination n-1
// if there is no path from 0 to n-1, print "IMPOSSIBLE"
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
    queue<int> q;
    q.push(0);
    unordered_map<int, int> prev;
    visited[0] = true;
    prev[0] = -1;
    while(!q.empty()){
        auto curr = q.front();
        q.pop();
        if(curr == n-1)
            break;
        for(auto next: adj[curr]){
            if(!visited[next]){
                visited[next] = true;
                q.push(next);
                prev[next] = curr;
            }
        }
    }
    vector<int> result;
    if(!prev.count(n-1)) cout<<"IMPOSSIBLE\n";
    else {
        int curr = n-1;
        while(curr != -1) {
            result.push_back(curr);
            curr = prev[curr];
        }
        int res = result.size();
        cout<<res<<"\n";
        for(int i = res-1; i >= 0;i--) cout<<result[i]+1<<" ";
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




