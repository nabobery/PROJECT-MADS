// 2482. Difference Between Ones and Zeros in Row and Column

// Solution 1 Straightforward and simple
// Time complexity: O(n*m)
// Space complexity: O(n*m)
class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<int> rows(n, 0), cols(m, 0);
        for(int i = 0;i < n;i++){
            for(int j = 0; j < m;j++){
                if(grid[i][j] == 1){
                    rows[i]++;
                    cols[j]++;
                }
            }
        }
        vector<vector<int>> res(n, vector<int>(m));
        for(int i = 0; i < n;i++){
            for(int j = 0; j < m;j++){
                res[i][j] = 2*(rows[i] + cols[j]) - (n+m);
            }
        }
        return res;
    }
};

