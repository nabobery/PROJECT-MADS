// 2965. Find Missing and Repeated Values

// Solution 1: Straightforward and simple
// Time complexity: O(n^2)
// Space complexity: O(n^2)

class Solution {
    public:
        vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
            vector<int> res(2, 0);
            int n = grid.size(), sum = 0, repeat = 1;
            vector<bool> vis(n*n, false);
            for(int i = 0; i < n;i++){
                for(int j = 0; j < n;j++){
                    if(!vis[grid[i][j] - 1])
                        vis[grid[i][j] - 1] = true;
                    else repeat = grid[i][j];
                    sum += grid[i][j];
                }
            }
            res[0] = repeat;
            res[1] = (pow(n, 4) + pow(n, 2))/2 - sum + repeat;
            return res;
        }
};

