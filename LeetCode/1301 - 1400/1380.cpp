// 1380. Lucky Numbers in a Matrix

// Solution 1 Brute Force
// Time Complexity: O(n*m*(n+m))
// Space Complexity: O(n+m)
class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<int> res;
        set<int> row, col;
        for(int i = 0; i < m;i++){
            for(int j = 0; j < n;j++){
                for(int k = 0; k < n;k++) row.insert(matrix[i][k]);
                for(int k = 0; k < m;k++) col.insert(matrix[k][j]);
                if(*row.begin() == *col.rbegin()) res.push_back(*row.begin());
                row.clear();
                col.clear();
            }
        }
        return res;
    }
};

// Solution 2 Optimized
// Time Complexity: O(n*m)
// Space Complexity: O(n+m)
class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<int> res;
        set<int> row, col;
        for(int i = 0; i< m;i++){
            int mi = 1e5;
            for(int j = 0; j < n;j++) mi = min(mi, matrix[i][j]);
            row.insert(mi);
        }
        for(int j = 0; j < n;j++){
            int mx = -1;
            for(int i = 0; i < m;i++) mx = max(mx, matrix[i][j]);
            col.insert(mx);
        }
        for(auto it : row)
            if(col.count(it)) res.push_back(it);
        return res;
    }
};

// More optimized Solution 2
// Time Complexity: O(n*m)
// Space Complexity: O(n+m)
class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<int> res;
        vector<int> row(m, 1e5), col(n, -1);
        for(int i = 0; i< m;i++){
            for(int j = 0; j < n;j++){
                row[i] = min(row[i], matrix[i][j]);
                col[j] = max(col[j], matrix[i][j]);
            }
        }
        for(int i = 0; i < m;i++)
            for(int j = 0; j < n;j++)
                if(row[i] == col[j]) res.push_back(row[i]);
        return res;
    }
};