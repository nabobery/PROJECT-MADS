// 74. Search a 2D Matrix
// my naive nlog(m) time solution
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        for(int i = 0; i < n;i++){
            if(matrix[0][i] <= target && matrix[m-1][i] >= target){
                int l = 0, r = m-1;
                while(l <= r){
                    int mid = l + (r-l)/2;
                    if(matrix[mid][i] == target) return true;
                    if(matrix[mid][i] < target) l = mid+1;
                    else r = mid-1;
                }
            }
            else{
                continue;
            }
        }
        return false;
    }
};

// O(m+n) time solution
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int s = matrix[0][0], l = matrix[m-1][n-1];
        if(target < s || target > l) return false;
        int i = 0, j = n-1;
        while(i < m && j >= 0){
            if(matrix[i][j] == target) return true;
            if(matrix[i][j] > target) j--;
            else i++;
        }
        return false;
    }
};

