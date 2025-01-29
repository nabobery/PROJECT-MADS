// 2017. Grid Game

// Solution 1 using prefix sum by chossing the minium possible maximum sum of robot 2
// Time complexity: O(n)
// Space complexity: O(1)
class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        long long res = LLONG_MAX;
        int n = grid[0].size(), ind = 0;
        vector<vector<long long>> prefix(2, vector<long long>(n+1, 0));
        for(int i = 0; i < 2;i++){
            for(int j = 0; j < n;j++){
                prefix[i][j+1] = prefix[i][j] + grid[i][j];
            }
        }
        for(int i = 0; i < n;i++)
            res = min(res, max(prefix[1][i], prefix[0][n] - prefix[0][i+1]));
        return res;
    }
};

// Efficient and cleaner Solution 1
class Solution {
    public:
    long long gridGame(vector<vector<int>>& grid) {
        long long firstRowSum = accumulate(begin(grid[0]), end(grid[0]), 0LL),
                  secondRowSum = 0;
        long long res = LONG_LONG_MAX;
        for (int turnIndex = 0; turnIndex < grid[0].size(); ++turnIndex) {
            firstRowSum -= grid[0][turnIndex];
            res = min(res, max(firstRowSum, secondRowSum));
            secondRowSum += grid[1][turnIndex];
        }
        return res;
    }
};