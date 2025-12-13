// 3531. Count Covered Buildings

// Solution 1: Greedy Approach by maintaining the bounds for each row and column
// Time Complexity: O(n) where n is the number of buildings
// Space Complexity: O(m) where m is the number of unique rows and columns
class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        int res = 0;
        unordered_map<int, pair<int,int>> rowToColumns, columnToRows;

        for (auto& b : buildings) {
            int r = b[0], c = b[1];

            if (!rowToColumns.count(r)) rowToColumns[r] = {c, c};
            else {
                rowToColumns[r].first = min(rowToColumns[r].first, c);
                rowToColumns[r].second = max(rowToColumns[r].second, c);
            }

            if (!columnToRows.count(c)) columnToRows[c] = {r, r};
            else {
                columnToRows[c].first = min(columnToRows[c].first, r);
                columnToRows[c].second = max(columnToRows[c].second, r);
            }
        }

        for (auto& b : buildings) {
            int r = b[0], c = b[1];
            if (rowToColumns[r].first < c && c < rowToColumns[r].second &&
                columnToRows[c].first < r && r < columnToRows[c].second)
                res++;
        }

        return res;
    }
};
