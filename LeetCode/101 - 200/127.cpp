// 127. Word Ladder

// Solution 1 using normal BFS (Very slow)
// Time complexity: O(n*m)
// Space complexity: O(m)
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> unvisited(wordList.begin(), wordList.end());
        if(!unvisited.count(endWord)) return 0;
        queue <string> q;
        q.push(beginWord);
        int result = 1;
        // BFS
        while(!q.empty()){
            int n = q.size();
            // For each word in the current level
            for(int i = 0; i < n;i++){
                string curr = q.front();
                q.pop();
                // If the current word is the endWord, return the result
                if(curr == endWord) return result;
                unvisited.erase(curr);
                // try all possible words by changing one character at a time
                for(int j = 0; j < curr.size();j++){
                    char temp = curr[j];
                    for(char k = 'a'; k <= 'z';k++){
                        curr[j] = k;
                        if(unvisited.count(curr))
                            q.push(curr);
                    }
                    curr[j] = temp;
                }
            }
            result++;
        }
        // If the endWord is not found, return 0
        return 0;    
    }
};


// Solution 2 using bidirectional bfs
// Time complexity: O(n*m^2)
// Space complexity: O(m)
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> s1, s2, dict(wordList.begin(),wordList.end());
        if(!dict.count(endWord)) return 0;
        int n = beginWord.size(), result = 0;
        s1.insert(beginWord);
        s2.insert(endWord);
        while(!s1.empty() && !s2.empty()){
            result++;
            if(s1.size() > s2.size())
                swap(s1,s2);
            unordered_set<string> curr;
            for(string w : s1){
                for(int i = 0;i < n;i++){
                    char temp = w[i];
                    for(char x = 'a';x <='z';x++){
                        w[i]=x;
                        if(s2.count(w))
                            return result+1;
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

