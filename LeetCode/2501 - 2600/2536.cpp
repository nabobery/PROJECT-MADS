// 2536. Increment Submatrices by One

// Solution 1: Using 2D Line Sweep Algorithm
// Time Complexity: O(q + n^2)
// Space Complexity: O(n^2)
class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        // Create a 2D prefix sum array to store the increments and decrements
        vector<vector<int>> diff(n+1, vector<int>(n+1, 0)), res(n, vector<int>(n));
        for(auto& query: queries){
            int r1 = query[0], c1 = query[1], r2 = query[2], c2 = query[3];
            // mark the corners for the 2D difference array
            // top-left corner (this is where we add 1 until we reach the bottom-right corner)
            diff[r1][c1] += 1;
            // bottom-left corner (this is where we subtract 1)
            diff[r2+1][c1] -= 1;
            // top-right corner (this is where we subtract 1)
            diff[r1][c2+1] -= 1;
            // bottom-right corner (this is where we add 1 back because it was subtracted twice)
            diff[r2+1][c2+1] += 1; 
        }
        // sweep the line horizontally
        for(int i = 0; i < n;i++){
            for(int j = 1; j < n;j++) diff[i][j] += diff[i][j-1]; 
        }
        // sweep the line vertically
        for(int j = 0; j < n;j++){
            for(int i = 1; i < n;i++) diff[i][j] += diff[i-1][j];
        }
        // copy the result to the output matrix
        for(int i = 0; i < n;i++){
            for(int j = 0; j < n;j++) res[i][j] = diff[i][j];
        }
        return res;
    }
};