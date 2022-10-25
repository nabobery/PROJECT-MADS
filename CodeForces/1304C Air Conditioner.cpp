#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#pragma GCC optimize("Ofast")

void solve()
{
    int n, m;
    cin >> n >> m;
    int min_t = m, max_t = m, prev = 0;
    int t[n], l[n], h[n];
    bool flag = true;
    for (int i = 0; i < n; i++)
        cin >> t[i] >> l[i] >> h[i];
    for (int i = 0; i < n; i++)
    {
        max_t += t[i] - prev;
        min_t -= t[i] - prev;
        if (max_t < l[i] || min_t > h[i])
        {
            flag = false;
            break;
        }
        max_t = min(max_t, h[i]);
        min_t = max(min_t, l[i]);
        prev = t[i];
    }
    cout << (flag ? "YES\n" : "NO\n");
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

