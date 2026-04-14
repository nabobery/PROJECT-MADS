// 3655. XOR After Range Multiplication Queries II

// Solution 1: Using Square Root Decomposition
// The idea is to separate the queries into two groups based on the value of k:
// 1. For small k values (k <= sqrt(n)), we can use a difference array to apply the multiplications efficiently.
// 2. For large k values (k > sqrt(n)), we can directly apply the multiplications to the relevant indices in the nums array.
// Time Complexity: O((n + q) * sqrt(n))
// Space Complexity: O(n + sqrt(n))
class Solution {
    const int mod = 1000000007;

    // Fast exponentiation to compute (base^exp) % mod
    long long power(long long base, long long exp) {
        long long res = 1;
        base %= mod;
        while (exp > 0) {
            if (exp % 2 == 1)
                res = (res * base) % mod;
            base = (base * base) % mod;
            exp /= 2;
        }
        return res;
    }

    // Compute modular inverse using Fermat's Little Theorem and fast exponentiation
    // n^(-1) mod m = n^(m-2) mod m (when m is prime)
    long long modInverse(long long n) { return power(n, mod - 2); }

public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        // Determine the threshold for small k values based on the square root of n
        int threshold = sqrt(n);

        // Buckets to group queries by their k values for small k
        vector<vector<int>> smallKBuckets(threshold + 1);
        for (int i = 0; i < queries.size(); ++i) {
            int k = queries[i][2];
            // If k is small, add the query index to the corresponding bucket
            if (k <= threshold) {
                smallKBuckets[k].push_back(i);
            } else {
                // For large k values, directly apply the multiplication to the relevant indices in nums
                int l = queries[i][0], r = queries[i][1], v = queries[i][3];
                for (int idx = l; idx <= r; idx += k) {
                    nums[idx] = (1LL * nums[idx] * v) % mod;
                }
            }
        }

        // Process the small k buckets using a difference array to apply the multiplications efficiently
        for (int kVal = 1; kVal <= threshold; ++kVal) {
            // If there are no queries for this k value, skip to the next k
            if (smallKBuckets[kVal].empty())
                continue;

            // Create a difference array to apply the multiplications for the queries in this bucket
            vector<long long> diff(n + kVal, 1);
            // Apply the multiplications for each query in the current bucket using the difference array
            for (int qIdx : smallKBuckets[kVal]) {
                int l = queries[qIdx][0], r = queries[qIdx][1],
                    v = queries[qIdx][3];
                int numSteps = (r - l) / kVal;
                // Calculate the last index that will be affected by this query
                int lastIdx = l + numSteps * kVal;

                // Update the difference array to apply the multiplication for the range defined by the query
                diff[l] = (diff[l] * v) % mod;
                // If the last index affected by this query is within bounds, update the difference array to remove the effect of this multiplication after the last index
                if (lastIdx + kVal < n + kVal) {
                    diff[lastIdx + kVal] =
                        (diff[lastIdx + kVal] * modInverse(v)) % mod;
                }
            }

            // Apply the difference array to the nums array to get the final values after processing all queries for this k value
            for (int i = 0; i < n; ++i) {
                // If the current index has a multiplication factor different from 1, apply it to the nums array and propagate it to the next index that will be affected by this multiplication
                if (diff[i] != 1) {
                    nums[i] = (1LL * nums[i] * diff[i]) % mod;
                    // If the next index that will be affected by this multiplication is within bounds, propagate the multiplication factor to that index in the difference array
                    if (i + kVal < n) {
                        diff[i + kVal] = (diff[i + kVal] * diff[i]) % mod;
                    }
                } else {
                    // If the current index has a multiplication factor of 1, we can still propagate it to the next index that will be affected by this multiplication if it is within bounds
                    if (i + kVal < n && diff[i] != 1) {
                        diff[i + kVal] = (diff[i + kVal] * diff[i]) % mod;
                    }
                }
            }
        }

        // After processing all queries, compute the final XOR of all elements in the nums array
        int finalXor = 0;
        for (int x : nums) {
            finalXor ^= x;
        }
        // Return the final XOR value as the result
        return finalXor;
    }
};