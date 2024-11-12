// 2275. Largest Combination With Bitwise AND Greater Than Zero

// Solution 1 using Greedy and Bit Manipulation
// Time complexity: O(n)
// Space complexity: O(1)
class Solution {
public:
    int bits[31];
    int largestCombination(vector<int>& candidates) {
        memset(bits, 0, sizeof(bits));
        int res = 0;
        for(int candidate : candidates){
            for(int i = 0; i < 31;i++) bits[i] += ((1 << i) & candidate) != 0;
        }
        for(int b : bits) res = max(res, b);
        return res;
    }
};