// 1930. Unique Length-3 Palindromic Subsequences

// Solution 1 using Hashset and first and last occurence of each character
// Time complexity: O(n)
// Space complexity: O(1)
class Solution {
public:
    int countPalindromicSubsequence(string s) {
        vector<int> first(26, -1), last(26, -1);
        for(int i = 0; i < s.size();i++){
            if(first[s[i] - 'a'] == -1) first[s[i] - 'a'] = i;
            last[s[i] - 'a'] = i;
        }
        int res = 0;
        for(int i = 0; i < 26;i++){
            if(first[i] != -1 && first[i] != last[i] && last[i] > first[i]+1){
                unordered_set<char> st(s.begin()+ first[i]+1, s.begin() + last[i]);
                res += st.size();
            }
        }
        return res;
    }
};

