#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define ll long long int
#pragma GCC optimize("Ofast")

void solve(){
    int n;
    cin >> n;
    int h1[n], h2[n];
    for(int i = 0; i < n;i++) cin >> h1[i];
    for(int i = 0; i < n;i++) cin >> h2[i];
    // dp[0][i] is the maximal sum when we don't take the ith column
    // dp[1][i] is the maximal sum when we take from the 1st row
    // dp[2][i] is the maximal sum when we take from the 2nd row
    vector<vector<ll>> dp(3, vector<ll>(n+1,0));
    for(int i = 1; i <= n;i++){
        // get max possible from dp[0][i-1],dp[1][i-1], dp[2][i-1] as we aren't taking from ith column
        dp[0][i] = max(dp[0][i-1], dp[1][i-1]);
        dp[0][i] = max(dp[0][i], dp[2][i-1]);
        // get the max possible when we don't take from i-1th column or when we take i-1th column from 2nd row
        dp[1][i] = max(dp[0][i-1], dp[2][i-1]) + h1[i-1];
        // get the max possible when we don't take from i-1th column or when we take i-1th column from 1st row
        dp[2][i] = max(dp[0][i-1], dp[1][i-1]) + h2[i-1];
    }
    // get max possible of all 3 possibilities
    ll result = max(dp[0][n], dp[1][n]);
    result = max(result,dp[2][n]);
    cout<<result<<"\n";
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

