// 1420. Build Array Where You Can Find The Maximum Exactly K Comparisons

// Solution 1 using Top Down DP
// Time complexity: O(n*m^2*k)
// Space complexity: O(n*m*k)
class Solution {
public:
    // dp[a][b][c] = number of ways to build array of length a, with max value b, and k steps left
    vector<vector<vector<int>>> dp;
    int n, m, mod = 1e9 + 7;
    int numOfArrays(int n, int m, int k) {
        this->n = n;
        this->m = m;
        // initialize 3D dp with -1
        dp = vector(n, vector<vector<int>>(m+1, vector<int>(k+1, -1)));
        // return helper(0,0, k);
        return helper(0,0, k);
    }

    // helper function to calculate number of ways to build array of length a, with max value b, and k steps left
    int helper(int a, int b, int c){
        // base case
        // if we reach the end of the array and we have used all k steps, return 1 else return 0
        if(a == n) return (c == 0 ? 1 : 0);
        // if we have used all k steps but we haven't reached the end of the array, return 0
        if(c < 0) return 0;
        // if we have already calculated the number of ways to build array of length a, with max value b, and k steps left, return it
        if(dp[a][b][c] != -1) return dp[a][b][c];
        // we don't introduce a new max value at the a-th index of the array
        // we initialize the result to the number of ways to build array of length a+1, with max value b, and k steps left * range of values we can use for the a-th index
        long long res = helper(a+1, b, c);
        res *= b;
        res %= mod;
        // we introduce a new max value at the a-th index of the array
        for(int i = b+1; i <= m;i++){
            // we add the number of ways to build array of length a+1, with max value i, and k-1 steps left
            res += helper(a+1, i, c-1)%mod;
            res %= mod;
        }
        // return the result
        return dp[a][b][c] = res;
    }
    
};

// Solution 2 using Bottom Up DP
// Time complexity: O(n*m^2*k)
// Space complexity: O(n*m*k)
class Solution {
public:
    int numOfArrays(int n, int m, int k) {
        vector<vector<vector<int>>> dp(n + 1, vector(m + 1, vector(k + 1, 0)));
        int mod = 1e9 + 7;
        // base case
        // if we reach the end of the array and we have used all k steps, return 1 else return 0
        for (int i = 0; i <= m; i++) {
            dp[n][i][0] = 1;
        }
        for(int i = n-1;i >= 0;i--){
            for(int j = m;j >= 0;j--){
                for(int l = 0;l <= k;l++){
                    long res = 0;
                    // we don't introduce a new max value at the a-th index of the array
                    for(int num = 1;num <= j;num++){
                        res += dp[i+1][j][l];
                        res %= mod;
                    }
                    // we introduce a new max value at the a-th index of the array and we have k-1 steps left
                    if(l > 0){
                        for(int num = j+1;num <= m;num++){
                            res += dp[i+1][num][l-1];
                            res %= mod;
                        }
                    }
                    dp[i][j][l] = res;
                }
            }
        }   
        return dp[0][0][k];
    }
};

// Solution 3 using Bottom Up DP with Space Optimization
// As we need only the previous row to calculate the current row, we can optimize the space complexity
// Time complexity: O(n*m^2*k)
// Space complexity: O(m*k)
class Solution {
public:
    int numOfArrays(int n, int m, int k) {
        vector<vector<int>> dp(m + 1, vector(k + 1, 0));
        int mod = 1e9 + 7;
        for (int i = 0; i <= m; i++) {
            dp[i][0] = 1;
        }
        for(int i = n-1;i >= 0;i--){
            vector<vector<int>> new_dp(m + 1, vector(k + 1, 0));
            for(int j = m;j >= 0;j--){
                for(int l = 0;l <= k;l++){
                    long res = 0;
                    for(int num = 1;num <= j;num++){
                        res += dp[j][l];
                        res %= mod;
                    }
                    if(l > 0){
                        for(int num = j+1;num <= m;num++){
                            res += dp[num][l-1];
                            res %= mod;
                        }
                    }
                    new_dp[j][l] = res;
                }
            }
            dp = new_dp;
        }   
        return dp[0][k];
    }
};

// Solution 4 using DP and Prefix Sum
// Time complexity: O(n*m*k)
// Space complexity: O(n*m*k)
class Solution {
public:
    int numOfArrays(int n, int m, int k) {
        long long dp[n+1][m+1][k+1], prefix[n+1][m+1][k+1];
        memset(dp, 0, sizeof(dp));
        memset(prefix, 0, sizeof(prefix));
        int mod = 1e9 + 7;
        // base case
        // if the length of the array is 1, we have only one step count

        for (int i = 1; i <= m; i++) {
            dp[1][i][1] = 1;
            prefix[1][i][1] = prefix[1][i - 1][1] + 1;
        }
        for(int i = 1; i <= n;i++){
            for(int j = 1;j <= m;j++){
                for(int l = 1;l <= k;l++){
                    long long res = j*dp[i-1][j][l];
                    res %= mod;
                    res += prefix[i-1][j-1][l-1];
                    res %= mod;
                    dp[i][j][l] += res;
                    dp[i][j][l] %= mod;
                    prefix[i][j][l] = (prefix[i][j-1][l] + dp[i][j][l]);
                    prefix[i][j][l] %= mod;
                }
            }
        }
        return prefix[n][m][k];
    }
};


// Solution 5 using DP and Prefix Sum with Space Optimization
// Time complexity: O(n*m*k)
// Space complexity: O(m*k)
class Solution {
public:
    int numOfArrays(int n, int m, int k) {
        long long dp[m + 1][k + 1];
        long long prefix[m + 1][k + 1];
        long long prevDp[m + 1][k + 1];
        long long prevPrefix[m + 1][k + 1];
        memset(dp, 0, sizeof(dp));
        memset(prefix, 0, sizeof(prefix));
        memset(prevDp, 0, sizeof(prevDp));
        memset(prevPrefix, 0, sizeof(prevPrefix));
        int MOD = 1e9 + 7;
        for (int num = 1; num <= m; num++) {
            dp[num][1] = 1;
        }
        for (int i = 1; i <= n; i++) {
            if (i > 1) {
                memset(dp, 0, sizeof(dp));
            }
            memset(prefix, 0, sizeof(prefix));
            for (int maxNum = 1; maxNum <= m; maxNum++) {
                for (int cost = 1; cost <= k; cost++) {
                    long long ans = (maxNum * prevDp[maxNum][cost]) % MOD;
                    ans = (ans + prevPrefix[maxNum - 1][cost - 1]) % MOD;

                    dp[maxNum][cost] += ans;
                    dp[maxNum][cost] %= MOD;
                    
                    prefix[maxNum][cost] = (prefix[maxNum - 1][cost] + dp[maxNum][cost]);
                    prefix[maxNum][cost] %= MOD;
                }
            }
            // Can't reassign long long[][] in C++, need to manually override
            for (int maxNum = 0; maxNum <= m; maxNum++) {
                for (int cost = 0; cost <= k; cost++) {
                    prevDp[maxNum][cost] = dp[maxNum][cost];
                    prevPrefix[maxNum][cost] = prefix[maxNum][cost];
                }
            }
        }
        return prefix[m][k];
    }
};

                    

