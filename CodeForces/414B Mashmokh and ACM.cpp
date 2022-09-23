#include <iostream>
#include <vector>
using namespace std;

#pragma GCC optimize("Ofast")

int mod = 1e9 + 7;

void solve(){
    int n,k;
    cin >> n >> k;
    // dp[i][j] is number of good sequences of length i that ends in j
    vector<vector<int>> dp(k+1, vector<int>(n+1));
    for(int i = 1; i <= n;i++) dp[1][i] = 1;
    // going from length of 2 to k
    for(int i = 2; i <= k;i++){
        // going from 1 to n
        for(int j = 1; j <= n; j++){
            long long int temp = 0;
            // getting all multiples of j
            for(int t = j; t <= n;t += j){
                temp += dp[i-1][t];
            }
            dp[i][j] = temp % mod;
        }

    }
    long long int result = 0;
    // get the sum of all sequences that end in i and have length k
    for(int i = 1; i <= n;i++){
        result += dp[k][i];
    }
    result %= mod;
    cout<<result<<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}


