#include <iostream>
using namespace std;

void solve(){
    int n, k;
    cin >> n >> k;
    if((n % 2) ^ k%2) cout<<"NO\n";
    else{
        long long int l = k;
        l *= k;
        if(n < l) cout<<"NO\n";
        else{
            cout<<"YES\n";
        }
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





