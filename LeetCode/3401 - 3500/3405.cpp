// 3405. Count the Number of Arrays with K Matching Adjacent Elements

// Solution 1: Using Combinatorial Counting and Modular Arithmetic (Inverse Factorials)
// Time Complexity: O(n)
// Space Complexity: O(n)

class Solution {
public:
    const int MOD = 1e9 + 7;
    vector<long> fact, inv_fact;
    int comb(int n, int k){
        if (k < 0 || k > n) return 0;
        return fact[n] * inv_fact[k] % MOD * inv_fact[n - k] % MOD;
    }
    int mod_pow(long a, long b){
        long result = 1;
        while(b){
            if(b%2) result = (result*a)% MOD;
            a = (a*a) % MOD;
            b /= 2;
        }
        return result;
    }
    int countGoodArrays(int n, int m, int k) {
        fact.resize(n, 1);
        inv_fact.resize(n, 1);
        for(int i = 1; i < n;i++)
            fact[i] = (fact[i - 1] * i) % MOD;
        inv_fact[n-1] = mod_pow(fact[n-1], MOD - 2);
        for(int i = n-2; i >= 0;i--)
            inv_fact[i] = inv_fact[i + 1] * (i + 1) % MOD;
        long long res = m;
        res = (res*comb(n-1, k)) % MOD;
        res = (res * mod_pow(m-1, n-1-k)) % MOD;
        return res;
    }
};