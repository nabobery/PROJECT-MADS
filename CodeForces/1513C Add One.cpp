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

const int l = 2 * 1e5 + 10, mod = 1e9 + 7;

ll dp[l];

void helper()
{
    ll count[10], tempcount[10];
    for (int i = 0; i < 10; i++)
    {
        dp[i] = 1;
        count[i] = 0;
        tempcount[i] = 0;
    }
    dp[10] = 2;
    tempcount[1] = 1, tempcount[0] = 1;
    for (int i = 11; i < l; i++)
    {
        for (int j = 1; j < 10; j++)
        {
            count[j] = tempcount[j - 1] % mod;
        }
        count[0] = tempcount[9];
        count[1] += tempcount[9] % mod;
        count[1] %= mod;
        dp[i] = 0;
        for (int j = 0; j < 10; j++)
        {
            dp[i] += ((count[j] % mod) * dp[j]);
            dp[i] %= mod;
            tempcount[j] = count[j];
        }
    }
}

void solve()
{
    int n, m;
    cin >> n >> m;
    string num = to_string(n);
    ll result = 0;
    for (auto d : num)
    {
        result += dp[d - '0' + m] % mod;
        result %= mod;
    }
    cout << result << "\n";
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