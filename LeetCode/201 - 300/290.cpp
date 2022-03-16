// 290. Word Pattern

// my naive wrong solution
/*class Solution {
public:
    bool wordPattern(string pattern, string s) {
        map<char,string> m;
        int i = 0;
        string word = "";
        for(char ch : s){
            if(ch == ' '){
                if(m.find(pattern[i]) == m.end()){
                    m[pattern[i]] = word;
                }
                else{
                    bool flag = false;
                    for(auto p : m){
                        if(p.first != pattern[i] && p.second == word){
                            flag = true;
                        }
                    }
                    if(m[pattern[i]] != word || flag){
                        return false;
                    }
                }
                //cout<<i<<" "<<word<<"\n";
                i++;
                word = "";
            }
            else{
                word = word + ch;
            }
        }
        return(m[pattern[i]] == word);
    }
};*/

// O(m) time and space solution where m is number of words in s
class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map <char,int> pi;
        unordered_map<string,int> si;
        istringstream in(s);
        string word;
        int i = 0, n = pattern.size();
        for(word; in >> word;i++){
            if(i == n || pi[pattern[i]] != si[word])
                return false;
            pi[pattern[i]] = si[word] = i+1;
        }
        return (i == n);
    }
};

