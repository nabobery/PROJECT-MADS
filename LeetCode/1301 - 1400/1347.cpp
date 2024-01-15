// 1347. Minimum Number of Steps to Make Two Strings Anagram

// Solution 1 by using frequency array
// Time complexity: O(n)
// Space complexity: O(1)
class Solution {
public:
    int minSteps(string s, string t) {
        int cnt1[26] = {0}, cnt2[26] = {0};
        for(int i = 0; i < s.size();i++){
            cnt1[s[i] - 'a']++;
            cnt2[t[i] - 'a']++;
        }
        int res = 0;
        for(int i = 0; i < 26;i++) 
            if(cnt1[i] > cnt2[i]) res += (cnt1[i] - cnt2[i]);
        return res;
    }
};

// Optimized and Cleaned Solution 1
class Solution {
public:
    int minSteps(string s, string t) {
        int cnt[26] = {0};
        for(int i = 0; i < s.size();i++){
            cnt[s[i] - 'a']++;
            cnt[t[i] - 'a']--;
        }
        int res = 0;
        for(int i : cnt) if(i > 0) res += i;
        return res;
    }
};