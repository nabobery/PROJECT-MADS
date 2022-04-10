#include <iostream>
using namespace  std;

void solve(){
    int n;
    cin >> n;
    if(n % 2 == 1) cout<<0<<"\n";
    else {
        long long int result = 1;
        int mod = 998244353;
        for (int i = 1; i <= n / 2; i++) {
            result *= i;
            result %= mod;
        }
        result *= result;
        result %= mod;
        cout << result << "\n";
    }
}

int main() {
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}


