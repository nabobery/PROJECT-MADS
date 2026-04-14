// 657. Robot Return to Origin

// Solution 1: Simple Simulation
// Time Complexity: O(n), where n is the length of moves
// Space Complexity: O(1)
class Solution {
public:
    bool judgeCircle(string moves) {
        int cx = 0, cy = 0;
        for (char& dir : moves) {
            if (dir == 'R')
                cx += 1;
            else if (dir == 'L')
                cx -= 1;
            else if (dir == 'U')
                cy -= 1;
            else
                cy += 1;
        }
        return (cx == 0 && cy == 0);
    }
};