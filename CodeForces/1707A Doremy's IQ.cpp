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
 
void solve(){
    int n, q, curr = 0;
    cin >> n >> q;
    int a[n];
    vector<bool> result(n, false);
    for(int i  = 0; i < n;i++) cin >> a[i];
    int p = n-1;
    for(; p >= 0 && curr < q;p--){
        if(a[p] > curr) curr++;
        result[p] = true;
    }
    for(; p >= 0;p--){
        if(a[p] <= curr) result[p] = true;
    }
    for(auto b : result) cout<<(b ? "1" : "0");
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