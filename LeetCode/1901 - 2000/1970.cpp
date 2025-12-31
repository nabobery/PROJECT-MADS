// 1970. Last Day Where You Can Still Cross

// Solution 1: Binary Search + BFS
// Time Complexity: O(R * C * log(R * C))
// Space Complexity: O(R * C)
class Solution {
private:
    int R, C;

public:
    bool canCross(int day, vector<vector<int>>& cells) {
        vector<vector<int>> grid(R, vector<int>(C, 0));
        for (int i = 0; i < day; ++i) {
            grid[cells[i][0] - 1][cells[i][1] - 1] = 1;
        }

        queue<pair<int, int>> q;
        for (int c = 0; c < C; ++c) {
            if (grid[0][c] == 0) {
                q.push({0, c});
                grid[0][c] = 1;
            }
        }

        int dr[] = {0, 0, 1, -1};
        int dc[] = {1, -1, 0, 0};

        while (!q.empty()) {
            pair<int, int> current = q.front();
            q.pop();
            int r = current.first;
            int c = current.second;

            if (r == R - 1) return true;

            for (int i = 0; i < 4; ++i) {
                int nr = r + dr[i];
                int nc = c + dc[i];

                if (nr >= 0 && nr < R && nc >= 0 && nc < C && grid[nr][nc] == 0) {
                    grid[nr][nc] = 1;
                    q.push({nr, nc});
                }
            }
        }

        return false;
    }

    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        this->R = row;
        this->C = col;
        
        int left = 1, right = cells.size();
        int res = 0;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (canCross(mid, cells)) {
                res = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return res;
    }
};