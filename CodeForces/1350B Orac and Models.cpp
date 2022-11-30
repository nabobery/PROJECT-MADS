#include <iostream>
#include <algorithm>
using namespace std;

#pragma GCC optimize("Ofast")

void solve(){
    int n;
    cin >> n;
    int arr[n];
    // dp[i] is the maximum number of models that we can buy till index i
    int dp[n];
    // intialise dp[i] to 1
    for(int i = 0; i < n;i++){
        cin >> arr[i];
        dp[i] = 1;
    }
    // O(nlogn) solution
    // start from index i = 1 to n
    for(int i = 0; i < n;i++){
        // get all multiples of i
        for(int j = (i+1)*2 ; j <= n; j += (i+1)){
            // if it's less it means we have can buy this and ith model to together, get the max of the current dp[j] and dp[i] + 1
            if(arr[i] < arr[j-1]){
                dp[j-1] = max(dp[j-1], dp[i] + 1);
            }
        }
    }
    int result = 0;
    // get the maximum number of models possible
    for(auto num : dp) result = max(num,result);
    cout<<result<<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}

