#include <iostream>
using namespace std;

#pragma GCC optimize("Ofast")

// As we can't choose the next character to remove, if we have an occurrence of 11 before occurrence of 00, it's not possible to remove both 11 or 00 => NO
void solve(){
    string s;
    cin >> s;
    int p1 = s.size(), p2 = 0;
    for(int i = 0; i < s.size()-1;i++){
        string temp = s.substr(i,2);
        if(temp == "11"){
            p1 = i;
            break;
        }
    }
    for(int i = s.size()-1; i > 0;i--){
        string temp = s.substr(i-1,2);
        if(temp == "00"){
            p2 = i-1;
            break;
        }
    }
    cout <<(p1 < p2 ? "NO\n" : "YES\n");
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




