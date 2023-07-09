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
    int n, x;
    cin >> n;
    unordered_map<int,ll> mp;
    ll result = 0;
    for(int i = 1; i <= n;i++){
        cin >> x;
        if(mp.count(x)){
            result += (mp[x])*(n-i+1);
            mp[x] += i;
        }
        else mp[x] = i;
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