// 1220. Count Vowels Permutation

// Solution 1 using Recursion + DP (Top Down)
// Time complexity: O(n)
// Space complexity: O(n)

class Solution {
public:
    int mod = 1e9+7;
    int helper(int i, int j, vector<vector<int>>& dp){
        if(dp[i][j] != -1) return dp[i][j];
        long long int res = 0;
        if(j == 0){
            res += helper(i-1,1,dp);
            res += helper(i-1,2,dp);
            res += helper(i-1,4,dp);
        }
        else if(j == 1){
            res += helper(i-1,0,dp);
            res += helper(i-1,2,dp);
        }
        else if(j == 2){
            res += helper(i-1,1,dp);
            res += helper(i-1,3,dp);
        }
        else if(j == 3){
            res += helper(i-1,2,dp);
        }
        else {
            res += helper(i-1,2,dp);
            res += helper(i-1,3,dp);
        }
        return dp[i][j] = res%mod;
    }
    int countVowelPermutation(int n) {
        vector<vector<int>> dp(n, vector<int>(5, -1));
        for(int i = 0; i < 5;i++) dp[0][i] = 1;
        long long int res = 0;
        for(int i = 0; i < 5;i++){
            res += helper(n-1, i, dp);
            res %= mod;
        }
        return res;
    }
};

// Solution 2 using Iterative + DP (Bottom Up)
// Time complexity: O(n)
// Space complexity: O(n)

class Solution {
public:
    int mod = 1e9+7;
    int countVowelPermutation(int n) {
        vector<vector<long long>> dp(n, vector<long long>(5, 0));
        for(int i = 0; i < 5;i++) dp[0][i] = 1;
        for(int i = 1; i < n;i++){
            dp[i][0] = (dp[i-1][1] + dp[i-1][2] + dp[i-1][4])%mod;
            dp[i][1] = (dp[i-1][0] + dp[i-1][2])%mod;
            dp[i][2] = (dp[i-1][1] + dp[i-1][3])%mod;
            dp[i][3] = (dp[i-1][2])%mod;
            dp[i][4] = (dp[i-1][2] + dp[i-1][3])%mod;
        }
        long long int res = 0;
        for(int i = 0; i < 5;i++){
            res += dp[n-1][i];
            res %= mod;
        }
        return res;
    }
};

// Solution 3 using Space Optimized Iterative + DP (Bottom Up)
// Time complexity: O(n)
// Space complexity: O(1)

class Solution {
public:
    int mod = 1e9+7;
    int countVowelPermutation(int n) {
        vector<long long> dp(5, 1);
        for(int j = 1; j < n;j++){
            long long a = (dp[1] + dp[2] + dp[4])%mod;
            long long e = (dp[0] + dp[2])%mod;
            long long i = (dp[1] + dp[3])%mod;
            long long o = (dp[2])%mod;
            long long u = (dp[2] + dp[3])%mod;
            dp[0] = a;
            dp[1] = e;
            dp[2] = i;
            dp[3] = o;
            dp[4] = u;
        }
        long long int res = 0;
        for(int i = 0; i < 5;i++){
            res += dp[i];
            res %= mod;
        }
        return res;
    }
};

// Solution 4 using Matrix Exponentiation
// This problem basically boils down to number of paths of length N in a directed graph.
// Time complexity: O(logn)
// Space complexity: O(1)

class Solution {
public:
    int mod = 1e9+7;
    vector<vector<int>> multiply(vector<vector<int>>& a, vector<vector<int>>& b){
        vector<vector<int>> res(5, vector<int>(5, 0));
        for(int i = 0; i < 5;i++){
            for(int j = 0; j < 5;j++){
                for(int k = 0; k < 5;k++){
                    res[i][j] += ((long long) a[i][k]*b[k][j])%mod;
                    res[i][j] %= mod;
                }
            }
        }
        return res;
    }
    int countVowelPermutation(int n) {
        vector<vector<int>> mat = {{0,1,0,0,0},
                                   {1,0,1,0,0},
                                   {1,1,0,1,1},
                                   {0,0,1,0,1},
                                   {1,0,0,0,0}}, res(5, vector<int>(5, 0));
        for(int i = 0; i < 5;i++) res[i][i] = 1;
        n--;
        while(n){
            if(n&1) res = multiply(res, mat);
            mat = multiply(mat, mat);
            n >>= 1;
        }
        long long int ans = 0;
        for(int i = 0; i < 5;i++){
            for(int j = 0; j < 5;j++){
                ans += res[i][j];
                ans %= mod;
            }
        }
        return ans;
    }
};

