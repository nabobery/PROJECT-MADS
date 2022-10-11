#include <iostream>
using namespace std;

#pragma GCC optimize("Ofast")

#define ll long long int

// unfairness from 0 to 2^k is 2^k+1 - 1 which is nothing but 2^k + 2^k-1 + 2^k-2 + .... 2^0 = 2^k+1 - 1
// we notice that 2^0 bit changes n/2 times, 2^1 bit changes n/4 times and so on...
// which can also be written as 2*n - number of bits set
void solve(){
    ll n,result = 0;
    cin >> n;
    while(n){
        result += n;
        n /= 2;
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




