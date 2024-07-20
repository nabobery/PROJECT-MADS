// 2582. Pass the Pillow

// Solution 1 Simple and Straightforward
// Time complexity: O(1)
// Space complexity: O(1)
class Solution {
public:
    int passThePillow(int n, int time) {
        if(time < n) return time+1;
        if(time/(n-1) % 2) return n-time%(n-1);
        return time%(n-1) + 1;
    }
};