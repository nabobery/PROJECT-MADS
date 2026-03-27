// 1886. Determine Whether Matrix Can Be Obtained By Rotation

// Solution 1: Brute Force, check all 4 rotations
// Time Complexity: O(n^2)
// Space Complexity: O(n^2)
class Solution {
public:
    void rotate(vector<vector<int>>& mat){
        int n = mat.size();
        vector<vector<int>> rotated(n, vector<int>(n));
        for(int i = 0; i < n;i++){
            for(int j = 0; j < n;j++){
                rotated[j][n-1-i] = mat[i][j];
            }
        }
        mat = rotated;
    }
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        if(mat == target) return true;
        for(int i = 0; i < 3;i++){
            rotate(mat);
            if(mat == target) return true;
        }
        return false;
    }
};

// Solution 2: Check all 4 rotations without creating new matrix
// Time Complexity: O(n^2)
// Space Complexity: O(1)
class Solution {
public:
    void rotate(vector<vector<int>>& mat) {
        int n = mat.size();
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                swap(mat[i][j], mat[j][i]);
            }
        }
        for (int i = 0; i < n; i++) {
            reverse(mat[i].begin(), mat[i].end());
        }
    }

    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        for (int i = 0; i < 4; i++) {
            if (mat == target)
                return true;
            rotate(mat);
        }
        return false;
    }
};
