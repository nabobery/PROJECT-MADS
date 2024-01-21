#include <iostream>
#include <vector>
using namespace std;

#pragma GCC optimize("Ofast")

#define ll long long int

int mod = 1e9 + 7;

// Solution 1
void solve(){
    int n;
    cin >> n;
    // if the sum is odd can't divide the sum into 2 sets
    // sum is n*(n+1)/2 so if sum has to be divisible by 2 n%4 == 0 || n+1%4 == 0
    if(n % 4 == 1 || n % 4 == 2){
        cout<<"0\n";
        return;
    }
    int sum = n*(n+1);
    sum /= 4;
    // find the number of ways we can get target sum from i=1 to i=n and then divide by 2
    vector<vector<int>> dp(n+1, vector<int>(sum+1));
    // base case
    dp[0][0] = 1;
    for(int i = 1; i <= sum;i++) dp[0][i] = 0;
    for(int i = 1; i <= n;i++){
        for(int j = 0; j <= sum;j++){
            // if i is greater than sum which means we can't include it
            if(i > j){
                dp[i][j] = dp[i-1][j];
            }
            else{
                // total number of ways to get sum j using first i elements is sum of
                // to not include ith number => dp[i-1][j]
                // to include ith number => dp[i-1][j-i]
                ll temp = dp[i-1][j] + dp[i-1][j - i];
                dp[i][j] = temp%mod;
            }
        }
    }
    // because dp[n][sum] = number of ways to get target sum = 2* number of ways to get 2 sets
    // dp[n][sum]/2  % mod = dp[n][sum]* inversemodulo(2, mod) % mod
    ll result = dp[n][sum];
    result *= 500000004;
    cout<<result%mod<<"\n";
}

// Solution 2
// Same as Solution 1 but we only calculate from 1 to n-1 because n is always in the other set
// So, number of ways to make 2 sets with the given sum is to just calculate the number of ways to make sum from 1 to n-1 elements
void solve2(){
    int n;
    cin >> n;
    if(n % 4 == 1 || n % 4 == 2){
        cout<<"0\n";
        return;
    }
    int sum = n*(n+1);
    sum /= 4;
    vector<vector<int>> dp(n,vector<int>(sum+1,0));
    dp[0][0] = 1;
    for (int i = 1; i < n; i++) {
        for (int j = 0; j <= sum; j++) {
            dp[i][j] = dp[i-1][j];
            int left = j-i;
            if (left >= 0) {
                (dp[i][j] += dp[i-1][left]) %= mod;
            }
        }
    }
    cout << dp[n-1][sum] << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}






