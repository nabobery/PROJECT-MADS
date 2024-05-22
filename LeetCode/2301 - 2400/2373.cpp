// 2373. Largest Local Values in a Matrix

// Simple Solution 1
// Time complexity: O(n^2)
// Space complexity: O(n^2)
class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> res(n-2, vector<int>(n-2, 0));
        for(int i = 1; i < n-1;i++)
            for(int j = 1; j < n-1;j++)
                for(int k = i-1; k <= i+1; k++)
                    for(int l = j-1; l <= j+1;l++)
                        res[i-1][j-1] = max(res[i-1][j-1], grid[k][l]);
        return res;
    }
};