// 935. Knight Dialer

// Solution 1 using Recursion + Memoization 
// Time complexity: O(n)
// Space complexity: O(n)
class Solution {
public:
    vector<vector<int>> dp;
    int mod = 1e9+7;
    vector<vector<int>> adj = {{4,6}, {6,8}, {7,9}, {4,8}, {0,3,9}, {}, {0,1,7},{2,6},{1,3}, {2,4}};
    int helper(int n, int d){
        if(n == 0) return 1;
        if(dp[n][d] != -1) return dp[n][d];
        if(d == 5) return 0;
        long long res = 0;
        for(auto it : adj[d]){
            res += helper(n-1, it)%mod;
            res %= mod;
        }
        return dp[n][d] = res; 
    }
    int knightDialer(int n) {
        dp.resize(n, vector<int>(10 , -1));
        long long res = 0;
        for(int i = 0; i <= 9;i++){
            res += helper(n-1, i)%mod;
            res %= mod;
        }
        return res;
    }
};

// Solution 2 using Bottom Up DP
// Time complexity: O(n)
// Space complexity: O(n)
class Solution {
public:
    int mod = 1e9+7;
    vector<vector<int>> adj = {{4,6}, {6,8}, {7,9}, {4,8}, {0,3,9}, {}, {0,1,7},{2,6},{1,3}, {2,4}};
    int knightDialer(int n) {
        vector<vector<int>> dp(n, vector<int>(10, 0));
        for(int i = 0; i <= 9;i++) dp[0][i] = 1;
        for(int i = 1; i < n;i++){
            for(int j = 0; j <= 9;j++){
                for(auto it : adj[j]){
                    dp[i][j] += dp[i-1][it];
                    dp[i][j] %= mod;
                }
            }
        }
        long long res = 0;
        for(int i = 0; i <= 9;i++){
            res += dp[n-1][i];
            res %= mod;
        }
        return res;
    }
};

// Solution 3 using Bottom Up DP with Space Optimization
// Time complexity: O(n)
// Space complexity: O(1)
class Solution {
public:
    int mod = 1e9+7;
    vector<vector<int>> adj = {{4,6}, {6,8}, {7,9}, {4,8}, {0,3,9}, {}, {0,1,7},{2,6},{1,3}, {2,4}};
    int knightDialer(int n) {
        vector<int> dp(10, 1);
        for(int i = 1; i < n;i++){
            vector<int> temp(10, 0);
            for(int j = 0; j <= 9;j++){
                for(auto it : adj[j]){
                    temp[j] += dp[it];
                    temp[j] %= mod;
                }
            }
            dp = temp;
        }
        long long res = 0;
        for(int i = 0; i <= 9;i++){
            res += dp[i];
            res %= mod;
        }
        return res;
    }
};

// Solution 4 using Linear Algebra (Matrix Multiplication)
// Time complexity: O(logn)
// Space complexity: O(1)

class Solution {
public:
    int mod = 1e9+7;
    // Matrix Multiplication Function 
    // If A - p xq matrix and B - q x r matrix then result will be p x r matrix
    vector<vector<long>> multiply(vector<vector<long>>& A, vector<vector<long>>& B) {
        vector<vector<long>> result(A.size(), vector<long>(B[0].size(), 0));
        
        for (int i = 0; i < A.size(); i++) {
            for (int j = 0; j < B[0].size(); j++) {
                for (int k = 0; k < B.size(); k++) {
                    result[i][j] = (result[i][j] + A[i][k] * B[k][j]) % mod;
                }
            }
        }
        
        return result;
    }
    int knightDialer(int n){
        vector<vector<long>> A = {{0,0,0,0,1,0,1,0,0,0},
                                  {0,0,0,0,0,0,1,0,1,0},
                                  {0,0,0,0,0,0,0,1,0,1},
                                  {0,0,0,0,1,0,0,0,1,0},
                                  {1,0,0,1,0,0,0,0,0,1},
                                  {0,0,0,0,0,0,0,0,0,0},
                                  {1,1,0,0,0,0,0,1,0,0},
                                  {0,0,1,0,0,0,1,0,0,0},
                                  {0,1,0,1,0,0,0,0,0,0},
                                  {0,0,1,0,1,0,0,0,0,0}};
        vector<vector<long>> res = {{1,1,1,1,1,1,1,1,1,1}};
        n--;
        while(n){
            if(n%2) res = multiply(res, A);
            A = multiply(A, A);
            n /= 2;
        }
        long long ans = 0;
        for(int i = 0; i < 10;i++){
            ans += res[0][i];
            ans %= mod;
        }
        return ans;
    }
};

