#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#pragma GCC optimize("Ofast")

#define ll long long int

// dp[i][j] means maximum difference between 1st and 2nd player (score1 - score2)  in the interval [i,j]
// Base case: if i == j dp[i][j] = x[i] as there's only one position to take from
// if 1st player takes from first position in [i,j]
// then 2nd player has to take from [i+1,j] as it's the same sub problem of player1 taking from [i+1,j] as both players play optimally
// dp[i][j] = x[i] - dp[i+1,j] max(score1 - score2) = x[i] - (score2 - remaining score1) => score1 - score2
// If 1st player takes from last position in [i,j]
// dp[i][j] = x[j] - dp[i,j-1]

void solve(){
    int n;
    ll sum = 0;
    cin >> n;
    int x[n];
    for(int i = 0; i < n;i++){
        cin >> x[i];
        sum += x[i];
    }
    vector<vector<ll>> dp(n, vector<ll>(n));
    for(int i = 0; i < n;i++) dp[i][i] = x[i];
    for(int l = n-1; l >= 0; l--){
        for(int r = l; r < n;r++){
            if(l != r) dp[l][r] = max(x[l] - dp[l+1][r], x[r] - dp[l][r-1]);
        }
    }
    // score1 + score2 = sum
    // score1 - score2 = dp[0][n-1] (max)
    // score1 = sum + dp[0][n-1]/2
    cout<<(sum + dp[0][n-1])/2<<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}





