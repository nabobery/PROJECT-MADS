// 762. Prime Number of Set Bits in Binary Representation

// Solution 1: Using Unordered Set to Check for Primes
// Time Complexity: O(n * log(m)), where n is the number of integers in the range [left, right] and m is the maximum integer in that range (due to counting set bits).
// Space Complexity: O(1) for the set of prime numbers.
class Solution {
public:
    unordered_set<int> primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};
    int countPrimeSetBits(int left, int right) {
        int res = 0;
        for(int i = left;i <= right;i++)
            res += primes.count(__builtin_popcount(i));
        return res;
    }
};

// Solution 2: Using Bit Manipulation to Check for Primes
// Time Complexity: O(n * log(m)), where n is the number of integers in the range [left, right] and m is the maximum integer in that range (due to counting set bits).
// Space Complexity: O(1) for the prime mask.
class Solution {
public:
    int countPrimeSetBits(int left, int right) {
        // 665772 is (1<<2 | 1<<3 | 1<<5 | 1<<7 | 1<<11 | 1<<13 | 1<<17 | 1<<19)
        const unsigned int primeMask = 0b10100010100010101100;
        int res = 0;
        for (int i = left; i <= right; ++i) {
            if ((primeMask >> __builtin_popcount(i)) & 1) {
                res++;
            }
        }
        return res;
    }
};