#include <iostream>
#include <cmath>

using namespace std;
 
#pragma GCC optimize("Ofast")
 
#define ll long long int
 
void solve(){
    int n, x, ma = 0;
    cin >> n;
    ll result= 0;
    for(int i = 0; i < n;i++){
        cin >> x;
        ma = max(ma, x);
        result+= x;
    }
    result= ceil((double)result/(n-1));
    cout<<(ma > result? ma : result)<<"\n";
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