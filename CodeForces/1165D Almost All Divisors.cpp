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
    int n;
    ll x;
    cin >> n;
    set<int> d;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        d.insert(x);
    }
    x = *d.begin();
    x *= *d.rbegin();
    set<int> temp;
    for (int i = 2; i <= sqrt(x); i++)
    {
        if (x % i == 0)
        {
            temp.insert(x / i);
            temp.insert(i);
        }
    }
    if (temp == d)
        cout << x << "\n";
    else
        cout << "-1\n";
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