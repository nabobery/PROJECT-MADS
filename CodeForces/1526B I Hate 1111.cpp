#include <iostream>
using namespace std;

// 1111 = 11*101, 11111 = 111*100 + 11, 111111 = 111*101 and so on...
// 11a + 111b = x => 11(a + 10b) + b = x => b = x % 11, a = (x - 111*b)/11
void solve(){
    int x;
    cin >> x;
    if(x % 11 == 0 || x % 111 == 0) cout<<"YES\n";
    else{
        int b = x % 11, a = (x - 111*b);
        if(a > 0 && b > 0 ) cout<<"YES\n";
        else cout<<"NO\n";
    }
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
