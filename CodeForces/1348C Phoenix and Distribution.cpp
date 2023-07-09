#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <cmath>
#include <queue>
#include <cstdlib>
#include <algorithm>
#include <cstring>
using namespace std;

#pragma GCC optimize("Ofast")

#define ll long long int

void solve()
{
    int n, k;
    string s;
    cin >> n >> k >> s;
    sort(s.begin(), s.end());
    if (s[0] != s[k - 1])
    {
        cout << s[k - 1] << "\n";
    }
    else
    {
        if (n == k)
            cout << s[0] << "\n";
        else if (s[k] == s[n - 1])
        {
            cout << s[0];
            for (int i = k; i < n; i += k)
            {
                cout << s[i];
            }
            cout << "\n";
        }
        else
            cout << s.substr(k - 1) << "\n";
    }
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