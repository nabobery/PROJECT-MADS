// 3548. Equal Sum Grid Partition II

// Solution 1: Prefix Sum and Brute Force Check -> TLE
// Time Complexity: O(m*n*(m*n)) where m and n are the dimensions of the grid. We iterate through each possible partition and check the sums, which takes O(m*n) time for each partition.
// Space Complexity: O(1) as we are using only a constant amount of extra space
class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        long long totalSum = 0;
        for (const auto& row : grid) {
            for (int val : row)
                totalSum += val;
        }

        long long topSum = 0;
        for (int i = 0; i < m - 1; ++i) {
            for (int j = 0; j < n; ++j)
                topSum += grid[i][j];
            long long bottomSum = totalSum - topSum;
            if (isValid(topSum, bottomSum, 0, i, 0, n - 1, grid))
                return true;
            if (isValid(bottomSum, topSum, i + 1, m - 1, 0, n - 1, grid))
                return true;
        }

        long long leftSum = 0;
        for (int j = 0; j < n - 1; ++j) {
            for (int i = 0; i < m; ++i)
                leftSum += grid[i][j];
            long long rightSum = totalSum - leftSum;
            if (isValid(leftSum, rightSum, 0, m - 1, 0, j, grid))
                return true;
            if (isValid(rightSum, leftSum, 0, m - 1, j + 1, n - 1, grid))
                return true;
        }

        return false;
    }

private:
    // Check if we can make the sums equal by removing atmost one element from the specified subgrid / partition
    bool isValid(long long s1, long long s2, int r1, int r2, int c1, int c2,
                 const vector<vector<int>>& grid) {
        if (s1 == s2)
            return true;
        long long diff = s1 - s2;

        int rows = r2 - r1 + 1;
        int cols = c2 - c1 + 1;

        if (rows > 1 && cols > 1) {
            for (int i = r1; i <= r2; ++i) {
                for (int j = c1; j <= c2; ++j) {
                    if (grid[i][j] == diff)
                        return true;
                }
            }
        } else if (rows == 1) {
            if (grid[r1][c1] == diff || grid[r1][c2] == diff)
                return true;
        } else if (cols == 1) {
            if (grid[r1][c1] == diff || grid[r2][c1] == diff)
                return true;
        }
        return false;
    }
};

// Solution 2: Using Prefix Sum and Hash Set to maintain frequency of numbers in the current partition -> Accepted
// Time Complexity: O(m*n) where m and n are the dimensions of the grid. We iterate through each possible partition (m*n) and check the sums, which takes O(1) time for each partition.
// Space Complexity: O(m*n) in the worst case if all elements are unique and we store them in the hash set.
class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        long long totalSum = 0;
        unordered_map<int, int> fullFreq;
        
        for (const auto& row : grid) {
            for (int val : row) {
                totalSum += val;
                fullFreq[val]++;
            }
        }

        unordered_map<int, int> topFreq;
        unordered_map<int, int> bottomFreq = fullFreq;
        long long topSum = 0;

        for (int i = 0; i < m - 1; ++i) {
            for (int j = 0; j < n; ++j) {
                int val = grid[i][j];
                topSum += val;
                topFreq[val]++;
                if (--bottomFreq[val] == 0) bottomFreq.erase(val);
            }
            long long bottomSum = totalSum - topSum;

            if (check(topSum, bottomSum, 0, i, 0, n - 1, grid, topFreq)) return true;
            if (check(bottomSum, topSum, i + 1, m - 1, 0, n - 1, grid, bottomFreq)) return true;
        }

        unordered_map<int, int> leftFreq;
        unordered_map<int, int> rightFreq = fullFreq;
        long long leftSum = 0;

        for (int j = 0; j < n - 1; ++j) {
            for (int i = 0; i < m; ++i) {
                int val = grid[i][j];
                leftSum += val;
                leftFreq[val]++;
                if (--rightFreq[val] == 0) rightFreq.erase(val);
            }
            long long rightSum = totalSum - leftSum;

            if (check(leftSum, rightSum, 0, m - 1, 0, j, grid, leftFreq)) return true;
            if (check(rightSum, leftSum, 0, m - 1, j + 1, n - 1, grid, rightFreq)) return true;
        }

        return false;
    }

private:
    bool check(long long s1, long long s2, int r1, int r2, int c1, int c2, 
               const vector<vector<int>>& grid, const unordered_map<int, int>& freq) {
        if (s1 == s2) return true;
        long long diff = s1 - s2;
        if (diff > 2e9 || diff < -2e9) return false;

        int rows = r2 - r1 + 1;
        int cols = c2 - c1 + 1;

        if (rows > 1 && cols > 1) {
            return freq.count((int)diff);
        } else if (rows == 1) {
            return grid[r1][c1] == diff || grid[r1][c2] == diff;
        } else {
            return grid[r1][c1] == diff || grid[r2][c1] == diff;
        }
    }
};