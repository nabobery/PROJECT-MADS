#include <iostream>
#include <vector>
using namespace std;

int mod = 1e9 + 7;

void solve(){
    int n;
    cin >> n;
    char grid[n][n];
    vector<vector<int>> dp(n,vector<int>(n,0));
    for(int i = 0; i < n;i++){
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }
    if(grid[0][0] == '.') dp[0][0] = 1;
    for(int i = 0; i < n;i++){
        for(int j = 0; j < n;j++){
            if(grid[i][j] == '*'){
                continue;
            }
            long long int temp = (i > 0 ? dp[i-1][j] : 0);
            temp += (j > 0 ? dp[i][j-1] : 0);
            dp[i][j] += temp%mod;
        }
    }
    cout<<dp[n-1][n-1]<<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}




