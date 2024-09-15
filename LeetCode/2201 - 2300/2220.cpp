// 2220. Minimum Bit Flips to Convert Number

// Solution 1 using bit manipulation
// Time complexity: O(log(max(start, goal)))
// Space complexity: O(1)
class Solution {
public:
    int minBitFlips(int start, int goal) {
        int mx = max(start, goal);
        if(mx == 0) return 0;
        int bits = log2(mx), res = 0;
        for(int i = 0; i <= bits;i++)
            if(((1 << i) & start) ^ ((1 << i) & goal)) res++;
        return res;
    }
};

