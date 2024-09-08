// 874. Walking Robot Simulation

// Solution 1: Brute Force Simulation
// Time complexity: O(n)
// Space complexity: O(k)
class Solution {
public:
    const int directions[4][2] = {
        {0, 1},  // NORTH
        {1, 0},  // EAST
        {0, -1}, // SOUTH
        {-1, 0}  // WEST
    };
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        int curr[2] = {0,0};
        int res = 0, currentdir = 0;
        set<vector<int>> obs(obstacles.begin(), obstacles.end());
        for(int command : commands){
            if(command > 0){
                auto dir = directions[currentdir];
                bool x = (dir[0] != 0);
                for(int i = 0; i < command;i++){
                    if(x) curr[0] += dir[0];
                    else curr[1] += dir[1];
                    if(obs.count({curr[0], curr[1]})){
                        if(x) curr[0] -= dir[0];
                        else curr[1] -= dir[1];
                        break;
                    }
                }
                res = max(curr[0]*curr[0] + curr[1]*curr[1], res);
            }
            else{
                if(command == -1) currentdir = (currentdir + 1) % 4;
                if(command == -2) currentdir = (currentdir + 3) % 4;
            }
        }
        return res;
    }
};
