// 791. Custom Sort String

// Simple Solution 1 using Hash Table
// Time Complexity: O(S + T)
// Space Complexity: O(S + T)
class Solution {
public:
    int cnt[26];
    char ord[26];
    string customSortString(string order, string s) {
        memset(ord, 27, sizeof(ord));
        memset(cnt, 0, sizeof(cnt));
        for(int i = 0; i < order.size();i++)
            ord[i] = order[i];
        for(char c : s) cnt[c - 'a']++;
        string res;
        for(int i = 0; i < order.size();i++){
            if(cnt[ord[i] - 'a']){
                for(int j = 0; j < cnt[ord[i] - 'a'];j++) res +=ord[i];
                cnt[ord[i] - 'a'] = 0;
            }
        }
        for(int i = 0; i < 26;i++){
            if(cnt[i] != 0)
                for(int j = 0; j < cnt[i];j++) res += (i + 'a');
        }
        return res;
    }
};

