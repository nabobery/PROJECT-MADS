#include <iostream>
using namespace std;

void solve(){
    int n, x,y, odd = 0, even = 0;
    cin >> n >> x;
    for(int i = 0; i < n;i++){
        cin >> y;
        if(y % 2 == 0) even++;
        else odd++;
    }
    if(odd == 0) cout<<"NO\n";
    else if(even == 0 && (x % 2 == 0 || odd < x)) cout<<"NO\n";
    else if(even == 0 && x % 2 == 1 && odd >= x) cout<<"YES\n";
    else{
        if(odd % 2 == 0) odd -= 1;
        if((even + odd) >= x) cout<<"YES\n";
        else cout<<"NO\n";
    }
    /* alternative way
     bool flag = false;
    for(int i = 1; i <= min(odd,x);i+=2){
        if(even >= x - i){
            flag = true;
            break;
        }
    }
    if(flag) cout<<"YES\n";
    else cout<<"NO\n";
    */
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





