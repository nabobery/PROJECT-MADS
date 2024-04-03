// 2485. Find the Pivot Integer

// Simple and easy Math based Solution
// x*(x+1)/2 = n*(n+1)/2 - x*(x-1)/2 => x^2 = n*(n+1)/2
// Time Complexity: O(logn)
// Space Complexity: O(1)
class Solution {
public:
    int pivotInteger(int n) {
        int temp = (n*(n+1))/2, x = sqrt(temp);
        return (x*x == temp ? x : -1);
    }
};