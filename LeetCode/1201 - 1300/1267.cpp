// 1267. Count Servers that Communicate

// Solution 1 using greedy approach and counting
// Time complexity: O(m*n)
// Space complexity: O(m+n)
class Solution
{
public:
    int countServers(vector<vector<int>> &grid)
    {
        int m = grid.size(), n = grid[0].size(), res = 0;
        vector<int> rows(m, 0);
        vector<int> cols(n, false);
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 1)
                {
                    rows[i]++;
                    cols[j]++;
                }
            }
        }
        for (int i = 0; i < m; i++)
            if (rows[i] != 1)
                res += rows[i];
        for (int i = 0; i < n; i++)
            if (cols[i] > 1)
                res += cols[i];
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 1 && rows[i] > 1 && cols[j] > 1)
                    res--;
            }
        }
        return res;
    }
};