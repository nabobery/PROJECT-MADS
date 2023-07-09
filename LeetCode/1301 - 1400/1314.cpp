// 1314. Matrix Block Sum

// naive O(m^2*n) time and O(mn) space solution
class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        int m = mat.size(), n = mat[0].size();
        vector<vector<int>> prefixsum(m,vector<int>(n+1,0)), result(m,vector<int>(n,0));
        for(int i = 0; i < m;i++){
            for(int j = 1; j <= n;j++){
                prefixsum[i][j] += (mat[i][j-1] + prefixsum[i][j-1]);
            }
        }
        for(int i = 0; i < m;i++){
            int min_i = max(0, i-k), max_i = min(m-1,i+k);
            for(int j = 0; j < n;j++){
                int min_j = max(0,j-k), max_j = min(n,j+k+1);
                for(int l = min_i; l <= max_i;l++){
                    result[i][j] += (prefixsum[l][max_j] - prefixsum[l][min_j]);
                }
            }
        }
        return result;
    }
};


// O(mn) time and O(mn) space solution
class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        int m = mat.size(), n = mat[0].size();
        vector<vector<int>> prefixsum(m+1,vector<int>(n+1,0)), result(m,vector<int>(n,0));
        for(int i = 1; i <= m;i++){
            for(int j = 1; j <= n;j++){
                prefixsum[i][j] += (mat[i-1][j-1] + prefixsum[i-1][j] + prefixsum[i][j-1] - prefixsum[i-1][j-1]);
            }
        }
        for(int i = 0; i < m;i++){
            int min_i = max(0, i-k), max_i = min(m,i+k+1);
            for(int j = 0; j < n;j++){
                int min_j = max(0,j-k), max_j = min(n,j+k+1);
                result[i][j] = (prefixsum[max_i][max_j] - prefixsum[max_i][min_j] - prefixsum[min_i][max_j] + prefixsum[min_i][min_j]);
            }
        }
        return result;
    }
};

