// 693. Binary Number with Alternating Bits

// Solution 1: Simple Iteration to check if number has alternating bits
// Time Complexity: O(log n) where n is the input number
// Space Complexity: O(1)
class Solution {
public:
    bool hasAlternatingBits(int n) {
        int prevBit = -1;
        while(n){
            int currBit = n %2;
            n /= 2;
            if(currBit == prevBit) return false;
            prevBit = currBit;
        }   
        return true;
    }
};