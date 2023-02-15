#include <iostream>
#include <cmath>
using namespace std;

#pragma GCC optimize("Ofast")

void solve(){
    int n;
    cin >> n;
    // as c^2 = a^2 + b^2 and c = a^2 - b, we get 2 equations => c = b+1 and a^2 = 2*b - 1
    // so every odd value of a we have a triplet, now we need to calculate till the max value of a which is upperbounded by sqrt(2*n-1)
    // and we need to start a from 3 as (a,b,c >= 1)
    int result = sqrt(2*n - 1);
    result = (result - 1)/2;
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






