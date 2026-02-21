// 190. Reverse Bits

// Solution 1: Traverse the bits of n and construct the result by adding the value of the bit at the corresponding position in the result. Time complexity: O(1) since we are always traversing 32 bits, Space complexity: O(1).
// Time complexity: O(1) since we are always traversing 32 bits, Space complexity: O(1).
// Space complexity: O(1).
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t i = 31, result = 0;
        while(n){
            if(n%2) result += pow(2, i);
            n /= 2;
            i--;
        }
        return result;
    }
};

// Solution 2: Using bitset
// Time complexity: O(1) since we are always traversing 32 bits.
// Space complexity: O(1).
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        bitset<32> original(n), reversed;
        for (int i = 0; i < 32; ++i) reversed[31-i] = original[i];
        return static_cast<uint32_t>(reversed.to_ulong());
    }
};