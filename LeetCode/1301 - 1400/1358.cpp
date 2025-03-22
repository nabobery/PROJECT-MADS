// 1358. Number of Substrings Containing All Three Characters

// Solution 1: Using Two Pointers
// Time Complexity: O(n)
// Space Complexity: O(1)
class Solution {
    public:
        int numberOfSubstrings(string s) {
            int res = 0, n = s.size(), l = 0;
            vector<int> cnt(3, 0);
            for (int r = 0; r < n; r++) {
                cnt[s[r] - 'a']++;
                bool b = true;
                for (int i = 0; i < 3; i++) {
                    if (cnt[i] < 1) {
                        b = false;
                        break;
                    }
                }
                while (b) {
                    res += (n - r);
                    cnt[s[l] - 'a']--;
                    for (int i = 0; i < 3; i++) {
                        if (cnt[i] < 1) {
                            b = false;
                            break;
                        }
                    }
                    l++;
                }
            }
            return res;
        }
};


// Cleaner Solution 
class Solution {
    public:
        int numberOfSubstrings(string s) {
            int res = 0, n = s.size(), l = 0;
            vector<int> cnt(3, 0);
            for (int r = 0; r < n; r++) {
                cnt[s[r] - 'a']++;
                while (cnt[0] && cnt[1] && cnt[2]) {
                    res += (n - r);
                    cnt[s[l] - 'a']--;
                    l++;
                }
            }
            return res;
        }
};