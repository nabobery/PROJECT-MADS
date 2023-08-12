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
                          int r, int p = mod)
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

// We can write the problem statement in ohter way as 
// We need to find the number of ways to get a non-decreasing sequence of length 2*m from 1 to n which can be used to form (a,b)
// Let xi denote number of times we take value i in our sequence with xi≥0. Also,
// x1+x2+x3+...+xn−1+xn=2m 
// So, we need to find the number of non-negative integer solutions to this equation.
// which can be solved using stars and bars method where we have n-1 bars and 2m stars
// The number of ways to do this is 2m+n−1C2*m = 2m+n−1Cn−1.
void solve(){
    int n, m;
    cin >> n >> m;
    cout<<nCrModPFermat(n + 2*m - 1, n-1)<<"\n";
}
 
int main() {
    ios_base::sync_with_stdio(false);
    int t = 1;
    //cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
 