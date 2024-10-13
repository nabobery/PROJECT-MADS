// 884. Uncommon Words from Two Sentences

// Solution 1: Using unordered_map
// Time complexity: O(n)
// Space complexity: O(n)
class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string, int> mp;
        stringstream ss1(s1), ss2(s2);
        string word;
        while(ss1 >> word) mp[word]++;
        while(ss2 >> word) mp[word]++;
        vector<string> res;
        for(auto it: mp)
            if(it.second == 1) res.push_back(it.first);
        return res;
    }
};