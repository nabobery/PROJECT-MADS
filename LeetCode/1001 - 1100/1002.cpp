// 1002. Find Common Characters

// Solution 1: Using Hash Map by maintaining the minimum frequency of each character
// Time Complexity: O(n * m) where n is the number of strings and m is the maximum length of the string
// Space Complexity: O(1) as the hash map will have at most 26 keys
class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<int> cnt(26, 100);
        vector<string> res;
        for(string word : words){
            vector<int> curr(26, 0);
            for(char ch : word) curr[ch - 'a']++;
            for(int i = 0; i < 26;i++) cnt[i] = min(cnt[i], curr[i]);
        }
        string str = "`";
        for(int i = 0; i < 26;i++){
            str[0]++;
            for(int j = 0; j < cnt[i];j++) res.push_back(str);
        }
        return res;
    }
};

