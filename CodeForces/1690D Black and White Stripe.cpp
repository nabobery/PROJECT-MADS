#include <iostream>
#include <algorithm>
using namespace std;

void solve(){
    int n, k;
    string s;
    cin >> n >> k >> s;
    int result = 1e6, black = 0;
    for(int i = 0; i < k;i++){
        if(s[i] == 'B') black++;
    }
    result = min(result, k - black);
    if(n == k) cout<<result<<"\n";
    else{
        for(int i = k; i < n;i++){
            if(s[i] == 'B') black++;
            if(s[i-k] == 'B') black--;
            result = min(result, k - black);
        }
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



