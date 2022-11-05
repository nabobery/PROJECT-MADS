#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

#pragma GCC optimize("Ofast")

#define ll long long int

void solve(){
    int n,x;
    cin >> n;
    map<int,int> mp;
    // counter of all elements in array
    for(int i = 0; i < n;i++){
        cin >> x;
        mp[x]++;
    }
    // max element
    int m = mp.rbegin()->first;
    // dp[i] is the max points we gain after going from numbers 1 to i  in the array
    // so we need to return dp[max]
    vector<ll> dp(m+1,0);
    dp[0] = 0;
    dp[1] = mp.count(1) ? mp[1] : 0;
    for(ll i = 2; i <= m;i++){
        // either we take this element and dp[i-2] or just don't take this one and prev one and get max
        dp[i] = max(dp[i-1], dp[i-2] + i*mp[i]);
    }
    // print out dp[max]
    cout<<dp[m]<<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}





