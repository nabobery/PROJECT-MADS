// 1935. Maximum Number of Words You Can Type

// Solution 1: Straightforward and Simple
// Time Complexity: O(n) 
// Space Complexity: O(1)
class Solution {
public:
    bool checkIfBroken(string& word, vector<bool>& broken){
        for(auto& ch: word) if(broken[ch-'a']) return true;
        return false;
    }
    int canBeTypedWords(string text, string brokenLetters) {
        string word;
        int res = 0;
        vector<bool> broken(26, false);
        for(auto& ch: brokenLetters) broken[ch - 'a'] = true;
        for(auto& ch: text){
            if(ch != ' ') word += ch;
            else{
                if(!checkIfBroken(word, broken)) res++;
                word = "";
            }
        }
        if(!checkIfBroken(word, broken)) res++;
        return res;
    }
};