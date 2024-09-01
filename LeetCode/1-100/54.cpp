// 54. Spiral Matrix

// Solution 1 using DFS
// Time complexity: O(m*n)
// Space complexity: O(1)
class Solution {
public:
    unordered_set<int> s;
    int m, n;
    void helper(int i, int j, char dir, vector<int>& res, vector<vector<int>>& matrix){
        if(i < 0 || i >= m || j < 0 || j >= n || s.count(i*n + j)) return;
        cout<<matrix[i][j]<<"\n";
        res.push_back(matrix[i][j]);
        s.insert(i*n + j);
        if(dir == 'E'){
            if(s.count(i*n + j+1) || j+1 >= n){
                dir = 'S';
                helper(i+1, j, dir, res, matrix);
            }
            else helper(i, j+1, dir, res, matrix);
        }
        else if(dir == 'S'){
            if(s.count((i+1)*n + j) || i+1 >= m){
                dir = 'W';
                helper(i, j-1, dir, res, matrix);
            }
            else helper(i+1, j, dir, res, matrix);
        }
        else if(dir == 'W'){
            if(s.count(i*n + j-1) || j-1 < 0){
                dir = 'N';
                helper(i-1, j, dir, res, matrix);
            }
            else helper(i, j-1, dir, res, matrix);
        }
        else{
            if(s.count((i-1)*n + j) || i-1 < 0){
                dir = 'E';
                helper(i, j+1, dir, res, matrix);
            }
            else helper(i-1, j, dir, res, matrix);
        }
    }
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        m = matrix.size(); 
        n =matrix[0].size();
        vector<int> res;
        helper(0 , 0, 'E', res, matrix);
        return res;
    }
};

// Solution 2 using simulation
// Time complexity: O(m*n)
// Space complexity: O(1)
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<int> res;
        int top = 0, bottom = m-1, left = 0, right = n-1;
        while(top <= bottom && left <= right){
            for(int i = left; i <= right; i++) res.push_back(matrix[top][i]);
            for(int i = top+1; i <= bottom; i++) res.push_back(matrix[i][right]);
            if(top < bottom && left < right){
                for(int i = right-1; i >= left; i--) res.push_back(matrix[bottom][i]);
                for(int i = bottom-1; i > top; i--) res.push_back(matrix[i][left]);
            }
            top++;
            bottom--;
            left++;
            right--;
        }
        return res;
    }
};