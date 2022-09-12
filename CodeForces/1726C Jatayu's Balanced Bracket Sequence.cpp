#include <iostream>
using namespace std;

void solve(){
    int n, result = 1;
    string s;
    cin >> n >> s;
    char prev = s[0];
    for(int i = 1; i < s.size();i++){
        if(prev == '(' && s[i] == '(') result++;
        prev = s[i];
    }
    cout<<result<<"\n";
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
