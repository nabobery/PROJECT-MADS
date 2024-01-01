// 1624. Largest Substring Between Two Equal Characters

// Solution 1 by maintaining first and last index of each character
// Time complexity: O(n)
// Space complexity: O(1)
class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        int res = -1;
        int first[26], last[26];
        memset(first, -1, sizeof(first));
        memset(last, -1, sizeof(last));
        for(int i = 0; i < s.size();i++){
            if(first[s[i] - 'a'] == -1) first[s[i] - 'a'] = i;
            last[s[i] - 'a'] = i;
        }
        for(int i = 0; i < 26;i++) res = max(res, last[i] - first[i] - 1);
        return res;
    }
};

// Solution 2 by maintaining only first index of each character
// Time complexity: O(n)
// Space complexity: O(1)
class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        int res = -1;
        int first[26];
        memset(first, -1, sizeof(first));
        for(int i = 0; i < s.size();i++){
            if(first[s[i] - 'a'] == -1) first[s[i] - 'a'] = i;
            else res = max(res, i - first[s[i] - 'a'] - 1);
        }
        return res;
    }
};