// 2906. Construct Product Matrix

// Solution 1: Using prefix and suffix products
// Time complexity: O(m*n)
// Space complexity: O(m*n)
class Solution {
public:
    const int mod = 12345;
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> res(m, vector<int>(n));
        long long prefix = 1, suffix = 1;
        vector<int> pre(m*n), suff(m*n);
        for(int i = 0; i < m;i++){
            for(int j = 0; j < n;j++){
                prefix *= grid[i][j];
                prefix %= mod;
                pre[i*n+j] = prefix;
            }
        }
        for(int i = m-1; i >= 0;i--){
            for(int j = n-1; j >= 0;j--){
                suffix *= grid[i][j];
                suffix %= mod;
                suff[i*n+j] = suffix;
            }
        }
        for(int i = 0; i < m;i++){
            for(int j = 0; j < n;j++){
                int idx = i*n+j;
                long long result = (idx > 0 ? pre[idx-1] : 1);
                result *= (idx < m*n - 1 ? suff[idx+1] : 1);
                result %= mod;
                res[i][j] = result;
            }
        }
        return res;
    }
};

// Solution 2: Using prefix and suffix products with optimization
// Time complexity: O(m*n)
// Space complexity: O(m*n)
class Solution {
public:
    const int mod = 12345;
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> res(m, vector<int>(n));
        long long p = 1;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                res[i][j] = p;
                p = (p * (grid[i][j] % mod)) % mod;
            }
        }

        long long s = 1;
        for (int i = m - 1; i >= 0; --i) {
            for (int j = n - 1; j >= 0; --j) {
                res[i][j] = (res[i][j] * s) % mod;
                s = (s * (grid[i][j] % mod)) % mod;
            }
        }

        return res;
    }
};