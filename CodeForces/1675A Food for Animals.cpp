#include <iostream>
using namespace std;

void solve(){
    int a,b,c,x,y;
    cin >> a >> b >> c >> x >> y;
    int diff1 = x - a, diff2 = y - b;
    if(diff1 > 0 || diff2 > 0){
        if(diff1 > 0) c -= diff1;
        if(diff2 > 0) c -= diff2;
        if( c >= 0) cout<<"YES\n";
        else cout<<"NO\n";
    }
    else cout<<"YES\n";
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




