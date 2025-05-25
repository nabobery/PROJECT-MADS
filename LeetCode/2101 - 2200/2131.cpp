// 2131. Longest Palindrome by Concatenating Two Letter Words

// Solution 1: Greedy Approach using Hash Map
// Time Complexity: O(n) where n is the number of words
// Space Complexity: O(n) for storing the frequency of words
class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        int res = 0;
        bool alreadyTaken = false;
        unordered_map<string, int> mp;
        for(auto& word: words) mp[word]++;
        for(auto& it: mp){
            string word = it.first;
            int cnt = it.second;
            if(word[0] == word[1]){
                res += (cnt/2 * 4);
                if(cnt%2 == 1 && !alreadyTaken){
                    res += 2;
                    alreadyTaken = true;
                }
            }
            else{
                string rev;
                for(int i = 1; i >= 0;i--) rev += word[i];
                if(mp.count(rev)) res += min(mp[rev], cnt) * 2;
            }
        }
        return res;
    }
};
