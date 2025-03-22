#include <iostream>
#include <vector>
using namespace std;

#pragma GCC optimize("Ofast")

#define ll long long int

// Floyd-Warshall's Algorithm
void solve() {
    int n, m, a, b, w, q;
    cin >> n >> m >> q;
    vector<vector<ll>> dist(n, vector<ll>(n, 1e12));
    for(int i = 0; i < n;i++) dist[i][i] = 0;
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> w;
        a--; b--;
        if(dist[a][b] > w)
            dist[a][b] = dist[b][a] = w;
    }
    for(int k = 0; k < n;k++){
        for(int i = 0; i < n;i++){
            for(int j = 0; j < n;j++){
                if(dist[i][k] + dist[k][j] < dist[i][j]) dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }

    int u, v;
    for(int i = 0; i < q;i++){
        cin >> u >> v;
        u--; v--;
        cout<<(dist[u][v] == 1e12 ? -1 : dist[u][v])<<"\n";
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


