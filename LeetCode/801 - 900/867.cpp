// 867. Transpose Matrix

// Solution 1 : Aij = Aji
// Time Complexity: O(r*c)
// Space Complexity: O(r*c)
class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        vector<vector<int>> res(matrix[0].size(), vector<int>(matrix.size()));
        for(int i = 0;i < matrix.size();i++){
            for(int j = 0; j < matrix[i].size();j++){
                res[j][i] = matrix[i][j];
            }
        }
        return res;
    }
};