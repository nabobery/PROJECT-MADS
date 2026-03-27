// 2946. Matrix Similarity After Cyclic Shifts

// Solution 1: Straightforward simulation
// Time complexity: O(m * n), where m is the number of rows and n is the number of columns in the matrix.
// Space complexity: O(n)
class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        int m = mat.size(), n = mat[0].size();
        k %= n;
        if (k == 0)
            return true;

        for (int i = 0; i < m; i++) {
            vector<int> modifiedRow;
            if (i % 2 == 0) {
                modifiedRow = cyclicShift(mat[i], k, false);
            } else {
                modifiedRow = cyclicShift(mat[i], k, true);
            }
            if (mat[i] != modifiedRow)
                return false;
        }
        return true;
    }

    vector<int> cyclicShift(const vector<int>& row, int k, bool isRight) {
        int n = row.size();
        vector<int> shifted(n);
        for (int i = 0; i < n; i++) {
            int newIdx = isRight ? (i + k) % n : (i - k + n) % n;
            shifted[newIdx] = row[i];
        }
        return shifted;
    }
};