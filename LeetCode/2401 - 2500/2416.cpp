// 2416. Sum of Prefix Scores of Strings

// Solution 1 using Trie
// Time complexity: O(n*m) where n is the number of words and m is the average length of the words
// Space complexity: O(n*m)
class TrieNode {
public:
    unordered_map<char, TrieNode*> children;
    int count;
    TrieNode(){
        count = 0;
    }
};

TrieNode* buildTrie(vector<string>& dictionary) {
    auto root = new TrieNode();
    for (auto& word : dictionary) {
        auto node = root;
        for (auto& c : word) {
            if (node->children.find(c) == node->children.end())
                node->children[c] = new TrieNode();
            node = node->children[c];
            node->count++;
        }
    }
    return root;
}

int helper(TrieNode* root, string& word){
    int res = 0;
    // cout<<word<<"\n";
    for (auto& c : word) {
        if (root->children.find(c) == root->children.end()) break;
        root = root->children[c];
        res += root->count;
        // cout<<c<<" "<<root->count<<"\n";
    }
    return res;
}

class Solution {
public:
    vector<int> sumPrefixScores(vector<string>& words) {
        auto root = buildTrie(words);
        int n = words.size();
        vector<int> res(n);
        for(int i = 0; i < n;i++)
            res[i] = helper(root, words[i]);
        return res;
    }
};

// Cleaner, efficient and more readable solution

struct TrieNode {
    TrieNode* children[26] = {};
    int count = 0;
};

class Solution {
public:
    vector<int> sumPrefixScores(vector<string>& words) {
        TrieNode* root = new TrieNode();
        for (string& word : words) {
            TrieNode* node = root;
            for (char c : word) {
                if (!node->children[c - 'a']) {
                    node->children[c - 'a'] = new TrieNode();
                }
                node = node->children[c - 'a'];
                node->count++;
            }
        }
        vector<int> res;
        for (string& word : words) {
            TrieNode* node = root;
            int score = 0;
            for (char c : word) {
                node = node->children[c - 'a'];
                if (!node) break;
                score += node->count;
            }
            res.push_back(score);
        }
        return res;
    }
};

