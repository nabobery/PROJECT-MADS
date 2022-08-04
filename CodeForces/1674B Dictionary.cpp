#include <iostream>
using namespace std;

void solve(){
    string s;
    cin >> s;
    int result = (s[0] - 'a')*25;
    result += (s[1] - 'a');
    if(s[1] < s[0]) result++;
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


