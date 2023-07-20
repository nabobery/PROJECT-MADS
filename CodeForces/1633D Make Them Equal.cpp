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

struct ds
{
    int moves, coins;
};

vector<set<int>> adj(1001);
int visited[1001];
bool visit[1001];

void helper()
{
    for (int i = 1; i <= 1000; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            adj[i].insert(i + i / j);
        }
    }
}

int bfs(int n)
{
    memset(visit, false, sizeof(visit));
    if (visited[n] != -1)
        return visited[n];
    queue<int> q;
    q.push(1);
    visit[1] = true;
    while (!q.empty())
    {
        int p = q.front();
        q.pop();
        if (p == n)
            return visited[p];
        for (auto it : adj[p])
        {
            if (it <= 1000 && !visit[it])
            {
                q.push(it);
                visit[it] = true;
                if (visited[it] == -1)
                    visited[it] = visited[p] + 1;
            }
        }
    }
    return 0;
}

void solve()
{
    int n, k;
    cin >> n >> k;
    ds arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i].moves;
    for (int i = 0; i < n; i++)
        cin >> arr[i].coins;
    memset(visited, -1, sizeof(visited));
    visited[1] = 0;
    for (int i = 0; i < n; i++)
        arr[i].moves = bfs(arr[i].moves);
    k = min(12 * n, k);
    vector<int> dp(k + 1, 0);
    for (int i = 1; i < n + 1; i++)
    {
        for (int w = k; w >= 0; w--)
        {
            if (arr[i - 1].moves <= w)
                dp[w] = max(dp[w], dp[w - arr[i - 1].moves] + arr[i - 1].coins);
        }
    }
    cout << dp[k] << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    helper();
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
