// 1009. Complement of Base 10 Integer
class Solution {
public:
    int bitwiseComplement(int n) {
        if(n == 0) return 1;
        unsigned mask = ~0;
        while( mask & n ) mask = mask << 1;
        return ~n ^ mask;
    }
};

// one liner
class Solution {
public:
    int bitwiseComplement(int n) {
        return n ? n ^ (int) pow(2, (int)(log2(n)+1) )-1 : 1;
    }
};
