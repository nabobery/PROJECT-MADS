// 2579. Count Total Number of Colored Cells

// Solution 1: USing Math => 1 + 4 + 8 + .... = 1 + 4*(n)*(n-1)/ 2 = 1 + 2*(n)*(n-1)
// Time Complexity: O(1)
// Space Complexity: O(1)
class Solution {
    public:
        long long coloredCells(int n) {
            if(n == 1) return 1;
            long long res = n;
            res *= (n-1);
            res *= 2;
            res += 1;
            return res;
        }
};