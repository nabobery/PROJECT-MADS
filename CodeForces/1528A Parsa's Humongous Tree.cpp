#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <cmath>
#include <queue>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <stack>
using namespace std;

#pragma GCC optimize("Ofast")

#define ll long long int

int l = 1e5 + 2;

vector<vector<int>> adj(l);
vector<pair<int, int>> lr(l);
// dp[u][0] means max beauty with u as root and u is choosing lu as au
// dp[u][1] means max beauty with u as root and u is choosing ru as au
vector<vector<ll>> dp(l, vector<ll>(2));

void dfs(int u, int parent)
{
    // for all nodes adjacent to u
    for (int v : adj[u])
    {
        // if v is parent, then it's already traversed
        if (v == parent)
            continue;
        // perform dfs
        dfs(v, u);
    }
    // for all nodes adjacent to u
    for (int v : adj[u])
    {
        // if v is parent, then it's already traversed
        if (v == parent)
            continue;
        // max beauty when taking lu
        // Sum of max of beauty when taking either of lr values from v and it's calculated max beauty with v as the root
        dp[u][0] += max((abs(lr[u].first - lr[v].first) + dp[v][0]), (abs(lr[u].first - lr[v].second) + dp[v][1]));
        // max beauty when taking ru
        // Sum of max of beauty when taking either of lr values from v and it's calculated max beauty with v as the root
        dp[u][1] += max((abs(lr[u].second - lr[v].first) + dp[v][0]), (abs(lr[u].second - lr[v].second) + dp[v][1]));
    }
}

void solve()
{
    int n, u, v;
    cin >> n;
    // initialize max beauty to 0 and clear adjacency list for this test case
    for (int i = 1; i <= n; i++)
    {
        adj[i].clear();
        dp[i][0] = 0;
        dp[i][1] = 0;
    }
    // get lv and rv
    for (int i = 1; i <= n; i++)
        cin >> lr[i].first >> lr[i].second;
    // make a undirected graph
    for (int i = 1; i < n; i++)
    {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    // perform dfs
    dfs(1, -1);
    // print the max beauty when taking the root node's (1) a1 as l1 or r1
    cout << max(dp[1][0], dp[1][1]) << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}