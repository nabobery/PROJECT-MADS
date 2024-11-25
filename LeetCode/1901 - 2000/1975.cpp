// 1975. Maximum Matrix Sum

// Solution 1 using Greedy Approach
// Time Complexity: O(N^2)
// Space Complexity: O(1)
// The idea is based on the fact that we can make all the elements positive by multiplying -1 to the negative elements except one if it has odd number of negative elements.
// Also, we can traverse the negative sign of the elements in the matrix and calculate the sum of the absolute values of the elements.
// if the number of negative elements is even, then we can simply add the sum of the absolute values of the elements.
// if the number of negative elements is odd, then we can add the sum of the absolute values of the elements and subtract the minimum absolute value from the sum.
class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long sum = 0;
        int min_abs = INT_MAX;
        int neg_count = 0;
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[i].size(); j++) {
                sum += abs(matrix[i][j]);
                if (matrix[i][j] < 0) {
                    neg_count++;
                    min_abs = min(min_abs, abs(matrix[i][j]));
                }
            }
        }
        if (neg_count % 2 == 0) {
            return sum;
        }
        return sum - 2 * min_abs;
    }
};