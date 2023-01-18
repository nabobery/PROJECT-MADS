// 1061. Lexicographically Smallest Equivalent String

class Solution {
public:
    int representative[26];
    int find(int x){
        if(representative[x] != x){
            representative[x] = find(representative[x]);
        }
        return representative[x];
    }
    void Union(int x, int y){
        x = find(x);
        y = find(y);
        if(x == y) return;
        else if(x < y) representative[y] = representative[x];
        else representative[x] = representative[y];
    }
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        for(int i = 0; i < 26;i++) representative[i] = i;
        for(int i = 0; i < s1.size();i++){
            Union(s1[i]-'a', s2[i]-'a');
        }
        string result = "";
        for(int i = 0; i < baseStr.size();i++){
            result += (char)(find(baseStr[i] - 'a') + 'a');
        }
        return result;
    }
};
