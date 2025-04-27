// 2338. Count the Number of Ideal Arrays

// Solution 1 Using Fast Exponentiation, Sieve of Eratosthenes, Inverse Modulo and Combinatorics
// Time Complexity: O(n log n + m log m) where n is the number of elements in the array and m is the maximum value in the array
// Space Complexity: O(m) where m is the maximum value in the array

// Fast Exponentiation: O(log n)
long long power(long long base, long long exp) {
    long long res = 1;
    base %= 1000000007;
    while (exp > 0) {
        if (exp % 2 == 1) res = (res * base) % 1000000007;
        base = (base * base) % 1000000007;
        exp /= 2;
    }
    return res;
}

// Inverse Modulo: O(log n)
// Using Fermat's Little Theorem: a^(p-1) ≡ 1 (mod p) => a^(p-2) ≡ a^(-1) (mod p)
// where p is a prime number
long long modInverse(long long n) {
    if (n == 0) return 0;
    return power(n, 1000000007 - 2);
}

vector<long long> fact;
vector<long long> invFact;
vector<int> spf;
int precomputed_max_val = -1;
int precomputed_max_comb_n = -1;

// Precompute factorials and their inverses
// O(n) for n factorials
void precomputeCombinations(int n_max_comb_needed) {
    if (precomputed_max_comb_n >= n_max_comb_needed) return;

    int old_size = fact.size();
    int limit = n_max_comb_needed;

    fact.resize(limit + 1);
    invFact.resize(limit + 1);

    if (old_size == 0) {
        fact[0] = 1;
        invFact[0] = 1;
        old_size = 1;
    }

    for (int i = old_size; i <= limit; i++) {
        fact[i] = (fact[i - 1] * i) % 1000000007;
        invFact[i] = modInverse(fact[i]);
    }
    precomputed_max_comb_n = limit;
}

// Combinatorics: O(1)
// nCr = n! / (r! * (n - r)!)
long long nCr(int n, int r) {
    if (r < 0 || r > n) return 0;
    if (r == 0 || r == n) return 1;
    if (r > n / 2) r = n - r;
    if (n > precomputed_max_comb_n) return 0;

    long long num = fact[n];
    long long den1 = invFact[r];
    long long den2 = invFact[n - r];
    long long den = (den1 * den2) % 1000000007;
    return (num * den) % 1000000007;
}

// Sieve of Eratosthenes: O(n log log n)
// Precompute smallest prime factors (SPF) for each number up to max_val
// This is used to factorize numbers efficiently
void sieve(int max_val) {
    if (precomputed_max_val >= max_val) return;
    int limit = max_val;
    spf.resize(limit + 1);
    iota(spf.begin(), spf.end(), 0);

    for (long long i = 2; i * i <= limit; ++i) {
        if (spf[i] == i) {
            for (long long j = i * i; j <= limit; j += i) {
                if (spf[j] == j) {
                    spf[j] = (int)i;
                }
            }
        }
    }
    precomputed_max_val = limit;
}

class Solution {
public:
    int idealArrays(int n, int maxValue) {
        if (maxValue <= 0) return 0;
        if (n <= 0) return 0;

        int mod = 1000000007;
        sieve(maxValue);
        int max_exponent_approx = (maxValue == 0) ? 0 : static_cast<int>(log2(max(1, maxValue))) + 1;
        int n_max_comb_needed = n + max_exponent_approx;
        precomputeCombinations(n_max_comb_needed);

        long long total_sum = 0;

        // Iterate through all values from 1 to maxValue
        // and calculate the number of ways to form ideal arrays for each value
        // The number of ways to form ideal arrays for a value v is given by the product of combinations
        // of the exponents of its prime factors
        // For example, if v = p1^e1 * p2^e2 * ... * pk^ek, then the number of ways is:
        // C(e1 + n - 1, n - 1) * C(e2 + n - 1, n - 1) * ... * C(ek + n - 1, n - 1)
        // where C(a, b) is the binomial coefficient "a choose b"
        // and e1, e2, ..., ek are the exponents of the prime factors p1, p2, ..., pk of v
        for (int v = 1; v <= maxValue; ++v) {
            long long ways_for_v = 1;
            int current_v = v;

            while (current_v > 1) {
                int p = spf[current_v];
                if (p <= 1) {
                    ways_for_v = 0;
                    break;
                }

                int exponent = 0;
                while (current_v % p == 0) {
                    exponent++;
                    current_v /= p;
                }

                long long combinations = nCr(exponent + n - 1, n - 1);
                if (combinations == 0 && (exponent + n - 1 > precomputed_max_comb_n)) {
                    ways_for_v = 0;
                    break;
                }

                ways_for_v = (ways_for_v * combinations) % mod;
            }

            total_sum = (total_sum + ways_for_v) % mod;
        }

        return (int)((total_sum + mod) % mod);
    }
};
