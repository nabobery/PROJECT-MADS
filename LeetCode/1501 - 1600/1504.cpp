// 1504. Count Submatrices With All Ones

// Solution 1: Using Prefix Sum and Monotonic Stack
// Time Complexity: O(m*n)
// Space Complexity: O(m*n)
class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        int res = 0, m = mat.size(), n = mat[0].size();
        vector<vector<int>> prefix(m, vector<int>(n, 0));
        for(int i = 0; i < m;i++){
            for(int j = 0; j < n;j++){
                prefix[i][j] = mat[i][j];
                if(mat[i][j] && j > 0) prefix[i][j] += prefix[i][j-1];
            }
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int mi = INT_MAX;
                for (int k = i; k >= 0; k--) {  
                    if (prefix[k][j] == 0) break; 
                    mi = min(mi, prefix[k][j]);
                    res += mi;
                }
            }
        }
        return res;
    }
};