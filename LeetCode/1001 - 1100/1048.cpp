// 1048. Longest String Chain

// Solution1 DP Solution with Hashmap
// Time Complexity: O(nlogn + n * l^2)
// Space Complexity: O(n)
class Solution {
public:
    int longestStrChain(vector<string>& words) {
        map<int, unordered_set<string>> mp;
        for(auto str : words) mp[str.size()].insert(str);
        unordered_map<string, int> dp;
        int result = 1;
        for(auto it = mp.rbegin(); it != mp.rend();it++){
            if(!mp.count(it->first-1)) continue;
            for(auto w : it->second){
                int word = dp[w] ? dp[w] : 1;
                for(int i = 0; i < w.size();i++){
                    string temp = w.substr(0,i) + w.substr(i+1);
                    if(mp[it->first-1].count(temp)){
                        dp[temp] = max(dp[temp], word + 1);
                        result = max(result, dp[temp]);
                    }
                }
            }
        }
        return result;
    }
};

// Solution1 using vector instead of map is faster
class Solution {
public:
    int longestStrChain(vector<string>& words) {
        vector<unordered_set<string>> mp(17);
        for(auto str : words) mp[str.size()].insert(str);
        unordered_map<string, int> dp;
        int result = 1;
        for(auto it = 16; it > 0;it--){
            if(mp[it - 1].empty()) continue;
            for(auto w : mp[it]){
                int word = dp[w] ? dp[w] : 1;
                for(int i = 0; i < w.size();i++){
                    string temp = w.substr(0,i) + w.substr(i+1);
                    if(mp[it-1].count(temp)){
                        dp[temp] = max(dp[temp], word + 1);
                        result = max(result, dp[temp]);
                    }
                }
            }
        }
        return result;
    }
};

// Solution 2 DP Solution using sorting (Slower than Solution1)
// Time Complexity: O(nlogn + n * l^2)
// Space Complexity: O(n)
class Solution {
public:
    int longestStrChain(vector<string>& words) {
        unordered_map<string, int> dp;
        int res = 1;
        sort(words.begin(), words.end(), [](const string &l, const string &r) { return l.size() < r.size(); });
        for (string word : words) {
            dp[word] = 1;
            for (int i = 0; i < word.size(); i++) {
                string prev = word.substr(0, i) + word.substr(i + 1);
                if (dp.find(prev) != dp.end()) {
                    dp[word] = max(dp[word], dp[prev] + 1);
                    res = max(res, dp[word]);
                }
            }
        }
        return res;
    }
};

// Solution 3 DP Solution by DFS and Memoization by decreasing the length of the word
// Slowest of all three solutions
// Time Complexity: O(n * l^2)
// Space Complexity: O(n)
class Solution {
public:
    unordered_set<string> words;
    unordered_map<string, int> dp;
    int longestStrChain(vector<string>& words) {
        for(auto word : words) this->words.insert(word);
        int result = 1;
        for(auto word : words) result = max(result, dfs(word));
        return result;
    }
    int dfs(string word){
        if(dp.count(word)) return dp[word];
        int result = 1;
        for(int i = 0; i < word.size();i++){
            string temp = word.substr(0,i) + word.substr(i+1);
            if(words.count(temp)) result = max(result, dfs(temp) + 1);
        }
        dp[word] = result;
        return result;
    }
};
