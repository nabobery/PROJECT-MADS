#include <iostream>
using namespace  std;

void solve(){
    int n, result = 0,x;
    cin >> n;
    for(int i = 0; i < n;i++){
        cin >> x;
        result |= x;
    }
    cout<<result<<"\n";
}

int main() {
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}

