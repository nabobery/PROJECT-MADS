// Solution 1
/*
 type-1 towers = Both cells as a part of the same block in the last row
 type-2 towers = Both cells as parts of different blocks in the last row
 an is number of type 1 towers and bn is number of type-2 towers
 a1 = 1, b1 = 1
 an = 2*an-1 + bn-1 , bn = 4*bn-1 + an-1
 number of total towers is an + bn
 an is (number of towers where both cells are divided + 1 undivided block)[bn-1]  + (number of towers where both cells are in the same block + 1 undivided block or we include the final block in the above block) [2*an-1]
 bn is (number of towers where both cells are in the same block + 2 divided blocks)[an-1] + (here we have 4 possibilities so ) [4*bn-1]
 4 possibilities where the n-1th and nth cell are divided wrt cells in the same row
 1) the 1st column has 2 1x1 blocks and 2nd column has 1 2x1 block ( after we merge the rightmost blocks)
 2) the 2nd column has 2 1x1 blocks and 1st column has 1 2x1 block (after we merge the leftmost blocks)
 3) both 1st and 2nd columns have 2x1 blocks (after we merge the both columns)
 4) we have 4 1x1 blocks in the last 2 rows
 */
#include <iostream>
#include <vector>
using namespace std;

#pragma GCC optimize("Ofast")

int l = 1e6 + 1, mod = 1e9 + 7;

vector<int> dp(l,0);

void helper(){
    long long int a = 1, b = 1,t1,t2;
    dp[1] = 2;
    for(int i = 2; i < l;i++){
        t1 = 2*a + b;
        t2 = 4*b + a;
        t1 %= mod;
        t2 %= mod;
        a = t1, b = t2;
        dp[i] = (t1+t2)% mod;
    }
}

void solve(){
    int n;
    cin >> n;
    cout<<dp[n]<<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    helper();
    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}




