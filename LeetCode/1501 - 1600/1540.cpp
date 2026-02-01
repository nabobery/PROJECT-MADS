// 1540. Can Convert String in K Moves

// Solution 1: Using Hash Map and storing the frequency of each difference
// Time Complexity: O(n)
// Space Complexity: O(26) ~ O(1)
class Solution {
public:
    bool canConvertString(string s, string t, int k) {
        if(s.size() != t.size()) return false;
        unordered_map<int, int> diffToCount;
        int n = s.size();
        for(int i = 0; i < n;i++){
            diffToCount[(t[i] - s[i] +26)%26]++;
        }
        for(auto& it : diffToCount){
            if(it.first == 0) continue;
            if((it.second-1)*26 + it.first > k) return false;
        }
        return true;
    }
};

// Solution 2: Using Array to store the frequency of each difference
// Time Complexity: O(n)
// Space Complexity: O(26) ~ O(1)
class Solution {
public:
    bool canConvertString(string s, string t, int k) {
        if (s.size() != t.size()) return false;
        vector<int> cnt(26, 0);
        int n = s.size();
        for (int i = 0; i < n; i++) {
            int diff = (t[i] - s[i] + 26) % 26;
            cnt[diff]++;
        }
        for (int diff = 1; diff < 26; diff++) {
            if (cnt[diff] > 0) {
                if ((cnt[diff] - 1) * 26 + diff > k)
                    return false;
            }
        }
        return true;
    }
};
