// 2942. Find Words Containing Character

// Solution 1: Simple Iteration
// Time Complexity: O(n * m) where n is the number of words and m is the length of the longest word
// Space Complexity: O(1)
class Solution {
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {
        int n = words.size();
        vector<int> res;
        for(int i = 0; i < n;i++){
            bool b = false;
            for(char& ch : words[i]){
                if(ch == x){
                    b = true;
                    break;
                }
            }
            if(b) res.push_back(i);
        }
        return res;
    }
};