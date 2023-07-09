#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <cmath>
#include <queue>
#include <algorithm>
using namespace std;
 
#pragma GCC optimize("Ofast")
 
#define ll long long int
 
void solve(){
    ll n;
    cin >> n;
    if(n <= 2) cout<<n<<"\n";
    else{
        if(n% 2){
            cout<<n*(n-1)*(n-2)<<"\n";
        }
        else{
            if(n%3) cout<<n*(n-1)*(n-3)<<"\n";
            else cout<<(n-1)*(n-2)*(n-3)<<"\n";
        }
    }
}
 
 
int main() {
    ios_base::sync_with_stdio(false);
    int t = 1;
    while(t--){
        solve();
    }
    return 0;
}