// 461. Hamming Distance
class Solution {
public:
    int hammingDistance(int x, int y) {
        int n = x ^ y; // find number of different bits usng XOR
        int result = 0;
        // calculate the number of different bits
        while(n > 0){
            result += n & 1;
            n >>= 1;
        }
        return result;
    }
};