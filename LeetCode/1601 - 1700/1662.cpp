// 1662. Check If Two String Arrays are Equivalent

// Solution 1 Easy and Naive
// Time Complexity = O(sum(word1[i].size() + word2[i].size())
// Space Complexity = O(sum(word1[i].size() + word2[i].size())
class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string w1, w2;
        for(auto word: word1) w1 += word;
        for(auto word: word2) w2 += word;
        return (w1 == w2);
    }
};

// Solution 2 Using Two Pointers
// Time Complexity = O(sum(word1[i].size() + word2[i].size())
// Space Complexity = O(1)
class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        int i = 0, j = 0, k = 0, l = 0;
        while(i < word1.size() && j < word2.size()){
            if(word1[i][k] != word2[j][l]) return false;
            k++;
            l++;
            if(k == word1[i].size()){
                i++;
                k = 0;
            }
            if(l == word2[j].size()){
                j++;
                l = 0;
            }
        }
        return (i == word1.size() && j == word2.size());
    }
};