#include <iostream>
using namespace std;

// to check if the number is not divisible by numbers from 2 to i+1
bool check(int x, int i){
    for(int k = 2; k <= i+1;k++){
        if(x % k != 0) return true;
    }
    return false;
}

void solve(){
    int n,x;
    cin >> n;
    bool flag = true;
    for(int i = 0; i < n;i++){
        cin >> x;
        if(i < 21) flag = (flag && check(x,i+1));
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



