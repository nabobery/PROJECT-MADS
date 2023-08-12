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

void solve()
{
    int n, x, prev, p = 0;
    cin >> n;
    int h[n];
    h[0] = 0;
    cin >> x;
    for (int i = 1; i < n; i++)
    {
        cin >> x;
        if (i > 1 && x < prev)
            p++;
        h[i] = h[p] + 1;
        prev = x;
    }
    cout << h[n - 1] << "\n";
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
