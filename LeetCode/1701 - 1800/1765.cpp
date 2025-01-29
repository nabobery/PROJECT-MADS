// 1765. Map of Highest Peak

// Solution 1 using Counting
// Time complexity: O(m*n)
// Space Complexity: O(m*n)
class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int m = isWater.size(), n = isWater[0].size();
        vector<vector<int>> res(m, vector<int>(n, 1e5));
        for(int i = 0; i < m;i++)
            for(int j = 0; j < n;j++)
                if(isWater[i][j] == 1)
                    res[i][j] = 0;
        for(int i = 0; i < m;i++){
            for(int j = 0; j < n;j++){
                if(i > 0) res[i][j] = min(res[i][j], res[i - 1][j] + 1);
                if(j > 0) res[i][j] = min(res[i][j], res[i][j - 1] + 1);
            }
        }
        for(int i = m - 1; i >= 0;i--){
            for(int j = n - 1; j >= 0;j--){
                if(i < m - 1) res[i][j] = min(res[i][j], res[i + 1][j] + 1);
                if(j < n - 1) res[i][j] = min(res[i][j], res[i][j + 1] + 1);
            }
        }
        return res;
    }
};