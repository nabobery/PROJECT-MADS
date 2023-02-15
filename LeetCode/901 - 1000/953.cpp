// 953. Verifying an Alien Dictionary

class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        int mp[26];
        for(int i = 0; i < 26;i++)
            mp[order[i] - 'a'] = i;
        bool flag = true;
        for(int i = 0; i < words.size()-1;i++){
            bool temp = false;
            int j, n = min(words[i].size(), words[i+1].size());
            for(j = 0; j < n;j++){
                if(mp[words[i][j] - 'a'] > mp[words[i+1][j] - 'a']){
                    temp = true;
                    break;
                }
                else if(mp[words[i][j] - 'a'] < mp[words[i+1][j] - 'a']) break;
            }
            if(temp || (j == n && words[i].size() > words[i+1].size())){
                flag = false;
                break;
            }
        }
        return flag;
    }
};