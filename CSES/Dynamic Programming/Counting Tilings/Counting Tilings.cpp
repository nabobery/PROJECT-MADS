#include <iostream>
using namespace std;

#pragma GCC optimize("Ofast")

#define ll long long int

const int mod = 1e9 + 7;

// Solution 1 which solves in O(NM*2^N) time complexity and O(M*2^N) space complexity

// dp[i][mask] is the number of ways to fill i-1 columns with mask representing cells filled in the ith column
//int dp[1001][1 << 10];
//int n, m;
//
//// helper function to fill the current column given current configuration, current row and next column's configuration
//void helper(int col, int row, int curr_mask, int next_mask){
//    // base case if we fill the current column
//    // we add the number of ways to the next configuration
//    if(row == n){
//        dp[col+1][next_mask] = (dp[col+1][next_mask] + dp[col][curr_mask])%mod;
//        return;
//    }
//    // if the current cell [row][col] is filled we just proceed with the next cell
//    if(curr_mask & (1 << row)) helper(col, row+1, curr_mask, next_mask);
//        // if not filled
//    else{
//        // we fill it with horizontal tile and set the next mask configuration (-)
//        helper(col, row+1, curr_mask, next_mask | 1<<row);
//        // if the tile below is free we go for the vertical tile (|)
//        // and there won't be any change in next mask because vertical tile doesn't fill any tiles in next column
//        if(row+1 < n && !(curr_mask & (1 << (row+1))))
//            helper(col, row+2, curr_mask, next_mask);
//    }
//}
//
//void solve(){
//    cin >> n >> m;
//    // if number of tiles is odd, it won't be possible to fill it with 2x1 and 1x2 tiles
//    if(n*m % 2){
//        cout<<"0\n";
//        return;
//    }
//    // base case where number of ways to fill an empty grid is 1
//    dp[0][0] = 1;
//    // traverse through all columns
//    for(int col = 0; col < m;col++){
//        // traverse through all possible masks
//        for(int mask = 0; mask < 1<<n;mask++){
//            // if number of  ways to get the current configuration > 0, we fill to go to the next configuration
//            if(dp[col][mask] > 0)
//                helper(col, 0, mask, 0);
//        }
//    }
//    // number of ways to fill m columns with m+1th column empty (whole grid covered)
//    cout<<dp[m][0]<<"\n";
//}

// dp[i][j][mask] represent the number of ways when we're currently at the point (i,j) and first i bits of mask correspond to jth column and rest of the bits belong to j-1 column
// All cells from cell (0, 0) to cell (i, j - 1) are covered.
// All cells from cell (i + 1, j) to cell (N - 1, M - 1) are empty

// When ith bit is 0 which means the ith cell in jth column in the mask is already covered
// Case 1 : We used horizontal tile to cover j-1th and jth column in ith row => dp[i][j][mask] = dp[i−1][j][mask ^ 2^i] (As, it's the same sub problem as point {i-1,j} with ith bit set)
// Case 2 : We used vertical tile to cover i-1th row and ith row => dp[i][j][mask] = dp[i−1][j][mask ^ 2^i] +  dp[i−1][j][mask ^ 2^-1] (As, it's the same sub problem as point {i-1,j} with ith and i-1th bit set)
// When ith bit is 1 which means ith cell in jth column is empty
// Case 3: We need to fill {i,j} cell with tiles and unset the ith cell bit => dp[i][j][mask] = dp[i−1][j][mask ^ 2^i]
int dp[1 << 10][2];

// Solution 2 solves in O(NM*2^N) time complexity and O(2^N) space complexity
void solve(){
    int n, m;
    cin >> n >> m;
    // base case
    dp[0][0] = 1;
    // traverse column by column
    for(int j = 0; j < m;j++){
        // traverse row by row
        for(int i = 0; i < n;i++){
            // traverse all possible mask configurations
            for(int mask = 0; mask < (1 << n); mask++){
                // Case 1 and Case 3
                dp[mask][1] = dp[mask ^ (1 << i)][0];
                // case 2
                if (i && !(mask & (1 << i)) && !(mask & (1 << i - 1)))
                    dp[mask][1] += dp[mask ^ (1 << i - 1)][0];
                // modulo operation
                if (dp[mask][1] >= mod) dp[mask][1] -= mod;
            }
            // setting the previous row
            for (int mask = 0; mask < (1 << n); mask++) dp[mask][0] = dp[mask][1];
        }
    }
    cout<<dp[0][0]<<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    int t = 1;
    //cin >> t;
    while(t--){
        solve();
    }
    return 0;
}




