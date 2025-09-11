// 3495. Minimum Operations to Make Array Elements Zero

// Solution 1: Breaking down the range into segments of powers of 4 and then calculating the number of operations required to make the range of elements zero
// Time Complexity: O(n)
// Space Complexity: O(1)
class Solution {
public:
    long long minOperations(vector<vector<int>>& queries) {
        long long res = 0;
        // Pre-calculate powers of 4. We only need up to 4^15 > 10^9.
        // A size of 17 is a safe upper bound.
        vector<long long> pow4(17);
        pow4[0] = 1;
        // Pre-calculate powers of 4
        for (int i = 1; i < 17; ++i) {
            pow4[i] = pow4[i - 1] * 4;
        }

        for (const auto& query : queries) {
            long long l = query[0];
            long long r = query[1];

            long long sum_of_costs = 0;
            // break down the range into segments of powers of 4
            for (int k = 1; k < 17; ++k) {
                long long start_k = pow4[k - 1];
                long long end_k = pow4[k] - 1;

                // No need to check ranges that are completely beyond r
                if (start_k > r) break;

                long long overlap_start = max(l, start_k);
                long long overlap_end = min(r, end_k);

                // calculate the number of divisions for each number in the overlap
                if (overlap_start <= overlap_end) {
                    long long count = overlap_end - overlap_start + 1;
                    // each of these numbers requires k divisions to become zero
                    sum_of_costs += count * k;
                }
            }

            if (sum_of_costs == 0) {
                continue;
            }
            
            // then do it for pairs
            // Step 3: The minimum operations is ceil(S / 2),
            // which is (S + 1) / 2 in integer arithmetic.
            res += (sum_of_costs + 1) / 2;
        }
        return res;
    }
};