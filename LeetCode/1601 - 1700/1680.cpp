// 1680. Concatenation of Consecutive Binary Numbers

// Solution 1: Straight Forward - TLE
// Time Complexity: O(nlogn)
// Space Complexity: O(1)
class Solution {
public:
    const int mod = 1e9+7;
    int concatenatedBinary(int n) {
        long res = 0;
        for(int i = 1; i <= n;i++){
            int curr = i;
            vector<int> bits;
            while(curr){
                bits.push_back(curr%2);
                curr /= 2;
            }
            for(auto it = bits.rbegin(); it != bits.rend();it++){
                res *= 2;
                res += *it;
                res %= mod;
            }
        }
        return res;
    }
};

// Solution 2: Bit Manipulation
// Time Complexity: O(n)
// Space Complexity: O(1)
class Solution {
public:
    const int mod = 1e9+7;
    int concatenatedBinary(int n) {
        long res = 0;
        // The number of bits required to represent the current number is equal to the number of bits required to represent the previous number + 1 if the current number is a power of 2, otherwise it is equal to the number of bits required to represent the previous number.
        int numBits = 0;
        for(int i = 1; i <= n;i++){
            // If i is a power of 2, then we need to increase the number of bits required to represent the current number by 1.
            if((i & (i-1)) == 0) numBits++;
            // We can concatenate the current number to the result by left shifting the result by the number of bits required to represent the current number and then adding the current number to the result.
            res = ((res << numBits) | i) % mod;
        }
        return res;
    }
};