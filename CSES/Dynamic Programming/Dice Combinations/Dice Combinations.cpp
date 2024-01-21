#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int mod = 1e9 + 7;

void solve(){
    int n;
    cin >> n;
    vector<int> dp(n+1,1);
    long long int result;
    for(int i = 2; i <= n;i++){
        result = 0;
        for(int j = 1; j < min(i+1,7);j++) result += dp[i-j];
        result %= mod;
        dp[i] = result;
    }
    cout<<dp[n]<<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}



