// 3516. Find Closest Person

// Solution 1: Simple and Straightforward
// This solution uses a direct comparison of distances.
// Time Complexity: O(1)
// Space Complexity: O(1)
class Solution {
public:
    int findClosest(int x, int y, int z) {
        int d1 = abs(x-z), d2 = abs(y-z);
        if(d1 < d2) return 1;
        else if(d1 > d2) return 2;
        return 0; 
    }
};