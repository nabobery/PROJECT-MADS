// 1669C Odd/Even Increments
#include <iostream>
using namespace std;

void solve(){
    int n,x;
    cin >> n;
    cin >> x;
    int div1 = x % 2;
    cin >> x;
    int div2 = x % 2;
    bool flag1 = true, flag2 = true;
    for(int i = 2; i < n;i++){
        cin >> x;
        if(i % 2 == 0){
            if(div1 != x % 2) flag1 =  false;
        }
        else{
            if(div2 != x % 2) flag2 = false;
        }
    }
    if(flag1 && flag2) cout<<"YES\n";
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




