#include <iostream>
#include <cmath>
using namespace std;

#pragma GCC optimize("Ofast")

void solve(){
    int n,x;
    cin >> n;
    bool flag = false;
    for(int i = 0; i < n;i++){
        cin >> x;
        if (ceil((double)sqrt(x)) != floor((double)sqrt(x))) flag = true;
    }
    cout<<(flag ? "YES\n" : "NO\n");
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

