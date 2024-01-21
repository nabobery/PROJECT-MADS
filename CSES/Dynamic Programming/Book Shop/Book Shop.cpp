#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#pragma GCC optimize("Ofast")

// O(n*x) solution
void solve(){
    int n, x;
    cin >> n >> x;
    // getting the prices and pages
    int h[n], s[n];
    for(int i = 0; i < n;i++) cin >> h[i];
    for(int i = 0; i < n;i++) cin >> s[i];
    // creating a dp array and initialising with zero
    vector<vector<int>> dp(n+1, vector<int>(x+1,0));
    // dp[i][j] denotes the maximum amount of pages we can get with first i books and cost atmost j
    for(int i = 1; i <= n;i++){
        for(int j = 1; j <= x;j++){
            // we take the maximum of 1) we don't take the current book 2) we take the current book
            // 1) dp[i-1][j] 2) dp[i-1][j - h[i-1]] + s[i-1]
            int temp = j >= h[i-1] ? dp[i-1][j - h[i-1]] + s[i-1] : 0;
            dp[i][j] = max(dp[i-1][j], temp);
        }
    }
    cout<< dp[n][x]<<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}


