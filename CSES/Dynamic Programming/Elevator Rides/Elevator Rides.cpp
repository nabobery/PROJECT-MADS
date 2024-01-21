#include <iostream>
#include <algorithm>
using namespace std;

#pragma GCC optimize("Ofast")

// dp[bitmask] indicates the minimum number of elevator rides required for bitmask subset and has the weight of the last elevator ride
pair<int,int> dp[1 << 20];

// Time Complexity: O(n*2^n)
// Space Complexity: O(2^n)
void solve(){
    int n, x;
    cin >> n >> x;
    int w[n];
    for(int i = 0; i < n;i++) cin >> w[i];
    // base case when there's no one taken (1 ride required and 0 weight in the last ride)
    dp[0] = {1,0};
    // go through all the subsets from 1 to 2^n
    for(int i = 1; i < (1 << n);i++){
        // initialise with the highest value which is n+1 because at max we require n rides
        dp[i] = {n+1, 0};
        // go through all the elements which can be the last person
        for(int j = 0; j < n;j++){
            // if j belongs to the subset i
            if(i&(1 << j)){
                // get the value of subset which doesn't include j
                auto p = dp[i^(1<<j)];
                // if we can include j in the last ride, we add the j's weight to pair without p
                if(p.second + w[j] <= x){
                    p.second += w[j];
                }
                // if we can't, we add j to the new elevator ride and keep the last weight as j
                else{
                    p.first++;
                    p.second = w[j];
                }
                // we get the minimum possible subset permutation such that we get least number of elevator rides
                dp[i] = min(dp[i], p);
            }
        }
    }
    // return the minimum rides required considering all n persons
    cout<<dp[(1 << n) - 1].first<<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}





