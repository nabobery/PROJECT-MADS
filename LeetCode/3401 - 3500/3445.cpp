// 3445. Maximum Difference Between Even and Odd Frequency II

// Solution 1: Using Sliding Window Technique and Bitmasking
// Time Complexity: O(n * 5^2)
// Space Complexity: O(1)
class Solution {
public:
    int maxDifference(string s, int k) {
        auto getStatus = [](int cnt_a, int cnt_b) {
            return ((cnt_a & 1) << 1) | (cnt_b & 1);
        };

        int n = s.size(), ans = INT_MIN;

        for (char a = '0'; a <= '4'; ++a) {
            for (char b = '0'; b <= '4'; ++b) {
                if (a == b) continue;

                int best[4] = {INT_MAX, INT_MAX, INT_MAX, INT_MAX};
                int cnt_a = 0, cnt_b = 0, prev_a = 0, prev_b = 0, left = -1;

                for (int right = 0; right < n; ++right) {
                    cnt_a += (s[right] == a);
                    cnt_b += (s[right] == b);

                    while (right - left >= k && cnt_b - prev_b >= 2) {
                        int st = getStatus(prev_a, prev_b);
                        best[st] = min(best[st], prev_a - prev_b);
                        ++left;
                        prev_a += (s[left] == a);
                        prev_b += (s[left] == b);
                    }

                    int st = getStatus(cnt_a, cnt_b);
                    int opp = st ^ 0b10;
                    if (best[opp] != INT_MAX) {
                        ans = max(ans, cnt_a - cnt_b - best[opp]);
                    }
                }
            }
        }

        return ans;
    }
};