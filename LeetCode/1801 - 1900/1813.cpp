// 1813. Sentence Similarity III

// Solution 1 using Two Pointers
// Time complexity: O(n)
// Space complexity: O(1)
class Solution {
public:
    bool areSentencesSimilar(string sentence1, string sentence2) {
        if(sentence1 == sentence2) return true;
        stringstream ss(sentence1);
        vector<string> s1, s2;
        string word;
        while (ss >> word) s1.push_back(word);
        ss.str(sentence2);ss.clear();
        while(ss >> word) s2.push_back(word);
        if (s1.size() > s2.size()) swap(s1, s2);
        int l = -1, r = s2.size(), i, j;
        for(i = 0; i < s1.size();i++){
            if(s1[i] == s2[l+1]) l++;
            else break;
        }
        for(j = s1.size()-1; j >= i;j--){
            if(s1[j] == s2[r-1]) r--;
            else break;
        }
        return (r-l-1 == s2.size() - s1.size());
    }
};