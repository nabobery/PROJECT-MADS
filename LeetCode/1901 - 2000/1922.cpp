// 1922. Count Good Numbers

// Solution 1: Using Fast Exponentiation
// Time Complexity: O(log n)
// Space Complexity: O(1)
class Solution {
    public:
        int mod = 1e9 + 7;
        long long mod_pow(long long base, long long exp, long long m) {
            long long result = 1;
            base %= m;
            while (exp > 0) {
                if (exp % 2 == 1)
                    result = (result * base) % m;
                base = (base * base) % m;
                exp /= 2;
            }
            return result;
        }
        int countGoodNumbers(long long n) {
            if(n == 1) return 5;
            long long even = (n+1)/2, odd = n/2;
            // 5^even * 4 ^ odd % mod
            long long res = mod_pow(5, even, mod);
            res *= mod_pow(4, odd, mod);
            return res % mod;
        }
};