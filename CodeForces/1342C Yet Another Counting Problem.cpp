#include <iostream>
#include <vector>
#include <map>
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
 
int gcd(int a, int b){
    if(b == 0) return a;
    return gcd(b,a%b);
}
 
void solve(){
    int a,b,q;
    cin >> a >> b >> q;
    if(a > b) swap(a,b);
    ll l, r, result;
    ll lcm = (a*b)/ gcd(a,b);
    for(int i= 0; i < q;i++){
        cin >> l >> r;
        int t1 = (l-1)%lcm, t2 = r %lcm;
        result = (r/lcm) *(lcm-b);
        result -= (l-1)/lcm *(lcm-b);
        if(t1 >= b) result -= (t1 - b + 1);
        if(t2 >= b) result += (t2 - b + 1);
        cout<<result<<" ";
    }
    cout<<"\n";
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