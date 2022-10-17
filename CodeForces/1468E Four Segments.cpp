#include <iostream>
#include <algorithm>
using namespace std;

#pragma GCC optimize("Ofast")

int a[4];

void solve(){
    for(int i = 0; i < 4;i++) cin >> a[i];
    sort(a, a+4);
    cout<<a[0]*a[2]<<"\n";
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



