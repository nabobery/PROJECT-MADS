// 1408. String Matching in an Array

// Solution 1: Bruteforce using Hash set
// Time complexity: O(n^3*l^2)
// Space complexity: O(n)

class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        unordered_set<string> s(words.begin(), words.end()), result;
        vector<string> res;
        for(string& word: words){
            for(int i = 0; i < word.size();i++){
                for(int j = i; j < word.size();j++){
                    string temp = word.substr(i, j-i+1);
                    if(s.count(temp) && temp != word){
                        result.insert(temp);
                    }
                }
            }
        }
        for(auto it : result) res.push_back(it);
        return res;
    }
};

// Efficient Solution 1 (As all words are unique)
// Time complexity: O(n^2*l^2)
// Space complexity: O(n)
class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        vector<string> res;
        for(int i = 0; i < words.size(); i++){
            for(int j = 0; j < words.size(); j++){
                if(i != j && words[j].find(words[i]) != string::npos){
                    res.push_back(words[i]);
                    break;
                }
            }
        }
        return res;
    }
};


