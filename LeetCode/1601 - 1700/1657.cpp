// 1657. Determine if Two Strings Are Close

// Naive and Straightforward solution
// Operation 1: Swap any two existing characters which takes care of ordering of word2 so that it becomes word1
// Operation 2: Transform every occurrence of one existing character into another existing character in word2
// So, we need to see if we can use operation 2 to transform word2 into word1
// Time complexity: O(n)
// Space complexity: O(1)
class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if(word1.size() != word2.size()) return false;
        unordered_map<char,int> mp1, mp2;
        for(int i = 0; i < word1.size();i++){
            mp1[word1[i]]++;
            mp2[word2[i]]++;
        }
        for(auto it : mp1){
            if(it.second == mp2[it.first]) continue;
            bool b = false;
            for(auto i : mp2){
                if(it.second == i.second && mp1.count(i.first) && mp1[i.first] != i.second){
                    mp2[i.first] = mp2[it.first];
                    mp2[it.first] = i.second;
                    b = true;
                    break;
                }
            }
            if(!b) return b;
        }   
        return mp1 == mp2;
    }
};