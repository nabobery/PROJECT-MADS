#include <iostream>
using namespace std;

#pragma GCC optimize("Ofast")

void solve(){
    string s;
    cin >> s;
    int result = 0;
    for(char c : s){
        if(c == '4' || c == '7') result++;
    }
    if(result == 4 || result == 7) cout<<"YES\n";
    else cout<<"NO\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}

