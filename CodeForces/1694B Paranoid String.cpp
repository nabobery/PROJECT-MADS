#include <iostream>
using namespace std;

void solve(){
    int n;
    string s;
    cin >> n >> s;
    long long int result = n;
    result *= (n+1);
    result /= 2;
    for(int i = 1; i < n;i++){
        if(s[i] == s[i-1]) result -= i;
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





