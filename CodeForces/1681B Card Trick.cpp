#include <iostream>
using namespace  std;

void solve(){
    int n, m,x, sum = 0;
    cin >> n;
    int a[n];
    for(int i = 0; i < n;i++) cin >> a[i];
    cin >> m;
    for(int i = 0; i < m;i++){
        cin >> x;
        sum += x;
        sum %= n;
    }
    cout<<a[sum]<<"\n";
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

