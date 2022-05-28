#include <iostream>
using namespace  std;

void solve(){
    int n,x,result;
    bool flag = false;
    cin >> n;
    for(int i = 0; i < n;i++){
        cin >> x;
        if(!flag && i != x){
            result = x;
            flag = true;
        }
        if(i != x) result = (result & x);
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
