// 342. Power of Four

// Solution 1 using while loop
// Time complexity: O(logn) 
// Space complexity: O(1)
class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n <= 0) return false;
        while(n != 1){
            if(n%4) return false;
            n /= 4;
        }
        return true;
    }
};

// Solution 2 using bit manipulation
// Time complexity: O(1)
// Space complexity: O(1)
class Solution {
public:
    bool isPowerOfFour(int n) {
        // n > 0 && n should be even and n & 1010101010101010101010101010101 should be true which is used to match all powers of 4
        return n > 0 && !(n&(n-1)) && (n&0x55555555);
    }
};