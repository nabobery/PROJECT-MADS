// 1041. Robot Bounded In Circle
// Solution by keeping tack of direction and distance
class Solution {
public:
    bool isRobotBounded(string instructions) {
        int x  = 0;
        int y = 0;
        char direction = 'N';
        for(char ch : instructions){
            if(ch == 'G'){
                if(direction == 'N')
                    y += 1;
                else if(direction == 'S')
                    y -= 1;
                else if(direction == 'E')
                    x += 1;
                else
                    x -= 1;

            }
            else if(ch == 'L'){
                if(direction == 'N')
                    direction = 'W';
                else if(direction == 'S')
                    direction = 'E';
                else if(direction == 'E')
                    direction = 'N';
                else
                    direction = 'S';
            }
            else{
                if(direction == 'N')
                    direction = 'E';
                else if(direction == 'S')
                    direction = 'W';
                else if(direction == 'E')
                    direction = 'S';
                else
                    direction = 'N';
            }
        }
        if(x == 0 && y == 0)
            return true;
        if(direction == 'N')
            return false;
        return true;

    }
};

// fast but not good memory wise
class Solution {
public:
    bool isRobotBounded(string instructions) {
        int x  = 0, y = 0, i = 0;
        vector<vector<int>> dir = {{0,1}, {-1, 0}, {0, -1}, {1,0}};
        for(char ch : instructions){
            if(ch == 'L')
                i = (i+1)%4;
            else if(ch == 'R')
                i = (i+3)%4;
            else{
                x += dir[i][0];
                y += dir[i][1];
            }
        }
        return (x == 0 && y == 0 || i != 0);
    }
};

