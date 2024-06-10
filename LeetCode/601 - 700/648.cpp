// 648. Replace Words

// Solution 1 using Stringstream and unordered_set
// Time complexity: O(n) 
// Space complexity: O(n)
class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        unordered_set<string> dict(dictionary.begin(), dictionary.end());
        stringstream s(sentence);
        string word, res;
        while(s >> word){
            int n = word.size();
            string temp;
            for(int i = 0;i < n;i++){
                temp += word[i];
                if(dict.count(temp))
                    break;
            }
            if(!res.empty()) res += " ";
            res += temp;
        }
        return res;
    }
};

// Solution 2 using Trie
// Time complexity: O(n)  Faster than Solution 1
// Space complexity: O(n) Not Memory Efficient as Solution 1

class TrieNode{
public:
    TrieNode* children[26];
    bool isEnd;
    TrieNode(){
        for(int i = 0;i < 26;i++)
            children[i] = nullptr;
        isEnd = false;
    }
};

class Trie{
public:
    TrieNode* root;
    Trie(){
        root = new TrieNode();
    }
    
    void insert(string word){
        TrieNode* node = root;
        for(char c : word){
            if(node->children[c - 'a'] == nullptr)
                node->children[c - 'a'] = new TrieNode();
            node = node->children[c - 'a'];
        }
        node->isEnd = true;
    }
    
    string search(string word){
        TrieNode* node = root;
        string temp;
        for(char c : word){
            if(node->children[c - 'a'] == nullptr || node->isEnd)
                break;
            temp += c;
            node = node->children[c - 'a'];
        }
        return node->isEnd ? temp : word;
    }
};

class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        Trie trie;
        for(string word : dictionary)
            trie.insert(word);
        stringstream s(sentence);
        string word, res;
        while(s >> word){
            if(!res.empty()) res += " ";
            res += trie.search(word);
        }
        return res;
    }
};