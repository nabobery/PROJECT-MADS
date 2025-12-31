// 1351. Count Negative Numbers in a Sorted Matrix

// Solution 1: Simple Iteration
// Time Complexity: O(m * n)
// Space Complexity: O(1)
class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int res = 0, m = grid.size(), n = grid[0].size();
        for(int i = 0; i < m;i++){
            for(int j = 0; j < n;j++){
                if(grid[i][j] < 0){
                    res += (n-j);
                    break;
                }
            }
        }
        return res;
    }
};

// Solution 2: Binary Search
// Time Complexity: O(m * log n)
// Space Complexity: O(1)
class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int res = 0, m = grid.size(), n = grid[0].size();
        for(int i = 0; i < m;i++){
            int left = 0, right = n - 1;
            while(left <= right){
                int mid = left + (right - left) / 2;
                if(grid[i][mid] < 0){
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }
            res += (n - left);
        }
        return res;
    }
};