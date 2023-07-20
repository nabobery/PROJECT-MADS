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

#define ll long long

int mod = 1e9 + 7;

unsigned ll power(unsigned ll x, int y, int p)
{
    unsigned ll res = 1; // Initialize result

    x = x % p; // Update x if it is more than or
    // equal to p

    while (y > 0)
    {

        // If y is odd, multiply x with result
        if (y & 1)
            res = (res * x) % p;

        // y must be even now
        y = y >> 1; // y = y/2
        x = (x * x) % p;
    }
    return res;
}

// Returns n^(-1) mod p
unsigned ll modInverse(unsigned ll n, int p)
{
    return power(n, p - 2, p);
}
unsigned ll mul(unsigned ll x,
                unsigned ll y, int p)
{
    return x * 1ull * y % p;
}
unsigned ll divide(unsigned ll x,
                   unsigned ll y, int p)
{
    return mul(x, modInverse(y, p), p);
}
// Returns nCr % p using Fermat's little
// theorem.
unsigned ll nCrModPFermat(unsigned ll n,
                          int r, int p)
{
    // If n<r, then nCr should return 0
    if (n < r)
        return 0;
    // Base case
    if (r == 0)
        return 1;
    // if n-r is less calculate nCn-r
    if (n - r < r)
        return nCrModPFermat(n, n - r, p);

    // Fill factorial array so that we
    // can find all factorial of r, n
    // and n-r
    unsigned ll res = 1;
    // keep multiplying numerator terms and dividing denominator terms in res
    for (int i = r; i >= 1; i--)
        res = divide(mul(res, n - i + 1, p), i, p);
    return res;
}

void solve()
{
    int n, k, x;
    cin >> n >> k;
    map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        mp[x]++;
    }
    for (auto i = mp.rbegin(); i != mp.rend(); ++i)
    {
        if (k - i->second <= 0)
        {
            cout << nCrModPFermat(i->second, k, mod) << "\n";
            break;
        }
        k -= i->second;
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