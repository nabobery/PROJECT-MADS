#include <iostream>
#include <cstring>
using namespace std;

void solve(){
    string s;
    cin >> s;
    if(s.size() <= 10) cout<<s<<"\n";
    else{
        string result = "";
        result += s[0];
        result += to_string(s.size() - 2);
        result += s[s.size()-1];
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



