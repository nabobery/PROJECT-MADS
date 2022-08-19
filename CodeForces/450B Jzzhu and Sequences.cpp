#include <iostream>
using namespace std;

int mod = 1e9 + 7;

void solve(){
    int x,y,n;
    int f[6];
    cin >> x >> y >> n;
    f[0] = x, f[1] = y;
    for(int i = 2; i < 6;i++){
        f[i] = (f[i-1]%mod - f[i-2]%mod)%mod;
    }
    cout<<(f[(n-1)%6] + mod)%mod<<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}




