// 3003. Maximize the Number of Partitions After Operations

// Solution 1: Using Brute Force Simulation with Dynamic Programming, Prefix Sum and Binary Search
// Time Complexity: O(n*25*logn)
// Space Complexity: O(n)
class Solution {
public:
    // Helper to count distinct chars in s[start...end] with a hypothetical change
    int countDistinct(int start, int end, int change_idx, int old_char_code, int new_char_code, const vector<vector<int>>& prefix_cnts) {
        if (start > end) return 0;
        int distinct_count = 0;
        for (int c = 0; c < 26; ++c) {
            int count = prefix_cnts[c][end + 1] - prefix_cnts[c][start];
            if (start <= change_idx && change_idx <= end) {
                if (c == old_char_code) count--;
                if (c == new_char_code) count++;
            }
            if (count > 0) distinct_count++;
        }
        return distinct_count;
    }

    // Helper to binary search for the end of a partition
    int find_partition_end(int start_idx, int change_idx, int old_char_code, int new_char_code, int n, int k, const vector<vector<int>>& prefix_cnts) {
        int low = start_idx, high = n - 1;
        int end_idx = start_idx - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (countDistinct(start_idx, mid, change_idx, old_char_code, new_char_code, prefix_cnts) <= k) {
                end_idx = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return end_idx;
    }

    int maxPartitionsAfterOperations(string s, int k) {
        if (k == 26) return 1;
        int n = s.size();
        vector<vector<int>> prefix_cnts(26, vector<int>(n + 1, 0));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < 26; ++j) prefix_cnts[j][i + 1] = prefix_cnts[j][i];
            prefix_cnts[s[i] - 'a'][i + 1]++;
        }

        vector<int> prefix_partitions(n, 0), partition_start(n, 0);
        int p_start = 0, count = 1;
        unordered_set<char> distinct_chars;
        for (int i = 0; i < n; ++i) {
            distinct_chars.insert(s[i]);
            if (distinct_chars.size() > k) {
                count++;
                distinct_chars.clear();
                distinct_chars.insert(s[i]);
                p_start = i;
            }
            prefix_partitions[i] = count;
            partition_start[i] = p_start;
        }

        vector<int> partitions_from(n + 1, 0);
        for (int i = n - 1; i >= 0; --i) {
            int end_idx = find_partition_end(i, -1, -1, -1, n, k, prefix_cnts);
            partitions_from[i] = 1 + partitions_from[end_idx + 1];
        }

        int max_res = partitions_from[0];

        for (int i = 0; i < n; ++i) {
            int old_char_code = s[i] - 'a';
            for (int new_char_code = 0; new_char_code < 26; ++new_char_code) {
                if (old_char_code == new_char_code) continue;

                p_start = partition_start[i];
                int partitions_before = (p_start > 0) ? prefix_partitions[p_start - 1] : 0;
                
                int r1 = find_partition_end(p_start, i, old_char_code, new_char_code, n, k, prefix_cnts);
                
                int current_total;
                if (r1 >= i) { // Case 1: Change is consumed
                    int partitions_after = (r1 < n - 1) ? partitions_from[r1 + 1] : 0;
                    current_total = partitions_before + 1 + partitions_after;
                } else { // Case 2: Change is in the next partition
                    int r2 = find_partition_end(r1 + 1, i, old_char_code, new_char_code, n, k, prefix_cnts);
                    int partitions_after = (r2 < n - 1) ? partitions_from[r2 + 1] : 0;
                    current_total = partitions_before + 1 + 1 + partitions_after;
                }
                max_res = max(max_res, current_total);
            }
        }
        return max_res;
    }
};
        