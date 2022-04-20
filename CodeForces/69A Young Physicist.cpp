#include <iostream>
using namespace  std;

void solve(){
    int n;
    cin >> n;
    int x, y, z, r1 = 0, r2 = 0, r3 = 0;
    for(int i = 0; i < n;i++){
        cin >> x >> y >> z;
        r1 += x;
        r2 += y;
        r3 += z;
    }
    if(r1 == 0 && r2 == 0 && r3 == 0) cout<<"YES\n";
    else cout<<"NO\n";
}

int main() {
    int t = 1;
    while(t--){
        solve();
    }
    return 0;
}


