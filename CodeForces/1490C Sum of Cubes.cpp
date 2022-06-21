#include <iostream>
#include <cmath>
using namespace  std;

void solve(){
    long long int x;
    cin >> x;
    int l = cbrt(x);
    bool flag = false;
    for(int i = 1; i <= l;i++){
        long long int temp = x - (long long int)pow(i,3);
        double a = cbrt(temp);
        if(a != 0 && a - (int)a  == 0){
            flag = true;
            break;
        }
    }
    if(flag) cout<<"YES\n";
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

