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
    return gcd(b, a%b);
}
 
void solve(){
    int n;
    cin >> n;
    vector<int> cp;
    ll temp = 1;
    cp.push_back(1);
    for(int i = 2; i < n;i++) {
        if (gcd(i, n) == 1) {
            cp.push_back(i);
            temp *= i;
            temp %= n;
        }
    }
    if(temp == 1){
        cout<<cp.size()<<"\n";
        for(auto x : cp) cout<<x<<" ";
        cout<<"\n";
    }
    else{
        cout<<cp.size() - 1<<"\n";
        for(auto x : cp) if(x != temp) cout<<x<<" ";
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