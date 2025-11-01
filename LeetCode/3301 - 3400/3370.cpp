// 3370. Smallest Number With All Set Bits

// Solution 1: Pre compute set bits and construct the number
// Time Complexity: O(1)
// Space Complexity: O(1)
class Solution {
public:
    // number with set bits = 2^k - 1
    vector<int> setBitNumbers = {1, 3, 7, 15, 31, 63, 127, 255, 511, 1023};
    int smallestNumber(int n) {
        return *lower_bound(setBitNumbers.begin(), setBitNumbers.end(), n);
    }
};