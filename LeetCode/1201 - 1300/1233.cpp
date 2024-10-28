// 1233. Remove Sub-Folders from the Filesystem

// Solution 1 using Trie and sorting (Inefficient)
// Time complexity: O(n*k + klogk)
// Space complexity: O(n*k)
class TrieNode {
public:
    bool is_end;
    unordered_map<string, TrieNode*> children;
    TrieNode(){
        is_end = false;
    }
};

class Trie{
public:
    TrieNode* root;
    Trie(){
        root = new TrieNode();
    }
    
    void insert(vector<string> words){
        TrieNode* node = root;
        for(string word : words){
            if(!node->children.count(word))
                node->children[word] = new TrieNode();
            node = node->children[word];
        }
        node->is_end = true;
    }
    
    bool search(vector<string> words){
        TrieNode* node = root;
        for(string word: words){
            if(!node->children.count(word))
                break;
            node = node->children[word];
        }
        return node->is_end;
    }
};

class Solution {
public:
    vector<string> split(const string& str, char delimiter) {
        vector<string> tokens;
        size_t start = 0;
        size_t end = str.find(delimiter);

        while (end != string::npos) {
            string token = str.substr(start, end - start);
            if (!token.empty()) { 
                tokens.push_back(token);
            }
            start = end + 1;
            end = str.find(delimiter, start);
        }
        tokens.push_back(str.substr(start)); 
        return tokens;
    }

    vector<string> removeSubfolders(vector<string>& folder) {
        vector<vector<string>> subfolders;
        vector<string> res;
        Trie trie;
        for(string folder : folder){
            subfolders.push_back(split(folder, '/'));
        }
        sort(subfolders.begin(), subfolders.end(), 
              [](const std::vector<std::string>& a, const std::vector<std::string>& b) {
                  return a.size() < b.size();
              });
        for(auto subfolder : subfolders){
            if(!trie.search(subfolder)){
                trie.insert(subfolder);
                string path = "";
                for(string sub: subfolder) path += ("/" + sub);
                res.push_back(path);
            }
        }
        return res;
    }
};


// Solution 2 using sorting and string matching
// Time complexity: O(nlogn)
// Space complexity: O(n)
class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin(), folder.end());
        vector<string> res;
        string prev = "";
        for (const string& f : folder) {
            if (prev.empty() || f.compare(0, prev.size(), prev) != 0 || f[prev.size()] != '/') {
                res.push_back(f);
                prev = f;
            }
        }
        return res;
    }
};