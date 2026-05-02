// 2833. Furthest Point From Origin

// Solution 1: Simple and Straightforward
// Time Complexity: O(n)
// Space Complexity: O(1)
class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int res = 0, unknown = 0;
        for(char& move: moves){
            if(move == 'L') res--;
            else if(move == 'R') res++;
            else unknown++;
        }
        return abs(res) + unknown;
    }
};