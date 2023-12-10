// 1688. Count of Matches in Tournament

// Solution 1: Simple Recursion
// Time Complexity: O(logn)
// Space Complexity: O(logn)
class Solution {
public:
    int numberOfMatches(int n) {
        if(n == 1) return 0;
        if(n%2) return (n - 1)/2 + numberOfMatches((n - 1)/2 + 1);
        return n/2 + numberOfMatches(n/2);
    }
};

// Solution 2: Simple Iteration
// Time Complexity: O(logn)
// Space Complexity: O(1)
class Solution {
public:
    int numberOfMatches(int n) {
        int res = 0;
        while(n > 1) {
            res += n/2;
            n = (n + 1)/2;
        }
        return res;
    }
};