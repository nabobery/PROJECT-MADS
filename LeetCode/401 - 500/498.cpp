// 498. Diagonal Traverse

// Solution 1: Intuitive and Straight Forward (by grouping diagonals by sum of the indices)
// Time Complexity O(m*n)
// Space Complexity: O(m*n)
class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size(), p = 0;
        vector<int> res(m*n);
        vector<vector<int>> diagonals(m+n);
        for(int i = 0; i < m;i++)
            for(int j = 0; j < n;j++) diagonals[i+j].push_back(mat[i][j]);
        for(int i =0; i <m+n;i++){
            if(i%2 == 0){
                for(int j = diagonals[i].size()-1; j >= 0;j--) res[p++] = diagonals[i][j];
            }
            else{
                for(int j = 0; j < diagonals[i].size();j++) res[p++] = diagonals[i][j];
            }
        }
        return res;
    }
};
