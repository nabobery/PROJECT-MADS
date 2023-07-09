// 931. Minimum Falling Path Sum

// O(n^2) time and O(n^2) space solution
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> dp(n, vector<int>(n, 1e4));
        for(int i = 0; i < n;i++) dp[n-1][i] = matrix[n-1][i];
        for(int i = n-2; i >= 0; i--){
            for(int j = 0; j < n;j++){
                if(j > 0) dp[i][j] = min(dp[i][j], matrix[i][j] + dp[i+1][j-1]);
                if(j < n-1) dp[i][j] = min(dp[i][j], matrix[i][j] + dp[i+1][j+1]);
                dp[i][j] = min(dp[i][j], matrix[i][j] + dp[i+1][j]);
            }
        }
        int result = 1e4;
        for(int i = 0; i < n;i++) result = min(dp[0][i], result);
        return result;
    }
};

// O(n^2) time and O(1) space solution
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        for (int i = 1; i < matrix.size(); ++i)
            for (int j = 0; j < matrix.size(); ++j)
            matrix[i][j] += min({ matrix[i-1][j], matrix[i-1][max(0,j-1)], matrix[i-1][min((int)matrix.size()-1,j+1)] });
        return *min_element(begin(matrix[matrix.size() - 1]), end(matrix[matrix.size() - 1]));
    }
};
