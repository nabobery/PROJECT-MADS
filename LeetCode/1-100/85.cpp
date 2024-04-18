// 85. Maximal Rectangle

// Solution 1 by ging through the matrix with left starting points which have 1 and checking for maximum rectangle possible
// Time Complexity: O((mn)^2)
// Space Complexity: O(1)
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m = matrix.size(), n = matrix[0].size(), res = 0;
        for(int i = 0; i < m; i++) 
            for(int j = 0; j < n; j++) 
                for(int row = i, colLen = n, col; row < m && matrix[row][j] == '1'; row++) {
                    for(col = j; col < n && matrix[row][col] == '1'; col++);
                    colLen = min(colLen, col-j);
                    res = max(res, (row-i+1) * colLen);
                }
        return res;
    }
};

// Solution 2 by using DP by precomputing the number of 1s to the right
// Time Complexity: O(mn^2)
// Space Complexity: O(mn)
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m = matrix.size(), n = matrix[0].size(), res = 0;
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for(int i = 0; i < m; i++) 
            for(int j = n-1; j >= 0; j--) 
                if(matrix[i][j] == '1') dp[i][j] = j == n-1 ? 1 : dp[i][j+1] + 1;
        for(int i = 0; i < m; i++) 
            for(int j = 0; j < n; j++) 
                for(int row = i, colLen = dp[i][j], col; row < m && matrix[row][j] == '1'; row++) {
                    colLen = min(colLen, dp[row][j]);
                    res = max(res, (row-i+1) * colLen);
                }
        return res;
    }
};

// Solution 3 by using stack based approach to find the maximum rectangle
// Time Complexity: O(mn)
// Space Complexity: O(n)
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m = matrix.size(), n = matrix[0].size(), res = 0;
        // heights vector to store the height of the rectangle
        vector<int> heights(n, 0);
        for(int i = 0; i < m; i++) {
            // updating the heights vector after each row
            for(int j = 0; j < n; j++) 
                heights[j] = matrix[i][j] == '1' ? heights[j] + 1 : 0;
            // stack to store the index of the heights vector    
            stack<int> st;
            // finding the maximum rectangle for each row
            for(int j = 0; j <= n; j++) {
                // if the current height is less than the previous height then pop the stack and calculate the area
                while(!st.empty() && (j == n || heights[st.top()] > heights[j])) {
                    int h = heights[st.top()];
                    st.pop();
                    int w = st.empty() ? j : j - st.top() - 1;
                    res = max(res, h * w);
                }
                // push the index of the height vector
                st.push(j);
            }
        }
        return res;
    }
};