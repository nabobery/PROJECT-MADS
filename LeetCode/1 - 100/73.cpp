// 73. Set Matrix Zeroes

// Solution 1: O(m+n) space complexity solution
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        set<int> rows, cols;
        int m = matrix.size(), n = matrix[0].size();
        for(int i = 0; i < m;i++){
            for(int j = 0; j < n;j++){
                if(!matrix[i][j]){
                    rows.insert(i);
                    cols.insert(j);
                }
            }
        }
        for(int i = 0; i < m;i++){
            for(int j = 0; j < n;j++){
                if(rows.count(i) || cols.count(j)) matrix[i][j] = 0;
            }
        }
    }
};

// Solution 2: O(1) space complexity solution
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        // boolean toset 1st column as zeroes
        bool col_0 = false;
        // traverse from 1st row to mth row
        for(int i = 0; i < m;i++){
            // if any of the elements in the 1st column are zero set it to true
            if(matrix[i][0] == 0) col_0 = true;
            // trvaerse from 2nd column to nth column
            for(int j = 1; j < n;j++){
                // if any of the elements zero
                if(!matrix[i][j]){
                    // set them as zero in their first row and column 
                    matrix[i][0] = matrix[0][j] = 0;
                }
            }
        }
        // traverse from the end and set the elements as zero based on the 1st row and 1st column markers
        for(int i = m-1; i >= 0; i--){
            for(int j = n-1; j >= 1;j--){
                if(!matrix[i][0] || !matrix[0][j]) matrix[i][j] = 0;
            }
            // if first column need to be set to zero
            if(col_0) matrix[i][0] = 0;
        }
        
    }
};

// Solution 3: O(1) space complexity solution (Easier to understand)
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        // booleans to check if the first row and column has zero
        bool isZeroCol = false, isZeroRow = false;
        for (int i = 0; i < matrix.size(); i++) { //check the first column
            if (!matrix[i][0]) {
                isZeroCol = true;
                break;
            } 
        }
        for (int i = 0; i < matrix[0].size(); i++) { //check the first row
            if (!matrix[0][i]) {
                isZeroRow = true;
                break;
            } 
        }
        for (int i = 1; i < matrix.size(); i++) { //check except the first row and column
            for (int j = 1; j < matrix[0].size(); j++) 
                if (!matrix[i][j]) {
                    matrix[i][0] = matrix[0][j] = 0;
                }
        }
        for (int i = 1; i < matrix.size(); i++) { //process except the first row and column
           for (int j = 1; j < matrix[0].size(); j++) 
               if (!matrix[i][0] || !matrix[0][j])
                   matrix[i][j] = 0;
        }
        if (isZeroCol) { //handle the first column
            for (int i = 0; i < matrix.size(); i++) 
                matrix[i][0] = 0;
        }
        if (isZeroRow) { //handle the first row
            for (int i = 0; i < matrix[0].size(); i++) 
                matrix[0][i] = 0;
        }
        
    }
};