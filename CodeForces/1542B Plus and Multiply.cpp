#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#pragma GCC optimize("Ofast")

#define ll long long int

void solve(){
    int n,a,b;
    cin >> n >> a >> b;
    // if b=1, we can generate all numbers in the infinite set
    if(b == 1) cout<<"Yes\n";
    else{
        bool flag = false;
        // we need to check if n is of the form a^x + yb
        if(a != 1){
            // we check for all powers of a and check if we can reach n
            for(ll i = 1; i <= n; i *= a){
                // if we can reach n using b's
                if(i % b == n % b){
                    flag = true;
                    break;
                }
            }
        }
        // if a = 1, we can generate only 1 + nb therefore we check if n % b == 1
        else{
            flag = n % b == 1;
        }
        cout<<(flag ? "Yes\n" : "No\n");
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






