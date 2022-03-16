// 211. Design Add and Search Words Data Structure

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */

// using unordered map
// we create a map mapping from size to strings of that size and then search and return true
// Time Complexity : O(N * word.size()) space : O(N) (N is number of words)
class WordDictionary {
    unordered_map<int, vector<string>>words;

    bool isEqual(string w1, string w2){
        for(int i = 0; i < w1.size(); i++){
            if(w2[i] == '.')
                continue;
            if(w1[i] != w2[i])
                return false;
        }
        return true;
    }
public:
    WordDictionary() {}

    void addWord(string word) {
        words[word.size()].push_back(word);
    }

    bool search(string word) {
        for(auto s: words[word.size()])
            if(isEqual(s, word))
                return true;
        return false;
    }

};

// using trie


