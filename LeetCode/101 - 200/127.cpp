// 127. Word Ladder
// bidirectional bfs
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> s1;
        unordered_set<string> s2;
        unordered_set<string> dict(wordList.begin(),wordList.end());
        if(!dict.count(endWord)) return 0;
        int n = beginWord.size(), result = 0;
        s1.insert(beginWord);
        s2.insert(endWord);
        while(!s1.empty() && !s2.empty()){
            result++;
            if(s1.size() > s2.size()){
                swap(s1,s2);
            }
            unordered_set<string> curr;
            for(string w : s1){
                for(int i = 0;i < n;i++){
                    char temp = w[i];
                    for(char x = 'a';x <='z';x++){
                        w[i]=x;
                        if(s2.count(w)){
                            return result+1;
                        }
                        if(!dict.count(w)) continue;
                        dict.erase(w);
                        curr.insert(w);
                    }
                    w[i] = temp;
                }
            }
            s1=curr;
        }

        return 0;
    }
};

