// 1926. Nearest Exit from Entrance in Maze

// Solution 1 using BFS 
// Time complexity: O(n*m)
// Space complexity: O(n*m)
class Solution {
public:
    const pair<int,int> dirs[4] = {{0,1},{0,-1},{1,0},{-1,0}};
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        queue<pair<int,int>> q;
        q.push({entrance[0], entrance[1]});
        int dis = 1, m = maze.size(), n = maze[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        visited[entrance[0]][entrance[1]] = true;
        while(!q.empty()){
            int s = q.size();
            for(int i = 0; i < s;i++){
                auto curr = q.front();
                q.pop();
                for(auto& dir : dirs){
                    pair<int,int> next = {curr.first+dir.first, curr.second+dir.second};
                    if(next.first >= 0 && next.first < m && next.second >= 0 && next.second < n && maze[next.first][next.second] == '.' && !visited[next.first][next.second]){
                        if(next.first == 0 || next.first == m-1 || next.second == n-1 || next.second == 0) return dis;
                        q.push(next);
                        visited[next.first][next.second] = true;
                    }
                }
            }
            dis++;
        }
        return -1;
    }
};

