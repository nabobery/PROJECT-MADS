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

void solve()
{
    int n, m, k, x, y;
    cin >> n >> m >> k;
    for (int i = 0; i < 2 * k; i++)
    {
        cin >> x >> y;
    }
    cout << n * m + n + m - 3 << "\n";
    for (int i = 1; i < n; i++)
        cout << "U";
    for (int i = 1; i < m; i++)
        cout << "L";
    for (int i = 0; i < n; i++)
    {
        if (i % 2)
        {
            for (int j = 1; j < m; j++)
                cout << "L";
        }
        else
        {
            for (int j = 1; j < m; j++)
                cout << "R";
        }
        if (i != n - 1)
            cout << "D";
    }
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