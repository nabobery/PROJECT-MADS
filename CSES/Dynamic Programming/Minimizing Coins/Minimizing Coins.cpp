#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

void solve(){
    int n,x,temp;
    cin >> n >> x;
    vector<int> dp(x+1,-1);
    set<int> coins;
    for(int i = 0; i < n;i++){
        cin >> temp;
        coins.insert(temp);
    }
    for(int i = 1; i <= x;i++){
        if(coins.find(i) != coins.end()) dp[i] = 1;
        else{
            for(auto itr: coins){
                if(i-itr <= 0 || dp[i - itr] == -1) continue;
                else{
                    if(dp[i] == -1) dp[i] = 1 + dp[i - itr];
                    else dp[i] = min(dp[i], 1 + dp[i-itr]);
                }
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


