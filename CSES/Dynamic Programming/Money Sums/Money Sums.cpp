#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

#pragma GCC optimize("Ofast")

#define ll long long int

void solve(){
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n;i++) cin >> arr[i];
    int sum = 0;
    for(auto i : arr) sum += i;
    bool dp[n+1][sum+1];
    memset(dp, false, sizeof(dp));
    for(int i = 0; i <= n;i++) dp[i][0] = true;
    for(int i = 1; i <= n;i++){
        dp[i][arr[i-1]] = true;
        for(int j = 1; j <= sum;j++){
            if(dp[i-1][j]){
                dp[i][j] = true;
                dp[i][j + arr[i-1]] = true;
            }
        }
    }
    int result = 0;
    for(int i = 1; i <= sum;i++){
        if(dp[n][i]) result++;
    }
    cout<<result<<"\n";
    for(int i = 1; i <= sum;i++){
        if(dp[n][i]) cout<<i<<" ";
    }
    cout<<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}






