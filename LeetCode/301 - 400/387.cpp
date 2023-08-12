// 387. First Unique Character in a String

class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> firstSeen(26, -1), lastSeen(26, -1);
        int n = s.size();
        for(int i = 0; i < n; i++){
            if(firstSeen[s[i] - 'a'] == -1) firstSeen[s[i]-'a'] = i;
        }
        for(int i = n-1; i >= 0;i--){
            if(lastSeen[s[i] - 'a'] == -1) lastSeen[s[i]-'a'] = i;
        }
        int result = n;
        for(int i = 0; i < 26;i++){
            if(firstSeen[i] != -1 && firstSeen[i] == lastSeen[i]) result = min(result, firstSeen[i]);
        }
        return (result == n ? -1 : result);
    }
};