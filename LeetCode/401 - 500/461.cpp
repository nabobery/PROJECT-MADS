// 461. Hamming Distance

// Solution 1
class Solution {
public:
    int x_bin[32], y_bin[32];
    int hammingDistance(int x, int y) {
        memset(x_bin, 0, sizeof(x_bin));
        memset(y_bin, 0, sizeof(y_bin));
        int i = 0, result = 0;
        while(x){
            if(x%2) x_bin[i] = 1;
            x /= 2;
            i++;
        }
        i = 0;
        while(y){
            if(y%2) y_bin[i] = 1;
            y /= 2;
            i++;
        }
        for(int i = 0; i < 32;i++)
            if(x_bin[i] != y_bin[i]) result++;
        return result;
    }
};

// Solution 2
class Solution {
public:
    int hammingDistance(int x, int y) {
        int z = x ^ y;
        int result = 0;
        while(z){
            if(z%2) result++;
            z /= 2;
        }
        return result;
    }
};


// Solution 3
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