// 3653. XOR After Range Multiplication Queries I

// Solution 1: Simulation with Active Queries
// Time Complexity: O(n * q) where n is the size of nums and q is the number of queries.
// Space Complexity: O(n * q) for storing active queries and the modified nums.
class Solution {
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size(), q = queries.size();
        long long MOD = 1e9 + 7;
        // active_queries[i] will store the indices of queries that are currently active at index i
        vector<vector<int>> active_queries(n);
        for (int i = 0; i < q; ++i) {
            int l_i = queries[i][0];
            if (l_i < n) {
                active_queries[l_i].push_back(i);
            }
        }
        // finalXor will store the cumulative XOR of the modified nums after processing all queries
        int finalXor = 0;
        // Process each index of nums and apply the active queries
        for (int i = 0; i < n; ++i) {
            // Apply all active queries at index i
            for (int queryIdx : active_queries[i]) {
                long long v_i = queries[queryIdx][3];
                nums[i] = (1LL * nums[i] * v_i) % MOD;

                int r_i = queries[queryIdx][1];
                int k_i = queries[queryIdx][2];
                int next_idx = i + k_i;

                // If the next index is within the range of the current query and within bounds of nums, add the query to the active queries for the next index
                if (next_idx <= r_i && next_idx < n) {
                    active_queries[next_idx].push_back(queryIdx);
                }
            }
            // XOR the modified nums[i] to the finalXor
            finalXor ^= nums[i];
        }
        // Return the final XOR after processing all queries
        return finalXor;
    }
};