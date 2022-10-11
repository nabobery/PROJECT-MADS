#include <iostream>
#include <algorithm>
using namespace std;

#pragma GCC optimize("Ofast")

int highestPowerof2(int n){
    if (!(n & (n - 1)))
        return n;
    return 0x80000000 >> (__builtin_clz(n));
}

// we know that sigma(ai) = S, let's take bi = 2^floor(log2 ai) => ai - bi <= ai/2 => sigma(ai-bi) <= S/2 => 2*sigma(ai - bi) <= S
void solve(){
    int n,x;
    cin >> n;
    for(int i = 0; i < n;i++){
        cin >> x;
        cout<<highestPowerof2(x)<<" ";
    }
    cout<<"\n";
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




