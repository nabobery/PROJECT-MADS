#include <iostream>
using namespace std;

void solve(){
    string s;
    cin >> s;
    int n = s.size();
    if(n == 1) cout<<"NO\n";
    else{
        bool flag = false;
        int count = 0;
        for(int i = 0; i < n;i++){
            if(s[i] == 'A') count++;
            else count--;
            if(count < 0){
                flag = true;
                break;
            }
        }
        if(!flag && s[n-1] == 'B') cout<<"YES\n";
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



