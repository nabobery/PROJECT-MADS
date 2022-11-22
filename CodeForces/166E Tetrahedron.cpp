#include <iostream>s
using namespace std;

#pragma GCC optimize("Ofast")

#define ll long long int

int mod = 1e9 + 7;

void solve(){
    int n;
    cin >> n;
    /* As we know that we can reach a vertex using other vertices. Therefore the number of ways we can reach a vertex can be given as
     * Ai = Bi-1 + Ci-1 + Di-1
     * Bi = Ai-1 + Ci-1 + Di-1
     * Ci = Ai-1 + Bi-1 + Di-1
     * Di = Ai-1 + Bi-1 + Ci-1
     * As, we're starting from D, we have A0 = 0, B0 = 0, C0 = 0, D0 = 1
     * As, the tetrahedron is symmetrical, we conclude that ABCi = Ai = Bi = Ci
     * => ABCi = Di-1 + 2*ABCi-1
     * => Di = 3*ABCi-1
     */
    ll abc = 0, d = 1;
    for(int i = 1; i <= n;i++){
        int t_abc = (d + 2*abc) % mod;
        int t_d = (3*abc)%mod;
        d = t_d;
        abc = t_abc;
    }
    cout<<d<<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}






