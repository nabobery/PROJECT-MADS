// 1292. Maximum Side Length of a Square with Sum Less than or Equal to Threshold

// Solution 1: Using Prefix Sum and Brute Force Search
// Time Complexity: O(m * n * min(m, n))
// Space Complexity: O(m * n)
class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>> prefixSum(m + 1, vector<int>(n + 1, 0));

        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                prefixSum[i][j] = mat[i - 1][j - 1] + prefixSum[i - 1][j] +
                                  prefixSum[i][j - 1] - prefixSum[i - 1][j - 1];
            }
        }

        int maxSide = 0;
        int minDim = min(m, n);

        for (int k = 1; k <= minDim; ++k) {
            bool found = false;
            for (int i = k; i <= m; ++i) {
                for (int j = k; j <= n; ++j) {
                    int currentSum = prefixSum[i][j] - prefixSum[i - k][j] -
                                     prefixSum[i][j - k] +
                                     prefixSum[i - k][j - k];
                    if (currentSum <= threshold) {
                        maxSide = k;
                        found = true;
                        break;
                    }
                }
                if (found)
                    break;
            }
            if (!found)
                break;
        }

        return maxSide;
    }
};

// Solution 2: Using Binary Search on Side Length and Prefix Sum
// Time Complexity: O(m * n * log(min(m, n)))
// Space Complexity: O(m * n)
class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>> prefixSum(m + 1, vector<int>(n + 1, 0));

        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                prefixSum[i][j] = mat[i - 1][j - 1] + prefixSum[i - 1][j] +
                                  prefixSum[i][j - 1] - prefixSum[i - 1][j - 1];
            }
        }

        int left = 1, right = min(m, n);
        int maxSide = 0;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            bool found = false;

            for (int i = mid; i <= m; ++i) {
                for (int j = mid; j <= n; ++j) {
                    int currentSum = prefixSum[i][j] - prefixSum[i - mid][j] -
                                     prefixSum[i][j - mid] +
                                     prefixSum[i - mid][j - mid];
                    if (currentSum <= threshold) {
                        found = true;
                        break;
                    }
                }
                if (found)
                    break;
            }

            if (found) {
                maxSide = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return maxSide;
    }
};