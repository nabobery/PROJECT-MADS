// 2707. Extra Characters in a String

// TLE Recursion Solution
class Solution {
public:
    int helper(int i, string s, unordered_set<string>& dict){
        if(i == s.size()) return 0;
        int res = s.size();
        for(int j = i; j < s.size();j++){
            if(dict.count(s.substr(i,j-i+1))) {
                res = min(res, helper(j+1, s, dict));
            }
            else res = min(res, j-i+1 + helper(j+1,s,dict));
        }
        return res;
    }
    int minExtraChar(string s, vector<string>& dictionary) {
        unordered_set<string> dict(dictionary.begin(), dictionary.end());
        return helper(0, s, dict);
    }
};

// Time Complexity: O(n^3)
// Space Complexity: O(n)
// Recursion + Memoization Solution
class Solution {
public:
    // helper function to find min extra characters in s[i..n-1]
    int helper(int i, string s, unordered_set<string>& dict, vector<int>& dp){
        // base case when i reaches end of string
        if(i == s.size()) return 0;
        // if already calculated, return
        if(dp[i] != s.size()) return dp[i];
        // else calculate
        int res = s.size();
        // try all possible substrings starting from i
        for(int j = i; j < s.size();j++){
            // if substring is present in dictionary, no extra characters needed
            if(dict.count(s.substr(i,j-i+1))) {
                // find min extra characters in s[j+1..n-1]
                res = min(res, helper(j+1, s, dict,dp));
            }
            // else find min extra characters in s[j+1..n-1] + j-i+1
            else res = min(res, j-i+1 + helper(j+1,s,dict,dp));
        }
        // store and return
        return dp[i] = res;
    }
    int minExtraChar(string s, vector<string>& dictionary) {
        // hashset for O(1) lookup time
        unordered_set<string> dict(dictionary.begin(), dictionary.end());
        // dp[i] = min extra characters in s[i..n-1]
        vector<int> dp(s.size(), s.size());
        // call helper function
        return helper(0, s, dict, dp);
    }
};

// Top Down DP Solution with nested function and using hashmap for memoization
// Time Complexity: O(n^3)
// Space Complexity: O(n)
class Solution {
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        // hashset for O(1) lookup time
        unordered_set<string> dict(dictionary.begin(), dictionary.end());
        // dp[i] = min extra characters in s[i..n-1]
        unordered_map<int,int> dp;
        // nested function to find min extra characters in s[i..n-1]
        function<int(int)> helper = [&](int i){
            // base case when i reaches end of string
            if(i == s.size()) return 0;
            // if already calculated, return
            if(dp.count(i)) return dp[i];
            // else calculate
            // to consider the case when s[i..n-1] is not present in dictionary
            int res = helper(i+1)+1;
            // try all possible substrings starting from i
            for(int j = i; j < s.size();j++){
                // if substring is present in dictionary, no extra characters needed
                if(dict.count(s.substr(i,j-i+1))) {
                    // find min extra characters in s[j+1..n-1]
                    res = min(res, helper(j+1));
                }
            }
            // store and return
            return dp[i] = res;
        };
        // call helper function
        return helper(0);
    }
};

// Bottom Up DP Solution
// Time Complexity: O(n^3)
// Space Complexity: O(n)
class Solution {
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        int n = s.size();
        // dp[i] = min extra characters in s[i..n-1]
        vector<int> dp(n+1,0);
        // hashset for O(1) lookup time
        unordered_set<string> dict(dictionary.begin(), dictionary.end());
        // we start from end of string
        for(int i = n-1; i >= 0;i--){
            // to consider the case when s[i..n-1] is not present in dictionary
            dp[i] = dp[i+1] + 1;
            // try all possible substrings starting from i
            for(int j = i ; j < n;j++){
                // if substring is present in dictionary, no extra characters needed
                if(dict.count(s.substr(i, j-i+1)))
                    // min extra characters in s[i..n-1] = min extra characters in s[j+1..n-1] as substring s[i,j] is present in dictionary    
                    dp[i] = min(dp[i], dp[j+1]);
            }
        }
        return dp[0];
    }
};

// Top Down DP Solution with Trie
// Time Complexity: O(n^2)
// Space Complexity: O(n)

// Class for Trie Node
class TrieNode {
public:
    unordered_map<char, TrieNode*> children;
    bool is_word;
};

class Solution {
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        int n = s.size();
        // build a trie tree from dictionary
        auto root = buildTrie(dictionary);
        // dp[i] = min extra characters in s[i..n-1]
        unordered_map<int,int> dp;
        // nested function to find min extra characters in s[i..n-1]
        function<int(int)> helper = [&](int i){
            // base case when i reaches end of string
            if(i == s.size()) return 0;
            // if already calculated, return
            if(dp.count(i)) return dp[i];
            // else calculate
            // to consider the case when s[i..n-1] is not present in dictionary
            int res = helper(i+1)+1;
            // try all possible substrings starting from i
            TrieNode* node = root;
            // traverse the string from i to  n
            for(int j = i; j < s.size();j++){
                char c = s[j];
                // if character not present in trie, break
                if(!node->children.count(c)) break;
                node = node->children[c];
                // if substring is present in dictionary, no extra characters needed
                if(node->is_word) res = min(res, helper(j+1));
            }
            // store and return
            return dp[i] = res;
        };
        return helper(0);
    }

    // Class to build Trie Tree
    TrieNode* buildTrie(vector<string>& dictionary) {
        // root node
        auto root = new TrieNode();
        // insert all words in dictionary into trie
        for (auto& word : dictionary) {
            // start from root
            auto node = root;
            // insert each character of word into trie
            for (auto& c : word) {
                // if character not present in trie at that position, create a new node
                if (node->children.find(c) == node->children.end()) {
                    node->children[c] = new TrieNode();
                }
                // move to next node
                node = node->children[c];
            }
            // at the end of word, mark is_word as true
            node->is_word = true;
        }
        return root;
    }
};

// Bottom Up DP Solution with Trie
// Time Complexity: O(n^2)
// Space Complexity: O(n)

// Class for Trie Node
class TrieNode {
public:
    unordered_map<char, TrieNode*> children;
    bool is_word;
};

class Solution {
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        int n = s.size();
        // build a trie tree from dictionary
        auto root = buildTrie(dictionary);
        // dp[i] = min extra characters in s[i..n-1]
        vector<int> dp(n+1,0);
        // we start from end of string
        for(int i = n-1; i >= 0;i--){
            // to consider the case when s[i..n-1] is not present in dictionary
            dp[i] = dp[i+1] + 1;
            // try all possible substrings starting from i
            TrieNode* node = root;
            // traverse the string from i to  n
            for(int j = i; j < s.size();j++){
                char c = s[j];
                // if character not present in trie, break
                if(!node->children.count(c)) break;
                node = node->children[c];
                // if substring is present in dictionary, no extra characters needed
                if(node->is_word) dp[i] = min(dp[i], dp[j+1]);
            }
        }
        return dp[0];
    }

    // Class to build Trie Tree
    TrieNode* buildTrie(vector<string>& dictionary) {
        // root node
        auto root = new TrieNode();
        // insert all words in dictionary into trie
        for (auto& word : dictionary) {
            // start from root
            auto node = root;
            // insert each character of word into trie
            for (auto& c : word) {
                // if character not present in trie at that position, create a new node
                if (node->children.find(c) == node->children.end()) {
                    node->children[c] = new TrieNode();
                }
                // move to next node
                node = node->children[c];
            }
            // at the end of word, mark is_word as true
            node->is_word = true;
        }
        return root;
    }
};