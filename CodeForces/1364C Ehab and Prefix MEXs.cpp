#include <iostream>
#include <vector>
#include <unordered_map>
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

bool vis[100005];

int a[100001], b[100001];

void solve()
{
    int n;
    cin >> n;
    memset(vis, false, sizeof(vis));
    memset(b, -1, sizeof(b));
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = n - 1; i > 0; i--)
    {
        if (a[i] > a[i - 1])
        {
            b[i] = a[i - 1];
            vis[a[i - 1]] = true;
        }
    }
    int p = 0;
    for (int i = 0; i < n; i++)
    {
        if (b[i] == -1)
        {
            while (vis[p])
            {
                p++;
            }
            if (p == a[n - 1])
                p++;
            b[i] = p;
            vis[p] = true;
        }
    }
    for (int i = 0; i < n; i++)
        cout << b[i] << " ";
    cout << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}