// 3342. Find Minimum Time to Reach Last Room II

// Solution: By Dijkstra's algorithm and maintaining a state of the current room
// Time Complexity: O(n log n) where n is the number of rooms
// Space Complexity: O(n) where n is the number of rooms
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
            vector<vector<int>> state(n, vector<int>(m, -1));
            pq.push({0 , 0});
            state[0][0] = 0;
            while(!pq.empty()){
                auto [time, cell] = pq.top();
                pq.pop();
                int ci = cell/m, cj = cell % m;
                for(auto [x, y]: directions){
                    int ni = x + ci, nj = y + cj;
                    if(ni >= 0 && ni < n && nj >= 0 && nj < m && state[ni][nj] == -1){
                        int cost = (state[ci][cj] == 1 ? 2 : 1);
                        int newTime = max(time, moveTime[ni][nj])+ cost;
                        if(ni == n-1 && nj == m-1) return newTime;
                        pq.push({newTime, ni*m + nj});
                        state[ni][nj] = 1 - state[ci][cj];
                    }
                }
            }
            return -1;
        }
};