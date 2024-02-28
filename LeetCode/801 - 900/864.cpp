// 864. Shortest Path to Get All Keys

// Solution 1 using BFS and bitmask
// Time complexity: O(m*n*2^k)
// Space complexity: O(m*n*2^k)

// Solution using BFS to find the shortest path to get all keys and using bitmask to keep track of the keys
class Solution {
public:
    int shortestPathAllKeys(vector<string>& grid) {
        int m = grid.size(), n = grid[0].size();
        int x, y, k = 0;
        // find the number of keys and the starting position
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                char c = grid[i][j];
                if (c == '@') {
                    x = i;
                    y = j;
                } else if (c >= 'a' && c <= 'f') {
                    k = max(k, c - 'a' + 1);
                }
            }
        }
        // maintain a queue of state{x, y, keys} and a visited array
        queue<tuple<int, int, int>> q;
        // push the starting position with 0 keys
        q.push({x, y, 0});
        vector<vector<vector<bool>>> visited(m, vector<vector<bool>>(n, vector<bool>(1 << k, false)));
        visited[x][y][0] = true;
        int steps = 0;
        // maintain the directions
        vector<int> dirs = {0, 1, 0, -1, 0};
        // while the queue is not empty
        while (!q.empty()) {
            int size = q.size();
            // for each state in the current level
            while (size--) {
                auto [i, j, keys] = q.front();
                q.pop();
                // if all keys are found return the steps
                if (keys == (1 << k) - 1) 
                    return steps;
                // for each direction check if the next position is valid and push it to the queue
                for (int d = 0; d < 4; d++) {
                    int ni = i + dirs[d], nj = j + dirs[d + 1];
                    // if the next position is out of bounds or is a wall continue
                    if (ni < 0 || ni >= m || nj < 0 || nj >= n || grid[ni][nj] == '#') 
                        continue;
                    char c = grid[ni][nj];
                    // if the next position is a lock and the key is not found continue
                    if (c >= 'A' && c <= 'F' && !(keys & (1 << (c - 'A')))) 
                        continue;
                    // if the next position is a key update the keys
                    int nkeys = keys;
                    // update the keys using bitmask
                    if (c >= 'a' && c <= 'f') 
                        nkeys |= 1 << (c - 'a');
                    // if the next position is already visited continue
                    if (visited[ni][nj][nkeys]) 
                        continue;
                    // mark the next position as visited and push it to the queue
                    visited[ni][nj][nkeys] = true;
                    q.push({ni, nj, nkeys});
                }
            }
            steps++;
        }
        // if no path is found
        return -1;
    }
};