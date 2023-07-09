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
    int n;
    cin >> n;
    vector<ll> a(n), b(n);
    for(int i = 0; i < n;i++) cin >> a[i] >> b[i];
    // calculate the total number of extra bullets required meaning the sum of the number of bullets required to kill the next monster after the bullets released by the current monster
    ll extrab = 0;
    for(int i = 0; i < n-1;i++){
        extrab += max(0LL, a[i+1] - b[i]);
    }
    ll result = 1e18, temp = max(0LL,a[0] - b[n-1]);
    extrab += temp;
    // now we have to find the minimum number of bullets required to kill all the monsters and find the starting monster to kill 
    // we do this by calculating the number of bullets required by starting from the current monster
    // if the current monster is the starting monster then we have to add the number of bullets required to kill the current monster to the sum and subtract the extra bullets to kill the currwnt monster as it won't be using the bullets from killing the last monster
    result = min(result, (extrab - temp) + a[0]);
    for(int i = 1; i < n;i++){
        temp = max(0LL, a[i] - b[i-1]);
        result = min(result, (extrab - temp) + a[i]);
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