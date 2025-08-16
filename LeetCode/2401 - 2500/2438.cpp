// 2438. Range Product Queries of Powers

// Solution 1: Using Prefix Array (Dynamic Programming) and Binary Exponentiation
// Time Complexity: O(q + s log s) where s is the number of set bits in n and q is the number of queries
// Space Complexity: O(s)
class Solution {
public:
    const int mod = 1e9 + 7;
    // Binary exponentiation
    int power(int base, int exp) {
        int result = 1;
        base %= mod;
        while (exp > 0) {
            if (exp % 2 == 1)
                result = (1LL * result * base) % mod;
            base = (1LL * base * base) % mod;
            exp /= 2;
        }
        return result;
    }

    // Modular inverse using Fermat's Little Theorem
    int modInverse(int b) { return power(b, mod - 2); }

    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        
        vector<int> powers;
        for (int i = 0; i < 32; i++)
            if (n & (1 << i))
                powers.push_back(1 << i);
        int s = powers.size(), q = queries.size();
        vector<int> prefix(s + 1, 1), res(q);
        for (int i = 0; i < s; i++)
            prefix[i + 1] = (1LL * prefix[i] * powers[i]) % mod;
        for (int i = 0; i < q; i++) {
            int inv = modInverse(prefix[queries[i][0]]);
            res[i] = (1LL * prefix[queries[i][1]+1] * inv) % mod;
        }
        return res;
    }
};