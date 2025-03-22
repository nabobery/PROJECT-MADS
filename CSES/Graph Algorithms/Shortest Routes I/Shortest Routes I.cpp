#include <iostream>
#include <vector>
#include <cmath>
#include <queue>
#include <algorithm>
#include <climits>
using namespace std;

#pragma GCC optimize("Ofast")

#define ll long long int

// Dijkstra's Algorithm
void solve() {
    int n, m, a, b, w;
    cin >> n >> m;
    vector<vector<pair<int, int>>> adj(n);
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> w;
        adj[a - 1].emplace_back(b - 1, w);
    }
    vector<ll> dist(n, LLONG_MAX);
    priority_queue<pair<ll,int> , vector<pair<ll,int>>, greater<>> pq;
    dist[0] = 0;
    pq.emplace(0, 0);
    while(!pq.empty()){
        auto [d, u] = pq.top();
        pq.pop();
        if (d > dist[u]) continue;
        for (auto [v, w] : adj[u]) {
            if (d + w < dist[v]) {
                dist[v] = d + w;
                pq.emplace(dist[v], v);
            }
        }
    }
    for(int i = 0; i < n;i++) cout<<dist[i]<<" ";
    cout<<"\n";

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


