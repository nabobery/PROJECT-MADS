// 476. Number Complement

// Naive Solution 1 using bit manipulation
// Time complexity: O(logn)
// Space complexity: O(1)
class Solution {
public:
    int findComplement(int num) {
        int count  = 0;
        int n  = num;
        while(n){
            count++;
            n >>= 1;
        }
        int result = pow(2,count) - num - 1;
        return result;
    }
};

// using xor ( we do xor with all bits set to 1)
// Time complexity: O(logn)
// Space complexity: O(1)
class Solution {
public:
    int findComplement(int num) {
        int n = num, result = 1;
        while(n != 1){
            n >>= 1;
            result <<= 1;
            result |= 1;
        }
        
        result ^= num;
        
        return result;
    }
};

// using xor and complement (bit manipulation)
// Time complexity: O(logn)
// Space complexity: O(1)
class Solution {
public:
    int findComplement(int num) {
        unsigned mask = ~0;
        while( mask & num ) mask = mask << 1;
        return ~num ^ mask;
    }
};

// n ^ max bits - 1 = ~n
// Time complexity: O(logn)
// Space complexity: O(1)
class Solution {
public:
    int findComplement(int n) {
        return n ? n ^ (long) pow(2, (long)(log2(n)+1) )-1 : 1;
    }
};