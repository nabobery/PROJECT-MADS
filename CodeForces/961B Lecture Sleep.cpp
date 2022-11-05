#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#pragma GCC optimize("Ofast")

#define ll long long int

void solve(){
    int n, k,sum = 0,temp = 0;
    cin >> n >> k;
    int a[n], t[n],prefixsum[n+1];
    prefixsum[0] = 0;
    for(int i = 0; i < n;i++){
        cin >> a[i];
    }
    for(int i = 0; i < n;i++) cin >> t[i];
    int result = 0;
    for(int i = 0; i < n;i++){
        if(t[i] == 1){
            result += a[i];
            a[i] = 0;
        }
        sum += a[i];
        prefixsum[i+1] = sum;
    }
    for(int i = 0; i < n-k+1;i++){
        temp = max(temp,(prefixsum[i+k] - prefixsum[i]));
    }
    cout<<result + temp<<"\n";
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






