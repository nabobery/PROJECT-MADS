// 1072. Flip Columns For Maximum Number of Equal Rows

// Solution 1: Using Hash Table and Greedy Bit Manipulation
// Time complexity: O(n*m)
// Space complexity: O(n)
class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        map<string, int> mp;
        for (int i = 0; i < m; i++) {
            string row;
            for (int j = 0; j < n; j++) 
                row += (matrix[i][j] == 1) ? '1' : '0';
            mp[row]++;
        }
        int res = 0;
        for(auto it : mp){
            string complement;
            for(auto ch : it.first) complement += (ch == '1') ? '0' : '1';
            res = max(res, it.second + mp[complement]);
        }
        return res;
    }
};

 