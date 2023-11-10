// 2849. Determine if a Cell Is Reachable at a Given Time

// Solution 1 using Math
// Time complexity: O(1)
// Space complexity: O(1)

// Min time to reach (sx, sy) to (fx, fy) is max(abs(fy-sy), abs(fx-sx)) which is the 
// minimum distance between the two points (Chebyshev distance). 
// If the Chebushev distance is 0, then the cell is reachable only if t != 1, otherwise it is reachable
class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        int dist = max(abs(fy-sy), abs(fx-sx));
        if(sx != fx || sy != fy) return (t >= dist);
        return t != 1;
    }
};