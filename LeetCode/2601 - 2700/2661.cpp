// 2661. First Completely Painted Row or Column

// Solution 1 using Hash Map
// Time complexity: O(m*n)
// Space complexity: O(m+n)
class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vector<int> mat_ind(m*n, 0);
        for(int i = 0; i < m;i++)
            for(int j = 0; j < n;j++)
                mat_ind[mat[i][j] - 1] = i*n + j;
        vector<int> row_left(m, n), col_left(n, m);
        for(int i = 0; i < m*n;i++){
            int ind = mat_ind[arr[i]-1];
            int row = ind/n, col = ind%n;
            row_left[row]--;
            col_left[col]--;
            if(row_left[row] == 0 || col_left[col] == 0) return i;
        }
        return -1;
    }
};