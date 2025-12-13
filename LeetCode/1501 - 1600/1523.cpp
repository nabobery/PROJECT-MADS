// 1523. Count Odd Numbers in an Interval Range

// Solution 1: Simple Math
// Time Complexity: O(1)
// Space Complexity: O(1)
class Solution {
public:
    int countOdds(int low, int high) {
        int nums = high-low+1;
        return (nums/2 + (low%2 && nums%2));
    }
};