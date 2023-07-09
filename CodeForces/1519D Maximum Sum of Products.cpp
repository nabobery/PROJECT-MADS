#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <cmath>
#include <queue>
#include <cstdlib>
#include <algorithm>
// #include <cstring>
#include <stack>
using namespace std;

#pragma GCC optimize("Ofast")

#define ll long long int

void solve()
{
    int n;
    cin >> n;
    ll a[n], b[n], prefixsum[n + 1];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];
    prefixsum[0] = 0;
    for (int i = 1; i <= n; i++)
        prefixsum[i] = (a[i - 1] * b[i - 1] + prefixsum[i - 1]);
    ll result = prefixsum[n];
    // choosing the center of reversed subsegment
    for (int center = 0; center < n; center++)
    {
        // if the subsegment is of odd length
        ll temp = a[center] * b[center];
        // a1....ac-1acac+1...an
        // if we're reversing from c-1 to c+1, then we just have to add ac-1*bc+1 and ac+1*bc-1 and then keep on extending like that
        // after reversing between c-1 and c+1 we get (sum from 1 to c-2) + ac-1*bc+1 + ac+1*bc-1 + (sum from c+2 to n)
        for (int l = center - 1, r = center + 1; l >= 0 && r < n; l--, r++)
        {
            temp += a[l] * b[r];
            temp += a[r] * b[l];
            result = max(result, temp + prefixsum[l] + (prefixsum[n] - prefixsum[r + 1]));
        }
        // if the subsegment is of even length
        temp = 0;
        for (int l = center, r = center + 1; l >= 0 && r < n; l--, r++)
        {
            temp += a[l] * b[r];
            temp += a[r] * b[l];
            result = max(result, temp + prefixsum[l] + (prefixsum[n] - prefixsum[r + 1]));
        }
    }
    cout << result << "\n";
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