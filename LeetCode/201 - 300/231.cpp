// 231. Power of Two

// using loops
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n == 0) return 0;
        while(n % 2 == 0) 
            n /= 2;
        return n == 1;     
    }
};

// We just need to check if n > 0 and if the and between n(all bits 0 except msb 1) and n -1(all bits 1 except msb 0) is 0
class Solution {
public:
    bool isPowerOfTwo(int n) {
        return (n > 0 && (n & n-1) == 0);     
    }
};