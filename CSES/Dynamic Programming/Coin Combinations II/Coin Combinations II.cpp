#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int mod = 1e9 + 7;

void solve(){
    int n,x;
    cin >> n >> x;
    vector<int> change(n), dp(x+1, 0);
    for(int i = 0; i < n;i++) cin >> change[i];
    sort(change.begin(),change.end());
    dp[0] = 1;
    for(auto coin : change){
        if(coin > x) break;
        for(int i = 1; i <= x;i++){
            if((i - coin) < 0) continue;
            else{
                dp[i] = (dp[i] + dp[i-coin]) % mod;
            }
        }
    }
    cout<<dp[x]<<"\n";

}

int main() {
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}




