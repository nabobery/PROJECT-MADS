#include <iostream>
using namespace  std;

void solve(){
    int n, m,k;
    cin >> n >> m >> k;
    long long int l = n;
    l *= n-1;
    l /= 2;
    if((m == l && k >= 3) || (n == 1 && k > 1 && m == 0) || (k > 3 && (m >= n-1 && m < l))) cout<<"YES\n";
    else cout<<"NO\n";
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

