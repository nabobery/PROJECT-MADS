// 242. Valid Anagram
// my naive solution O(n) space and time
class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> count_s(26,0), count_t(26,0);
        for(char c : s) count_s[c - 'a']++;
        for(char c : t) count_t[c - 'a']++;
        return (count_s == count_t);
    }
};

// another solution using only one array
class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;
        int count[26] = {0};
        for(int i = 0; i < s.size();i++){
            count[s[i] - 'a']++;
            count[t[i] - 'a']--;
        }
        for(auto c : count) if(c) return false;
        return true;

    }
};
