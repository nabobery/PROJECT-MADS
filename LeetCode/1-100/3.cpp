// 3. Longest Substring Without Repeating Characters

// O(n) time and O(unique char) space solution
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int start = 0, n = s.size(), result = 0;
        if(n==0) return 0;
        map<char,int> mp;
        for(int i = 0; i < n;i++){
            if(!mp.count(s[i])) mp[s[i]] = i;
            else{
                start = max(start,mp[s[i]]+1);
                mp[s[i]] = i;
            }
            result = max(i-start+1, result);
        }
        result = max(n-start, result);
        return result;
    }
};

