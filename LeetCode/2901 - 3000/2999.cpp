// 2999. Count the Number of Powerful Integers

// Solution 1: Using Digital Dynamic Programming
// Time Complexity: O(log(finish)* 10)
// Space Complexity: O(log(finish))
class Solution {
    public:
        long long numberOfPowerfulInt(long long start, long long finish, int limit,
                                      const string& pattern) {
            // 1) Convert bounds to strings
            string low_str = to_string(start);
            string high_str = to_string(finish);
    
            // 2) Pad low_str with leading zeros so both have same length
            int n = high_str.size();
            if ((int)low_str.size() < n) {
                low_str = string(n - low_str.size(), '0') + low_str;
            }
    
            // 3) Determine how many leading digits are free vs. fixed by pattern
            int m = pattern.size();
            int prefix_len = n - m;
    
            // 4) Precompute digit arrays for fast access
            vector<int> low_digits(n), high_digits(n), pat_digits(m);
            for (int i = 0; i < n; ++i) {
                low_digits[i] = low_str[i] - '0';
                high_digits[i] = high_str[i] - '0';
            }
            for (int i = 0; i < m; ++i) {
                pat_digits[i] = pattern[i] - '0';
            }
    
            // 5) memo[i] stores the count for subproblems at position i
            //    when both low‑bound and high‑bound are already loose
            vector<long long> memo(n, -1);
    
            // 6) DFS with two “tight” flags:
            //    tight_low  = have we matched the lower bound exactly so far?
            //    tight_high = have we matched the upper bound exactly so far?
            function<long long(int, bool, bool)> dfs =
                [&](int pos, bool tight_low, bool tight_high) -> long long {
                // a) If we've assigned all n digits, that's one valid number
                if (pos == n)
                    return 1;
    
                // b) If both bounds are loose and we’ve cached this state, reuse it
                if (!tight_low && !tight_high && memo[pos] != -1) {
                    return memo[pos];
                }
    
                // c) Determine allowed digit range at this position
                int lo = tight_low ? low_digits[pos] : 0;
                int hi = tight_high ? high_digits[pos] : 9;
    
                long long cnt = 0;
                if (pos < prefix_len) {
                    // d) In the “free” prefix, we can choose any digit ≤ limit
                    for (int d = lo; d <= min(hi, limit); ++d) {
                        cnt += dfs(pos + 1, tight_low && d == lo,
                                   tight_high && d == hi);
                    }
                } else {
                    // e) In the pattern region, digit is fixed by pat_digits
                    int d = pat_digits[pos - prefix_len];
                    if (d >= lo && d <= min(hi, limit)) {
                        cnt = dfs(pos + 1, tight_low && d == lo,
                                  tight_high && d == hi);
                    }
                }
    
                // f) Cache if both bounds are loose
                if (!tight_low && !tight_high) {
                    memo[pos] = cnt;
                }
                return cnt;
            };
    
            // 7) Kick off DFS from pos=0 with both bounds tight
            return dfs(0, true, true);
        }
};

    