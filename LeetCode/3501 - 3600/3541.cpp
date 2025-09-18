// 3541. Find Most Frequent Vowel and Consonant

// Solution 1: Straightforward
// Time Complexity: O(n)
// Space Complexity: O(1)
class Solution {
public:
    int maxFreqSum(string s) {
        vector<int> cnt(26, 0);
        for (char& ch : s)
            cnt[ch - 'a']++;
        int v = 0, c = 0;
        for (int i = 0; i < 26; i++) {
            if (i == 0 || i == 4 | i == 8 | i == 14 | i == 20)
                v = max(v, cnt[i]);
            else
                c = max(c, cnt[i]);
        }
        return v + c;
    }
};