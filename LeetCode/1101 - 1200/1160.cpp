// 1160. Find Words That Can Be Formed by Characters

// Solution 1 - Using Frequency Array
// Time Complexity = O(n), where n is the total number of characters in all the words
// Space Complexity = O(1), since the frequency array is of constant size
class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        vector<int> count(26, 0);
        for(auto ch : chars) count[ch - 'a']++;
        int res = 0;
        for(auto word : words){
            vector<int> temp (26, 0);
            for(auto ch : word) temp[ch - 'a']++;
            bool b = true;
            for(int i = 0; i < 26;i++){
                if(count[i] < temp[i]){
                    b = false;
                    break;
                }
            }
            if(b) res += word.size();
        }
        return res;
    }
};