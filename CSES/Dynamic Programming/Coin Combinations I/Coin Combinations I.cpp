#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int mod = 1e9 + 7;

void solve(){
    int n, x;
    cin >> n >> x;
    vector<int> dp(x+1,0);
    vector<int> change(n);
    for(int i = 0; i < n;i++){
        cin >> change[i];
        if(change[i] <= x) dp[change[i]] = 1;
    }
    sort(change.begin(),change.end());
    for(int i = 1; i <= x;i++){
        long long temp = dp[i];
        for(auto coin : change){
            if(i-coin <= 0) break;
            else{
                temp += dp[i-coin];
            }
        }
        dp[i] =  temp%mod;
    }
    cout<<dp[x]<<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}



