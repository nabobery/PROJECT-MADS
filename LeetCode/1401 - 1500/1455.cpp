// 1455. Check If a Word Occurs As a Prefix of Any Word in a Sentence

// Solution 1 (Naive): Using stringstream
// Time complexity: O(n)
// Space complexity: O(n)
class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        stringstream ss(sentence);
        string word;
        vector<string> words;
        while(ss >> word) words.push_back(word);
        int n = searchWord.size();
        for(int i = 0; i < words.size();i++)
            if(n <= words[i].size() && words[i].substr(0,n) == searchWord) return i+1;
        return -1;
    }
};

// Solution 2 (Optimized): Using stringstream
// Time complexity: O(n)
// Space complexity: O(1)
class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        stringstream ss(sentence);
        string word;
        int idx = 1;
        while(ss >> word){
            if(word.size() >= searchWord.size() && word.substr(0, searchWord.size()) == searchWord) return idx;
            idx++;
        }
        return -1;
    }
};