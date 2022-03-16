// 476. Number Complement
// My naive sol
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
class Solution {
public:
    int findComplement(int num) {
        unsigned mask = ~0;
        while( mask & num ) mask = mask << 1;
        return ~num ^ mask;
    }
};