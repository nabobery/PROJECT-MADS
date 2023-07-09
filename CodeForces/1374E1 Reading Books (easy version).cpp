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
    int n, k;
    cin >> n >> k;
    vector<int> v, v01, v10;
    int t, a, b;
    for (int i = 0; i < n; i++)
    {
        cin >> t >> a >> b;
        if (a && b)
            v.push_back(t);
        else if (a && !b)
            v10.push_back(t);
        else if (!a && b)
            v01.push_back(t);
    }
    sort(v01.begin(), v01.end());
    sort(v10.begin(), v10.end());
    for (int i = 0; i < min(v01.size(), v10.size()); i++)
        v.push_back(v01[i] + v10[i]);
    if (v.size() < k)
        cout << "-1\n";
    else
    {
        sort(v.begin(), v.end());
        int result = 0;
        for (int i = 0; i < k; i++)
            result += v[i];
        cout << result << "\n";
    }
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