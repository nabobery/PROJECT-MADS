// 190. Reverse Bits

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