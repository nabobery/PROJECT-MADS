#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
#include <cmath>
#include <queue>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <stack>
using namespace std;
 
#pragma GCC optimize("Ofast")
 
#define ll long long int
 
void solve(){
    int x, y;
    ll n;
    cin >> x >> y;
    if(x > y){
        n = x;
        n *= y;
        n += y;
    }
    else if(y%x == 0) n = x;
    else{
        n = y/x;
        n = (n*x + y)/2;
    }
    cout<<n<<"\n";
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
 