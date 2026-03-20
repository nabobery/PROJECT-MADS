// 3070. Count Submatrices with Top-Left Element and Sum Less Than k

// Solution 1: Prefix Sum
// Time Complexity: O(m * n)
// Space Complexity: O(1) 
class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int res = 0, m = grid.size(), n = grid[0].size();
        for(int i = 0; i < m;i++){
            for(int j = 0; j < n;j++){
                if(i > 0) grid[i][j] += grid[i-1][j];
                if(j > 0) grid[i][j] += grid[i][j-1];
                if(i > 0 && j > 0) grid[i][j] -= grid[i-1][j-1];
                if(grid[i][j] <= k) res++;
            }
        } 
        return res;
    }
};