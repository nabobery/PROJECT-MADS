// 1582. Special Positions in a Binary Matrix

// Solution 1 Naive and Simple
// Time complexity: O(n*m *max(n, m)
// Space complexity: O(1)
class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size(), result = 0;
        for(int i = 0;i < n;i++){
            for(int j = 0; j < m;j++){
                if(mat[i][j] == 1){
                    bool b = true;
                    for(int k = 0; k < n;k++){
                        if(mat[k][j] == 1 && i != k){
                            b = false;
                            break;
                        }
                    }
                    for(int k = 0; k < m;k++){
                        if(mat[i][k] == 1 && j != k){
                            b = false;
                            break;
                        }
                    }
                    if(b) result++;
                }
            }
        }
        return result;
    }
};


// Solution 2
// Time complexity: O(n*m)
// Space complexity: O(n + m)
class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size(), result = 0;
        vector<int> row(n, 0), col(m, 0);
        for(int i = 0;i < n;i++){
            for(int j = 0; j < m;j++){
                if(mat[i][j] == 1){
                    row[i]++;
                    col[j]++;
                }
            }
        }
        for(int i = 0;i < n;i++){
            for(int j = 0; j < m;j++){
                if(mat[i][j] == 1 && row[i] == 1 && col[j] == 1){
                    result++;
                }
            }
        }
        return result;
    }
};