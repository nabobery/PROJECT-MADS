// 48. Rotate Image

// rotating by 90 = transposing the matrix + reversing each row approx O(n^2) time
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        if(n == 1) return;
        for(int i = 0; i < n;i++){
            for(int j = i+1; j < n;j++)
                swap(matrix[i][j],matrix[j][i]);
        }
        for(int i = 0; i < n;i++){
            int low = 0, high = n-1;
            while(low < high){
                swap(matrix[i][low], matrix[i][high]);
                low++;
                high--;
            }
        }
    }
};

// Rotate Groups of Four Cells
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        if(n == 1) return;
        for(int i = 0; i < (n+1)/2;i++){
            for(int j = 0; j < n/2;j++){
                int temp = matrix[n-1-j][i];
                matrix[n - 1 - j][i] = matrix[n - 1 - i][n - j - 1];
                matrix[n - 1 - i][n - j - 1] = matrix[j][n - 1 -i];
                matrix[j][n - 1 - i] = matrix[i][j];
                matrix[i][j] = temp;
            }
        }
    }
};



