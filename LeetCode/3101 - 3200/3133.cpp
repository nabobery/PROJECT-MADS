// 3133. Minimum Array End

// Solution 1 using Bit manipulation and bitset
// Time complexity: O(n)
// Space complexity: O(1)
// The idea to get minimum nums[n-1] is to keep nums[0] = x
// Then, we can keep n's bits in unset bits of x to get minimum nums[n-1]
class Solution {
public:
    long long minEnd(int n, int x) {
        // If n is 1, return x
        if(n == 1) return x;
        // Convert x to a bitset as nums[0] = x
        bitset<64> result(x);
        int nIndex = 0;
        n--;
        for (int i = 0; i < 64; ++i) {
            // If the bit is not set, set it to the bit of n
            if (!result[i]) {
                if (((long long)n >> nIndex) & 1) {
                    result.set(i); 
                }
                // Increment the index of n
                nIndex++; 
            }
        }
        return result.to_ullong();
    }
};