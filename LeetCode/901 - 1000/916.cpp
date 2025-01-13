// 916. Word Subsets

// Solution 1: Using Counting and storing the max frequency of each character
// Time Complexity: O(m + n) where m is the total number of characters in words1 and n is the total number of characters in words2
// Space Complexity: O(1) as the frequency array will have a fixed size of 26
class Solution {
public:
    int temp[26], cnt[26];
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<string> res;
        int s1 = words1.size(), s2 = words2.size();
        memset(cnt, 0, sizeof(cnt));
        for(int i = 0; i < s2;i++){
            memset(temp, 0, sizeof(temp));
            for(int j = 0; j < words2[i].size();j++) temp[words2[i][j] - 'a']++;
            for(int i = 0; i < 26;i++)
                cnt[i] = max(cnt[i], temp[i]);
        }
        for(int i = 0; i < s1;i++){
            bool subset = true;
            memset(temp, 0, sizeof(temp));
            for(int j = 0; j < words1[i].size();j++) temp[words1[i][j] - 'a']++;
            for(int j = 0; j < 26;j++){
                if(temp[j] < cnt[j]){
                    subset = false;
                    break;
                }
            }
            if(subset) res.push_back(words1[i]);
        }
        return res;
    }
};