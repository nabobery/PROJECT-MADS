// 2641. Cousins in Binary Tree II

// Solution 1 using 2D DP
// Time complexity: O(n*m)
// Space complexity: O(n*m)
class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        int max_length = 0;
        vector<vector<int>> dp(rows + 1,vector<int>(cols + 1,0));
        for(int i = 1; i <= rows;i++){
            for(int j = 1; j <= cols;j++){
                if(matrix[i-1][j-1])
                    dp[i][j] = min(min(dp[i-1][j],dp[i][j-1]),dp[i-1][j-1]) + 1;
            }
        }
        int res = 0;
        for(int i = 1; i <= rows;i++)
            for(int j = 1; j <= cols;j++)
                res += dp[i][j];  
        return res;
    }
};

// Solution 2 using 1D DP
// Time complexity: O(n*m)
// Space complexity: O(m)
class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int rows = matrix.size(), cols = matrix[0].size(),  res = 0;
        vector<int> prev(cols+1, 0);
        for(int i = 1; i <= rows;i++){
            vector<int> curr(cols+1, 0);
            for(int j = 1; j <= cols;j++){
                if(matrix[i-1][j-1])
                    curr[j] = min(min(prev[j],curr[j-1]),prev[j-1]) + 1;
            }
            res += accumulate(curr.begin(), curr.end(), 0);
            prev = curr;
        }
        return res;
    }
};