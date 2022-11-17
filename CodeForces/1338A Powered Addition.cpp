#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

#pragma GCC optimize("Ofast")

#define ll long long int

void solve(){
    int n,x,m,temp = 0;
    ll result;
    cin >> n;
    cin >> x;
    m = x;
    for(int i = 1; i < n;i++){
        cin >> x;
        if(x > m){
            m = x;
        }
        else{
            temp = max(temp, m - x);
        }
    }
    // find n using 2^n - 1 = max (max is max of the minimum required value to be non-decreasing at different positions)
    temp += 1;
    result = ceil(log2(temp));
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





