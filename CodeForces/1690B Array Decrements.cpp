#include <iostream>
using namespace std;

int l = 1e9 + 1;

void solve(){
    int n,diff = l;
    cin >> n;
    int a[n], b[n];
    for(int i = 0; i < n;i++) cin >> a[i];
    for(int i = 0; i < n;i++) cin >> b[i];
    bool flag = false;
    for(int i = 0; i < n;i++){
        if(b[i] != 0){
            diff = a[i] - b[i];
            break;
        }
    }
    if(diff != l){
        if(diff < 0) flag = true;
        for(int i = 0; i < n;i++){
            if((b[i] != 0 && diff != (a[i] - b[i])) || (b[i] == 0 && diff < (a[i] - b[i]))) flag = true;
            else continue;
        }
    }
    if(flag) cout<<"NO\n";
    else cout<<"YES\n";
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



