#include <iostream>
using namespace std;

void solve(){
    int n;
    cin >> n;
    int b = (n+3)/3 + ((n+3)% 3 != 0);
    if((n-b) % 2) cout<<(n-b)/2 + 1<<" "<<b<<" "<<(n-b)/2<<"\n";
    else cout<<(n-b)/2 + 1<<" "<<b<<" "<<(n-b)/2 - 1<<"\n";

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



