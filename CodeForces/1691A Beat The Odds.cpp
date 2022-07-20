#include <iostream>
using namespace std;

void solve(){
    int n,x,odd = 0;
    cin >> n;
    for(int i = 0; i < n;i++){
        cin >> x;
        if(x%2 == 0) odd++;
    }
    int result = (odd >= (n - odd)) ? n-odd : odd;
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



