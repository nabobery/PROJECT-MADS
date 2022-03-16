// 338. Counting Bits
// my naive solution using default function
class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> result;
        result.push_back(0);
        if(n == 0) return result;
        for(int i = 1; i <=n; i++){
            result.push_back(__builtin_popcount(i));
        }
        return result;
    }
};

// O(n) time solution
// if it's even, we right shift the bit and as no bit is lost the number of bits are the same
// example : 12 - 1100,  6 - 0110
// if it's odd, we right shift and add 1 as we're losing a 1 bit
// example : 7 - 111,  3 - 011
class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> result(n+1,0);
        for(int i = 1; i <= n; i++){
            // result[i] = result[i&(i-1)] + 1;
            result[i] = result[i >> 1] + (i&1);
        }
        return result;
    }
};

