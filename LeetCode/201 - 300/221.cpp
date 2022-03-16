//221. Maximal Square
// Not space optimised Time complexity and space compplexity O(rows)(cols)
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        int max_length = 0;
        vector<vector<int>> dp(rows + 1,vector<int>(cols + 1,0));
        for(int i = 1; i <= rows;i++){
            for(int j = 1; j <= cols;j++){
                if(matrix[i-1][j-1] == '1'){
                    dp[i][j] = min(min(dp[i-1][j],dp[i][j-1]),dp[i-1][j-1]) + 1;
                    max_length = max(max_length,dp[i][j]);
                }
            }
        }
        return max_length*max_length;
    }
};

// memory optimised O(cols)
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        int max_length = 0, prev = 0;
        //vector<int> dp(cols + 1, 0);
        int dp[cols + 1];
        for(int i = 0; i <= cols;i++)
            dp[i] = 0;
        for(int i = 1; i <= rows;i++){
            for(int j = 1; j <= cols;j++){
                int temp = dp[j];
                if(matrix[i-1][j-1] == '1'){
                    dp[j] = min(min(dp[j-1],prev),dp[j]) + 1;
                    max_length = max(max_length,dp[j]);
                }
                else{
                    dp[j] = 0;
                }
                prev = temp;
            }
        }
        return max_length*max_length;
    }
};