#include <iostream>
using namespace std;

#define ll long long int

void solve(){
    ll n;
    cin >> n;
    if(n %2 || n == 2) cout<<"-1\n";
    else{
        if(n == 4 || n == 6) cout<<"1 1 \n";
        else{
            if(n %6 == 0) cout<<n/6<<" "<<n/4<<"\n";
            else cout<<(n/6 + 1)<<" "<<n/4<<"\n";
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



