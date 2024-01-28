// 1074. Number of Submatrices That Sum to Target

// Solution 1 using 2D prefix sum
// Time complexity: O(n^4)
// Space complexity: O(n^2)

class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size(), result = 0;
        // prefix[i][j] = sum of matrix[0][0] to matrix[i][j]
        int prefix[m][n];
        // fill the first row
        for(int i = 0; i < n;i++) prefix[0][i] = matrix[0][i];
        // fill the vertical sum
        for (int i = 1; i < m; i++)
            for (int j = 0; j < n; j++) 
                prefix[i][j] = matrix[i][j] + prefix[i-1][j];
        // fill the horizontal sum
        for (int i = 0; i < m; i++) 
            for (int j = 1; j < n; j++) 
                prefix[i][j] += prefix[i][j-1];
        // go through all the submatrices and get the sum
        // if the sum is equal to target, increment the result
        // Given x1, y1, x2, y2, the sum of the submatrix is prefix[x2][y2] - prefix[x1-1][y2] - prefix[x2][y1-1] + prefix[x1-1][y1-1]
        for(int r = 0; r < m;r++){
            for(int c = 0; c < n;c++){
                for(int i = 0; i <= r;i++){
                    for(int j = 0; j <= c;j++){
                        int res = prefix[r][c];
                        if(i > 0) res -= prefix[i-1][c];
                        if(j > 0) res -= prefix[r][j-1];
                        if(i > 0 && j > 0) res += prefix[i-1][j-1];
                        if(res == target) result++;
                    }
                }
            }
        }
        return result;
    }
};