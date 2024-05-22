// 861. Score After Flipping Matrix

// Solution 1 Greedy Approach by flipping the rows and columns
// Time complexity: O(n*m)
// Space complexity: O(1)

class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        int n = grid.size(),  m = grid[0].size();
        // flip the rows if the first element is 0
        for (int i = 0; i < n; i++) 
            if (grid[i][0] == 0) 
                for (int j = 0; j < m; j++) 
                    grid[i][j] = 1 - grid[i][j];
        // flip the columns if the number of 1s is less than the number of 0s
        for (int j = 1; j < m; j++) {
            int cnt = 0;
            for (int i = 0; i < n; i++) 
                cnt += grid[i][j];
            if (cnt * 2 < n) {
                for (int i = 0; i < n; i++) 
                    grid[i][j] = 1 - grid[i][j];
            }
        }
        // calculate the result
        int res = 0;
        for (int i = 0; i < n; i++) {
            int val = 0;
            for (int j = 0; j < m; j++) 
                val = val * 2 + grid[i][j];
            res += val;
        }
        return res;
    }
};

// Solution 2 Greedy Approach by not modifying the original matrix
// The idea is to traverse column wise and get the maximum of the number of 1s in each column and multiply it with 2^(m-1-j) where j is the column number and add it to the result
// Time complexity: O(n*m)
// Space complexity: O(1)

class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        int n = grid.size(),  m = grid[0].size();
        int res = 0;
        for (int j = 0; j < m; j++) {
            int cnt = 0;
            for (int i = 0; i < n; i++) 
                cnt += grid[i][j] ^ grid[i][0];
            res += max(cnt, n - cnt) * (1 << (m - 1 - j));
        }
        return res;
    }
};