#include <iostream>
using namespace  std;

void solve(){
    string s;
    cin >> s;
    int l = s.size() - 1, r = 0;
    for(int i = 0; i < s.size();i++){
        if(s[i] == '0'){
            l = i;
            break;
        }
    }
    for(int i = s.size() - 1; i > -1;i--){
        if(s[i] == '1'){
            r = i;
            break;
        }
    }
    cout<<l-r+1<<"\n";
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

