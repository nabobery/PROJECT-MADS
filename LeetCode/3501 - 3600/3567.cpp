// 3567. Minimum Absolute Difference in Sliding Submatrix

// Solution 1: Brute Force
// Time Complexity: O(m * n * k^2)
// Space Complexity: O(k^2)
class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> res(m-k+1, vector<int>(n-k+1, 0));
        for(int i = 0; i < m-k+1;i++){
            for(int j = 0; j < n-k+1;j++){
                set<int> subMatrix;
                for(int l = i; l < i+k;l++){
                    for(int m = j; m < j+k;m++){
                        subMatrix.insert(grid[l][m]);
                    }
                }
                int minDiff = INT_MAX;
                if(subMatrix.size() == 1)
                    minDiff = 0;
                else{
                    auto prev = subMatrix.begin();
                    auto curr = prev;
                    curr++;
                    for(;curr != subMatrix.end(); curr++){
                        minDiff = min(abs(*prev - *curr), minDiff);
                        prev = curr;
                    }
                }
                res[i][j] = minDiff;
            }
        }
        return res;
    }
};


// Solution 2: Sliding Window + Multiset
// Time Complexity: O(m * n * log(k^2))
// Space Complexity: O(k^2)
class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> res(m - k + 1, vector<int>(n - k + 1));
        for (int i = 0; i <= m - k; ++i) {
            map<int, int> window;

            for (int r = i; r < i + k; ++r) {
                for (int c = 0; c < k; ++c) {
                    window[grid[r][c]]++;
                }
            }
            res[i][0] = calculateMin(window);

            for (int j = 1; j <= n - k; ++j) {
                for (int r = i; r < i + k; ++r) {
                    int valOut = grid[r][j - 1];
                    if (--window[valOut] == 0)
                        window.erase(valOut);
                    int valIn = grid[r][j + k - 1];
                    window[valIn]++;
                }
                res[i][j] = calculateMin(window);
            }
        }
        return res;
    }

private:
    int calculateMin(const map<int, int>& m) {
        if (m.size() < 2)
            return 0;
        int minD = INT_MAX;
        auto it = m.begin();
        int prev = it->first;
        for (++it; it != m.end(); ++it) {
            minD = min(minD, abs(it->first - prev));
            prev = it->first;
        }
        return minD;
    }
};