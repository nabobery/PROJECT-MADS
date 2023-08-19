// 191. Number of 1 Bits

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int result = 0;
        while(n){
            if(n%2) result++;
            n /= 2;
        }
        return result;
    }
};