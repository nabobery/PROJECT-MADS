// 2257. Count Unguarded Cells in the Grid

// Solution 1: Traversal using Set
// Time complexity: O(mnlogn)
// Space complexity: O(mn)
class Solution {
public:
    const int dirs[4][2] = {
        {0, 1},  // Move right
        {1, 0},  // Move down
        {0, -1}, // Move left
        {-1, 0}  // Move up
    };
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        int res = n*m;
        set<pair<int,int>> w, g;
        for(auto wall : walls){
            w.insert({wall[0], wall[1]});
            visited[wall[0]][wall[1]] = true;
        }
        for(auto guard: guards)
            g.insert({guard[0], guard[1]});
        for(auto guard: guards){
            visited[guard[0]][guard[1]] = true;
            for(int i = 0; i < 4;i++){
                int x = guard[0], y = guard[1];
                while(true){
                    x += dirs[i][0];
                    y += dirs[i][1];
                    if(w.count({x, y}) || x >= m || y >= n || x < 0 || y < 0 || g.count({x, y})) break;
                    visited[x][y] = true;
                }
            }
        }
        for(auto i : visited)
            for(auto b : i) if(b) res--;
        return res;
    }
};

// Solution 2: Traversal using states in visited array
// Time complexity: O(mn)
// Space complexity: O(mn)
class Solution {
public:
    const int dirs[4][2] = {
        {0, 1},  // Move right
        {1, 0},  // Move down
        {0, -1}, // Move left
        {-1, 0}  // Move up
    };
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        int res = n*m;
        set<pair<int,int>> w, g;
        for(auto wall : walls){
            w.insert({wall[0], wall[1]});
            visited[wall[0]][wall[1]] = true;
        }
        for(auto guard: guards)
            g.insert({guard[0], guard[1]});
        for(auto guard: guards){
            visited[guard[0]][guard[1]] = true;
            for(int i = 0; i < 4;i++){
                int x = guard[0], y = guard[1];
                while(true){
                    x += dirs[i][0];
                    y += dirs[i][1];
                    if(w.count({x, y}) || x >= m || y >= n || x < 0 || y < 0 || g.count({x, y})) break;
                    visited[x][y] = true;
                }
            }
        }
        for(auto i : visited)
            for(auto b : i) if(b) res--;
        return res;
    }
};