// 1559. Detect Cycles in 2D Grid

// Solution: BFS for each character's occurrences
// Time complexity: O((m*n)^2)
// Space complexity: O(m*n)
class Solution {
public:
    int m, n;
    const pair<int, int> dir[4] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    // Check if there is a cycle in the graph formed by the nodes with the same character
    bool hasCycle(vector<int>& nodes) {
        // Set to keep track of visited nodes during BFS
        unordered_set<int> seen;
        // Create a set of nodes that have the same character for O(1) lookups
        unordered_set<int> sameCharNodes(nodes.begin(), nodes.end());

        // Perform BFS for each unvisited node in the same character group
        for (int startNode : nodes) {
            if (seen.count(startNode))
                continue;

            queue<pair<int, int>> q;
            q.push({startNode, -1});
            seen.insert(startNode);

            // BFS to detect cycles
            while (!q.empty()) {
                auto [curr, parent] = q.front();
                q.pop();

                int r = curr / n;
                int c = curr % n;

                for (auto& d : dir) {
                    int nr = r + d.first;
                    int nc = c + d.second;
                    int neighbor = nr * n + nc;

                    if (nr >= 0 && nr < m && nc >= 0 && nc < n) {
                        if (sameCharNodes.count(neighbor)) {
                            if (seen.count(neighbor)) {
                                if (neighbor != parent)
                                    return true;
                            } else {
                                seen.insert(neighbor);
                                q.push({neighbor, curr});
                            }
                        }
                    }
                }
            }
        }
        return false;
    }

    bool containsCycle(vector<vector<char>>& grid) {
        vector<vector<int>> charToOccurrence(26);
        m = grid.size(), n = grid[0].size();
        // Map each character to its occurrences in the grid
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                charToOccurrence[grid[i][j] - 'a'].push_back(i * n + j);
            }
        }
        // Check for cycles for each character's occurrences
        for (int i = 0; i < 26; i++) {
            if (!charToOccurrence[i].empty()) {
                if (hasCycle(charToOccurrence[i])) {
                    return true;
                }
            }
        }
        return false;
    }
};

// Solution 2: DFS for each character's occurrences
// Time complexity: O(m*n)
// Space complexity: O(m*n)
class Solution {
    int m, n;
    int dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    // based on problem's constraints, we can use a fixed size array for visited nodes
    bool visited[500][500];
    // Check if there is a cycle in the graph formed by the nodes with the same character
    bool hasCycle(int r, int c, int pr, int pc, char val,
                  vector<vector<char>>& grid) {
        visited[r][c] = true;
        // Explore all four directions
        for (auto& d : dir) {
            int nr = r + d[0], nc = c + d[1];
            // Check if the neighbor is within bounds and has the same character
            if (nr >= 0 && nr < m && nc >= 0 && nc < n && grid[nr][nc] == val) {
                // If the neighbor is visited and it's not the parent, we found a cycle
                if (visited[nr][nc]) {
                    if (nr != pr || nc != pc)
                        return true;
                // If the neighbor is not visited, continue DFS recursively from that neighbor
                } else if (hasCycle(nr, nc, r, c, val, grid)) {

                    return true;
                }
            }
        }
        // If we explored all neighbors and didn't find a cycle, return false
        return false;
    }

public:
    bool containsCycle(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();
        // Check for cycles for each character's occurrences
        memset(visited, 0, sizeof(visited));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                // If the cell is not visited, start a DFS from that cell to check for cycles
                if (!visited[i][j]) {
                    if (hasCycle(i, j, -1, -1, grid[i][j], grid))
                        return true;
                }
            }
        }
        // If we checked all cells and didn't find any cycles, return false
        return false;
    }
};