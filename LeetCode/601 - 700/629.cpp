// 629. K Inverse Pairs Array

// Solution 1 Easy and Naive Recursion + Memoization
// Time Complexity  = O(n*k*k)
// Space Complexity = O(n*k)
class Solution {
public:
    const int mod = 1e9+7;
    int dp[1001][1001];
    int helper(int n, int k){
        // base case if no inversions, then only one way to arrange the array i.e. in increasing order
        if(k == 0) return 1;
        // if k = 1 then there are n-1 ways to arrange the array
        if(k == 1) return n-1;
        // if already calculated then return the value
        if(dp[n][k] != -1) return dp[n][k];
        long long res = 0;
        // if k >= 2 then we try to place the largest element to get k-i inversions
        for(int i = 0; i < n;i++){
            if(i > k) break;
            res += helper(n-1, k-i);
            res %= mod;
        }
        return dp[n][k] = res;
    }
    int kInversePairs(int n, int k) {
        memset(dp, -1, sizeof(dp));
        return helper(n,k);
    }
};

// Solution 2 Bottom Up DP 
// Time Complexity  = O(n*k*k)
// Space Complexity = O(n*k)
class Solution {
public:
    const int mod = 1e9+7;  
    int dp[1001][1001] = { 1 };
    int kInversePairs(int n, int k) {
        for (int i = 1; i <= n; ++i)
            for (int j = 0; j <= k; ++j)
                for (int p = 0; p <= min(j, i-1); ++p)
                    dp[i][j] = (dp[i][j] + dp[i-1][j-p]) % mod;
        return dp[n][k];
    }
};

// Solution 3 Bottom Up DP Time Optimized
// f(n, k) = f(n-1, k) + f(n-1, k-1) + f(n-1, k-2) + ... + f(n-1, k-n+1) --->(1)
// f(n, k-1) = f(n-1, k-1) + f(n-1, k-2) + f(n-1, k-3) + ... + f(n-1, k-n+1)+ f(n-1, k-n) --->(2)
// Using 1 and 2 we get f(n, k) = f(n, k-1) + f(n-1, k) - f(n-1, k-n)
// Idea is to use the fact that dp[i][j] = dp[i][j-1] + dp[i-1][j] - dp[i-1][j-i]
// Time Complexity  = O(n*k)
// Space Complexity = O(n*k)
class Solution {
public:
    const int mod = 1e9+7;  
    int dp[1001][1001] = { 0 };
    int kInversePairs(int n, int k) {
        for(int i = 0; i <= n; i++) dp[i][0] = 1;
        for(int i = 1; i <= n; i++){
            for(int j = 0; j <= k; j++){
                dp[i][j] = (dp[i-1][j] + (j > 0 ? dp[i][j-1] : 0)) % mod;
                if(j-i >= 0) dp[i][j] = (dp[i][j] - dp[i-1][j-i] + mod) % mod;
            }
        }
        return dp[n][k];
    }
};

// Solution 4 Bottom Up DP Space Optimized
// Time Complexity  = O(n*k)
// Space Complexity = O(k)
class Solution {
public:
    const int mod = 1e9+7;  
    int kInversePairs(int n, int k) {
        vector<int> dp(k+1, 0);
        dp[0] = 1;
        for(int i = 1; i <= n; i++){
            vector<int> temp(k+1, 0);
            temp[0] = 1;
            for(int j = 1; j <= k; j++){
                temp[j] = (dp[j] + (j > 0 ? temp[j-1] : 0)) % mod;
                if(j-i >= 0) temp[j] = (temp[j] - dp[j-i] + mod) % mod;
            }
            dp = temp;
        }
        return dp[k];
    }
};