// 1622. Fancy Sequence

/**
 * Your Fancy object will be instantiated and called as such:
 * Fancy* obj = new Fancy();
 * obj->append(val);
 * obj->addAll(inc);
 * obj->multAll(m);
 * int param_4 = obj->getIndex(idx);
 */

// Solution 1: Using prefix multiplication and addition and Fermat's Little Theorem for modular inverse
// The idea is to maintain two prefix arrays: one for the cumulative product of multipliers and another for the cumulative sum of adders. When we need to get the value at a specific index, we can calculate the effect of all operations applied to that index using these prefix arrays. We also use modular inverse to handle the division when calculating the final value after all operations.
// This approach allows us to perform each operation in O(1) time, and retrieving the value at a specific index also takes O(1) time after O(n) preprocessing for the prefix arrays.
// Time Complexity: O(1) for each operation
// Space Complexity: O(n) for storing the sequence and prefix arrays
class Fancy {
public:
    long long mod = 1e9 + 7;
    vector<int> sequence;
    // prefix_mul[i] = product of all multipliers applied to the first i elements
    // prefix_add[i] = sum of all adders applied to the first i elements
    vector<long long> prefix_mul;
    vector<long long> prefix_add;

    Fancy() {
        // Initialize prefix arrays with base case
        prefix_mul.push_back(1);
        prefix_add.push_back(0);
    }

    // Function to calculate (base^exp) % mod using binary exponentiation
    long long power(long long base, long long exp) {
        long long res = 1;
        base %= mod;
        while (exp > 0) {
            if (exp % 2 == 1) res = (res * base) % mod;
            base = (base * base) % mod;
            exp /= 2;
        }
        return res;
    }

    // Function to calculate modular inverse using Fermat's Little Theorem
    // Since mod is prime, the modular inverse of n is n^(mod-2) % mod
    long long modInverse(long long n) {
        return power(n, mod - 2);
    }

    // Append a value to the sequence
    void append(int val) {
        // Store the original value before any operations
        sequence.push_back(val);
        // For the new element, the prefix multiplication and addition are the same as the last element
        prefix_mul.push_back(prefix_mul.back());
        prefix_add.push_back(prefix_add.back());
    }

    // Add inc to all elements in the sequence
    void addAll(int inc) {
        // Update the last element of prefix_add to reflect the addition for all elements
        prefix_add.back() = (prefix_add.back() + inc) % mod;
    }

    // Multiply all elements in the sequence by m
    void multAll(int m) {
        // Update the last elements of prefix_mul and prefix_add to reflect the multiplication for all elements
        prefix_mul.back() = (prefix_mul.back() * m) % mod;
        prefix_add.back() = (prefix_add.back() * m) % mod;
    }

    int getIndex(int idx) {
        // If idx is out of bounds, return -1
        if (idx >= sequence.size()) return -1;


        // Calculate the result for the element at index idx using the prefix multiplication and addition
        long long m_start = prefix_mul[idx];
        long long a_start = prefix_add[idx];
        // Get the last values of prefix multiplication and addition to calculate the final result
        long long m_end = prefix_mul.back();
        long long a_end = prefix_add.back();

        // Calculate the ratio of the final multiplier to the initial multiplier for the element at index idx
        long long ratio = (m_end * modInverse(m_start)) % mod;
        long long res = (ratio * sequence[idx]) % mod;
        // Add the contribution from the additions, adjusting for the ratio of multipliers
        res = (res + a_end - (ratio * a_start) % mod + mod) % mod;

        return (int)res;
    }
};