// 3341. Find Minimum Time to Reach Last Room I

// Solution 1: Using Dijkstra's Algorithm
// Time Complexity: O(E log V) where E is the number of edges and V is the number of vertices
// Space Complexity: O(V) where V is the number of vertices
class Solution {
    public:
        vector<pair<int, int>> directions = {
            {0, -1},  // left
            {1, 0},   // down
            {-1, 0},  // up
            {0, 1}    // right
        };
        int minTimeToReach(vector<vector<int>>& moveTime) {
            priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
            int n = moveTime.size(), m = moveTime[0].size();
            vector<vector<bool>> visited(n, vector<bool>(m, false));
            visited[0][0] = true;
            pq.push({0 , 0});
            while(!pq.empty()){
                auto [time, cell] = pq.top();
                pq.pop();
                int ci = cell/m, cj = cell % m;
                for(auto [x, y]: directions){
                    int ni = x + ci, nj = y + cj;
                    if(ni >= 0 && ni < n && nj >= 0 && nj < m && !visited[ni][nj]){
                        int newTime = max(time, moveTime[ni][nj])+1;
                        if(ni == n-1 && nj == m-1) return newTime;
                        pq.push({newTime, ni*m + nj});
                        visited[ni][nj] = true;
                    }
                }
            }
            return -1;
        }
};