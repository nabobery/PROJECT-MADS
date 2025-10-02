// 2221. Find Triangular Sum of an Array

// Solution 1: Using Simulation
// Time Complexity: O(n^2)
// Space Complexity: O(1)
class Solution {
public:
    int triangularSum(vector<int>& nums) {
        int n = nums.size();
        for (int i = n - 1; i > 0; --i) {
            for (int j = 0; j < i; ++j) {
                nums[j] = (nums[j] + nums[j + 1]) % 10;
            }
        }
        return nums[0];
    }
};

// Solution 2: Using Combinatorics, Modular Arithmetic, Lucas Theorem and Chinese Remainder Theorem
// Final value = sum_{i=0..n-1} nums[i] * C(n-1, i) (mod 10)
// Time Complexity: O(nlogn)
// Space Complexity: O(n)
class Solution {
public:
    // Function to calculate nCr % p for small values of n and r (n < p).
    // This uses a dynamic programming approach based on Pascal's Triangle.
    int nCrModp(int n, int r, int p) {
        if (r > n)
            return 0;
        if (r == 0 || r == n)
            return 1;
        if (r > n / 2)
            r = n - r; // Optimization: C(n,r) = C(n, n-r)

        long long C[r + 1];
        for (int i = 0; i <= r; i++) {
            C[i] = 0;
        }
        C[0] = 1;

        for (int i = 1; i <= n; i++) {
            for (int j = min(i, r); j > 0; j--) {
                C[j] = (C[j] + C[j - 1]) % p;
            }
        }
        return C[r];
    }

    // Lucas's Theorem to calculate nCr % p for large numbers.
    // This reduces a large nCr mod p to many small nCr with n < p.
    // Lucas's Theorem: compute C(n, r) mod p by splitting n,r into base-p digits.
    // Returns C(n,r) mod p for prime p. Uses recursive digit decomposition:
    // C(n,r) ≡ Π C(ni, ri) (mod p) where ni,ri are base-p digits.
    int lucasTheorem(long long n, long long r, int p) {
        if (r < 0 || r > n)
            return 0;
        if (r == 0)
            return 1;

        int ni = n % p; // current least-significant base-p digit of n
        int ri = r % p; // current digit of r
        // Recurse on higher digits and multiply by small binomial C(ni,ri) mod p
        return (lucasTheorem(n / p, r / p, p) * nCrModp(ni, ri, p)) % p;
    }

    // Chinese Remainder Theorem to find the result modulo 10.
    // Combine nCr mod 2 and mod 5 into mod 10 using CRT.
    // For moduli 2 and 5 (coprime): solution is x = 5*a + 6*b (mod 10),
    // because 5 ≡ 1 (mod 2) and 6 ≡ 1 (mod 5) as required by CRT construction.
    int nCrMod10(long long n, long long r) {
        if (r < 0 || r > n)
            return 0;
        if (r == 0 || r == n)
            return 1;

        // Calculate nCr mod 2
        int a = lucasTheorem(n, r, 2);

        // Calculate nCr mod 5
        int b = lucasTheorem(n, r, 5);

        // CRT combination for mod 10 (unique because 2 and 5 are coprime)
        // Use the Chinese Remainder Theorem formula: x = 5a + 6b (mod 10)
        int result = (5 * a + 6 * b) % 10;

        return result;
    }
    int triangularSum(vector<int>& nums) {
        int n = nums.size(), res = 0;
        if (n == 1)
            return nums[0] % 10;
        // nCrMod10 gives us the coefficient of nums[i] in the final result.
        for (int i = 0; i < n; i++) {
            res = (res + nCrMod10(n-1, i) * nums[i]) % 10;
        }
        return res;
    }
};