#include <iostream>
#include <bitset>
using namespace  std;

void solve(){
    int n,k, mod = 1000000007;
    cin >> n >> k;
    bitset<32> bset(k);
    long long int base = 1,result = 0;
    for(int i = 0; i < bset.size();i++){
        if(bset.test(i)){
            result += (base % mod);
            result %= mod;
        }
        base *= n;
        base %= mod;
    }
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

