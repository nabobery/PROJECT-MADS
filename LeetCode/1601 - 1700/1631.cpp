// 1631. Path With Minimum Effort

// Solution 1 using dfs and binary search 
// Time complexity: O(n*m*log(max(heights)))
// Space complexity: O(n*m)
class Solution {
public:
    int n, m;
    bool visited[101][101];
    bool isInRange(pair<int,int> p){
        return ((p.first >= 0 && p.first < n) && (p.second >= 0 && p.second < m));
    }
    bool helper(vector<vector<int>>& heights , pair<int,int> curr, int diff,int k){
        if(curr.first ==  n-1 && curr.second == m-1){
            return k >= diff;
        }
        if(diff > k) return false;
        bool flag = false;
        visited[curr.first][curr.second] = true;
        if(isInRange({curr.first-1, curr.second}) && !visited[curr.first-1][curr.second]){
            int temp = max(diff, abs(heights[curr.first][curr.second] - heights[curr.first-1][curr.second]));
            flag |= helper(heights, {curr.first-1, curr.second}, temp, k);
        }
        if(isInRange({curr.first, curr.second-1}) && !visited[curr.first][curr.second-1]){
            int temp = max(diff, abs(heights[curr.first][curr.second] - heights[curr.first][curr.second-1]));
            flag |= helper(heights, {curr.first, curr.second-1}, temp, k);
        }
        if(isInRange({curr.first+1, curr.second}) && !visited[curr.first+1][curr.second]){
            int temp = max(diff, abs(heights[curr.first][curr.second] - heights[curr.first+1][curr.second]));
            flag |= helper(heights, {curr.first+1, curr.second}, temp, k);
        }
        if(isInRange({curr.first, curr.second+1}) && !visited[curr.first][curr.second+1]){
            int temp = max(diff, abs(heights[curr.first][curr.second] - heights[curr.first][curr.second+1]));
            flag |= helper(heights, {curr.first, curr.second+1}, temp, k);
        }
        return flag;
    }
    int minimumEffortPath(vector<vector<int>>& heights) {
        int l = 0, r = 1e6;
        n = heights.size(), m = heights[0].size();
        while(l < r){
            memset(visited, false, sizeof(visited));
            int mid = (l+r)/ 2;
            if(helper(heights,{0,0},0, mid)) r = mid;
            else l = mid+1;
        }
        return l;
    }
};

// Solution 2 using dijkstra's algorithm
// Time complexity: O(n*m*log(n*m))
// Space complexity: O(n*m)
class Solution {
public:
    const int directions[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size(), m = heights[0].size();
        priority_queue <pair<int, pair<int,int>>, vector<pair<int, pair<int,int>>>, greater<pair<int, pair<int,int>>>> pq;
        vector<vector<int>> dis(n, vector<int>(m, 1e6));
        dis[0][0] = 0;
        pq.push({0, {0, 0}});
        while(!pq.empty()) {
            pair<int, pair<int,int>> curr = pq.top(); 
            pq.pop();
            int d = curr.first, r = curr.second.first, c = curr.second.second;
            if(r==n-1 && c==m-1) return d;
            for(int i=0; i< 4; ++i) {
                int nx = r + directions[i][0], ny = c + directions[i][1];
                if(nx < 0 || nx >= n || ny < 0 || ny >= m)continue;
                int nd = max(d, abs(heights[nx][ny] - heights[r][c]));
                if (nd < dis[nx][ny]) {
                    dis[nx][ny] = nd;
                    pq.push({nd, {nx, ny}});
                }
            }
        }
        return 0;
    }
};