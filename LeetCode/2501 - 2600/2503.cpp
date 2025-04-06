// 2503. Maximum Number of Points From Grid Queries

// Solution 1: Using Sorting and Priority Queue
// The idea is to sort the queries and process them in order, using a priority queue to keep track of the maximum values in the grid.
// We start from the top-left corner of the grid and explore all possible paths, updating the maximum value seen so far.
// Time Complexity: O(nlogn + klogk), where n is the number of elements in the grid and k is the number of queries
// Space Complexity: O(n + k), where n is the number of elements in the grid and k is the number of queries
class Solution {
    public:
        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    
        bool isValid(int r, int c, int m, int n) {
            return r >= 0 && r < m && c >= 0 && c < n;
        }
    
        struct State {
            int max_val;
            int r;
            int c;
    
            bool operator>(const State& other) const {
                return max_val > other.max_val;
            }
        };
    
        vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
            int m = grid.size(), n = grid[0].size();
    
            int k = queries.size();
            vector<pair<int, int>> queries_with_indices(k);
            for (int i = 0; i < k; ++i) {
                queries_with_indices[i] = {queries[i], i};
            }
            sort(queries_with_indices.begin(), queries_with_indices.end());
    
            vector<int> results(k, 0);
            priority_queue<State, vector<State>, greater<State>> pq;
            vector<vector<bool>> visited(m, vector<bool>(n, false));
    
            pq.push({grid[0][0], 0, 0});
            int current_points = 0;
    
            for (int i = 0; i < k; ++i) {
                int current_query_limit = queries_with_indices[i].first;
                int original_index = queries_with_indices[i].second;
    
                while (!pq.empty() && pq.top().max_val < current_query_limit) {
                    State current = pq.top();
                    pq.pop();
    
                    int r = current.r;
                    int c = current.c;
                    int path_max = current.max_val;
    
                    if (visited[r][c]) continue;
    
                    visited[r][c] = true;
                    current_points++;
    
                    for (auto& dir : directions) {
                        int nr = r + dir.first;
                        int nc = c + dir.second;
    
                        if (isValid(nr, nc, m, n)) {
                            int next_path_max = max(path_max, grid[nr][nc]);
                            pq.push({next_path_max, nr, nc});
                        }
                    }
                }
                results[original_index] = current_points;
            }
    
            return results;
        }
};
    