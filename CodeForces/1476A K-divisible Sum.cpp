#include <iostream>
using namespace  std;

void solve(){
    int n, k;
    cin >> n >> k;
    if(n <= k){
        if(k%n != 0) cout<<k/n + 1<<"\n";
        else cout<<k/n<<"\n";
    }
    else{
        if(n % k == 0) cout<<"1\n";
        else cout<<"2\n";
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
