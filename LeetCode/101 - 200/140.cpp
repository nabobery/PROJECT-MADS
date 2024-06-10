// 140. Word Break II

// Solution 1 Recursion + Backtracking
// Time complexity: O(2^n)
// Space complexity: O(n)
class Solution {
public:
    vector<string> res;
    unordered_set<string> dict;
    void helper(int prev, int ind, string& s, vector<string>& curr){
        int n = s.size();
        if(ind == n){
            bool b = true;
            if(prev < n) curr.push_back(s.substr(prev+1, ind-prev));
            for(string c : curr){
                if(!dict.count(c)){
                    b = false;
                    break;
                }
            }
            if(b){
                string t = curr[0];
                for(int i = 1; i < curr.size();i++) t += (" " + curr[i]);
                res.push_back(t);
            }
            if(prev < n) curr.pop_back();
            return;
        }
        helper(prev, ind+1, s, curr);
        curr.push_back(s.substr(prev+1, ind-prev));
        helper(ind, ind+1, s, curr);
        curr.pop_back();
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        copy(wordDict.begin(),wordDict.end(),std::inserter(dict,dict.end()));
        vector<string> curr;
        helper(-1, 0, s,curr);
        return res;
    }
};

// Solution 2 using Dynamic Programming
// Time complexity: O(n^2)
// Space complexity: O(n^2)
class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict;
        // insert all words in the dictionary
        for(string word : wordDict) dict.insert(word);
        int n = s.size();
        // dp[i] stores all possible sentences that can be formed using the first i characters of s
        vector<vector<string>> dp(n+1);
        // base case
        dp[0].push_back("");
        // iterate over all characters of s
        for(int i = 1; i <= n; i++){
            // iterate over all possible splits of the string
            for(int j = 0; j < i; j++){
                // if the first j characters can be split into words and the substring from j to i is a word in the dictionary
                if(dp[j].size() > 0 && dict.count(s.substr(j,i-j)))
                    // add the substring from j to i to all possible sentences that can be formed using the first j characters of s
                    for(string str : dp[j])
                        dp[i].push_back(str + (str == "" ? "" : " ") + s.substr(j,i-j));
            }
        }
        // return all possible sentences that can be formed using the first n characters of s
        return dp[n];
    }
};