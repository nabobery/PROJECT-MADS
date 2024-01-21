#include <iostream>
#include <vector>
using namespace std;

#pragma GCC optimize("Ofast")

int mod = 1e9 + 7;

void solve(){
    int n, m,x;
    cin >> n >> m;
    // dp[i][j] = number of ways to fill the array up to index i, if x[i] = j
    vector<vector<int>> dp(n, vector<int>(102,0));
    cin >> x;
    if(x == 0){
        for(int j = 1; j <= m;j++) dp[0][j] = 1;
    }
    else dp[0][x] = 1;
    for(int i = 1; i < n;i++){
        cin >> x;
        if(x != 0){
            long long int temp = (long long int)dp[i-1][x-1] + dp[i-1][x] + dp[i-1][x+1];
            dp[i][x] = temp % mod;
        }
        else{
            for(int j =1; j <= m;j++){
                long long int temp = (long long int)dp[i-1][j-1] + dp[i-1][j] + dp[i-1][j+1];
                dp[i][j] = temp % mod;
            }
        }
    }
    long long int result = 0;
    for(int j = 1; j <= m;j++) result += (dp[n-1][j]%mod);
    cout<<result%mod<<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}

