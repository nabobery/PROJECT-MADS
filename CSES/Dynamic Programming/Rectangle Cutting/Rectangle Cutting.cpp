#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#pragma GCC optimize("Ofast")

#define ll long long int

void solve(){
    int a,b;
    cin >> a >> b;
    vector<vector<int>> dp(a+1, vector<int>(b+1, 1e6));
    for(int i = 0; i <= min(a,b);i++) dp[i][i] = 0;
    for(int i = 1; i <= a;i++){
        for(int j = 1; j <= b;j++){
            // horizontal cut
            for(int k = 1; k < j;k++){
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[i][j-k] + 1);
            }
            // vertical cut
            for(int k = 1; k < i;k++){
                dp[i][j] = min(dp[i][j], dp[k][j] + dp[i-k][j] + 1);
            }
        }
    }
    cout<<dp[a][b]<<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}




