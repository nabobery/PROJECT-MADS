// 472. Concatenated Words

class Solution {
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        unordered_set<string> dict(words.begin(), words.end());
        vector<string> res;
        for (auto word : words) {
            int length = word.size();
            vector<bool> dp(length + 1);
            dp[0] = true;
            for (int i = 1; i <= length; ++i) {
                for (int j = (i == length ? 1 : 0); !dp[i] && j < i; ++j) {
                    dp[i] = dp[j] && dict.count(word.substr(j, i - j));
                }
            }
            if (dp[length]) {
                res.push_back(word);
            }
        }
        return res;
    }
};
