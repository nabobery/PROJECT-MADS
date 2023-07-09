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
 
ll mod = 1e9 + 7;
 
ll gcd(ll a, ll b){
    if(b == 0) return a;
    return gcd(b, a%b);
}
 
ll lcm(ll a, ll b){
    return (a*b)/gcd(a,b);
}
 
void solve(){
    ll result = 0,n;
    cin >> n;
    ll curr = 1, prev = 1;
    for(int i = 2; i < 100;i++){
        curr = lcm(prev, i);
        ll temp = (n/prev - n/curr);
        result += i*temp;
        result %= mod;
        prev = curr;
    }
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