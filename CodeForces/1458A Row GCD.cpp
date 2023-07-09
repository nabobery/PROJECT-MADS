#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <cmath>
#include <queue>
#include <cstdlib>
#include <algorithm>
#include <cstring>
using namespace std;
 
#pragma GCC optimize("Ofast")
 
#define ll long long int
 
ll gcd(ll a, ll b){
    if(b == 0) return a;
    return gcd(b,a%b);
}
 
// GCD(x,y)=GCD(x−y,y)
// GCD(a1+bj,…,an+bj) = GCD(a1+bj,a2-a1…,an - a1)
void solve(){
    int n, m;
    cin >> n >> m;
    if(n == 1){
        ll a,b;
        cin >> a;
        for(int i = 0; i < m;i++){
            cin >> b;
            cout<<a+b<<" ";
        }
        cout<<"\n";
    }
    else{
        ll temp = 0, a1, x, result;
        cin >> a1;
        for(int i = 1; i < n;i++){
            cin >> x;
            temp = gcd(temp, abs(x - a1));
        }
        for(int i = 0; i < m;i++){
            cin >> x;
            result = gcd(temp, a1 + x);
            cout<<result<<" ";
        }
        cout<<"\n";
    }
}
 
 
int main() {
    ios_base::sync_with_stdio(false);
    int t = 1;
    //cin >> t;
    while(t--){
        solve();
    }
    return 0;
}