#include <iostream>
using namespace  std;

void solve(){
    int n, x , prev;
    bool flag = false;
    cin >> n;
    cin >> x;
    for(int i = 1; i < n;i++){
        prev = x;
        cin >> x;
        if(prev >= x) flag = true;
    }
    if(n % 2 == 0) cout<<"YES\n";
    else{
        if(flag) cout<<"YES\n";
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

