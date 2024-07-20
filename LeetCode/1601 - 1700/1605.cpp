// 1605. Find Valid Matrix Given Row and Column Sums

// Solution 1 Greedy Approach
// Time Complexity: O(n*m)
// Space Complexity: O(n*m)

class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        int m = rowSum.size(), n = colSum.size();
        vector<vector<int>> res(m,  vector<int>(n, 0));
        for(int i = 0; i < m;i++){
            for(int j = 0; j < n;j++){
                int temp = min(rowSum[i], colSum[j]);
                if(temp > 0){
                    res[i][j] = temp;
                    rowSum[i] -= temp;
                    colSum[j] -= temp;
                }
            }
        }
        return res;
    }
};

// Cleaned Version of Solution 1
class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        int m = rowSum.size(), n = colSum.size();
        vector<vector<int>> res(m,  vector<int>(n, 0));
        for(int i = 0; i < m;i++){
            for(int j = 0; j < n;j++){
                res[i][j] = min(rowSum[i], colSum[j]);
                rowSum[i] -= res[i][j];
                colSum[j] -= res[i][j];
            }
        }
        return res;
    }
};