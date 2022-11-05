#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#pragma GCC optimize("Ofast")

#define ll long long int

int mod = 1e9 + 7;

// for us to have max sum and bitwise and zero, we need to have k zeroes (so that bitwise and is 0).
// We initially keep all 1's and put a zero in every kth bit(such that bitwise and is zero) in n numbers
// Therefore we have n^k possibilities (As we have to choose k zeroes from all n numbers having k bits)
void solve(){
    int n, k;
    cin >> n >> k;
    long long int result = 1;
    while(k--){
        result *= n;
        result %= mod;
    }
    cout<<result<<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}






