// 407. Trapping Rain Water II

// Solution 1 using BFS and Priority Queue
// Time complexity: O(m*N*log(m*n))
// Space Complexity: O(m*n)
class Solution {
public:
    // to check if the cell is valid
    bool isValid(int i, int j, int m, int n){
        return i >= 0 && i < m && j >= 0 && j < n;
    }
    int trapRainWater(vector<vector<int>>& heightMap) {
        int m = heightMap.size(), n = heightMap[0].size();
        // if the grid is less than 3*3, then we can't trap any water
        if(m < 3 || n < 3) return 0;
        // A priority queue to store the height of the cell and its coordinates (min heap)
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        // Push the boundary cells into the priority queue
        for(int i = 0; i < m; i++) {
            pq.push({heightMap[i][0], {i, 0}});
            pq.push({heightMap[i][n - 1], {i, n - 1}});
            visited[i][0] = visited[i][n - 1] = true;
        }
        for(int i = 1; i < n - 1; i++) {
            pq.push({heightMap[0][i], {0, i}});
            pq.push({heightMap[m - 1][i], {m - 1, i}});
            visited[0][i] = visited[m - 1][i] = true;
        }
        vector<vector<int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        int res = 0;
        // BFS from the boundary cells and go through the cells with lower height first
        // because the water can only be trapped by the lower height cell when compared to the current cell
        while(!pq.empty()){
            auto curr = pq.top();
            pq.pop();
            int h = curr.first, i = curr.second.first, j = curr.second.second;
            for(auto& dir : dirs){
                int nx = i + dir[0], ny = j + dir[1];
                if(isValid(nx, ny, m, n) && !visited[nx][ny]){
                    res += max(0, h - heightMap[nx][ny]);
                    pq.push({max(h, heightMap[nx][ny]), {nx, ny}});
                    visited[nx][ny] = true;
                }

            }
        }
        return res;
    }
};
