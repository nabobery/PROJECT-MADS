#include <iostream>
using namespace std;

#pragma GCC optimize("Ofast")

void solve(){
    int n;
    cin >> n;
    string s;
    int result = 0;
    for(int i = 0; i < n;i++){
        cin >> s;
        bool flag = false;
        for(char c : s)
            if(c == '-') flag = true;
        if(flag) result--;
        else result++;
    }
    cout<<result<<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}


