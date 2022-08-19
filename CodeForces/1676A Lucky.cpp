#include <iostream>
using namespace std;

void solve(){
    char ch;
    int result = 0;
    for(int i = 0; i < 3;i++){
        cin >> ch;
        result += (ch - '0');
    }
    for(int i = 0; i < 3;i++){
        cin >> ch;
        result -= (ch - '0');
    }
    cout<< (result == 0 ? "YES\n" : "NO\n");
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



