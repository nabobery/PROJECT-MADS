#include <iostream>
using namespace std;

void solve(){
    string s, t;
    long long int result = 1;
    cin >> s >> t;
    bool flag = false;
    for(char c: t){
        if(c == 'a'){
            flag = true;
            break;
        }
    }
    if(flag){
        if(t.size() == 1) cout<<"1\n";
        else cout<<"-1\n";
    }
    else{
        for(int i = 0; i < s.size();i++) result *= 2;
        cout<<result<<"\n";
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



