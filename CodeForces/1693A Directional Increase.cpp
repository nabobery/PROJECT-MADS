#include <iostream>
using namespace std;

void solve(){
    int n,x,i;
    cin >> n >> x;
    long long int b = x;
    bool flag = false;
    for(i = 1; i < n;i++){
        cin >> x;
        if((b < 0) || (b == 0 && (b+x) != 0)){
            flag = true;
            break;
        }
        else  b += x;
    }
    if(flag){
        i++;
        while(i < n){
            cin >> x;
            i++;
        }
    }
    if(b == 0){
        if(flag) cout<<"No\n";
        else cout<<"Yes\n";
    }
    else{
        cout<<"No\n";
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





