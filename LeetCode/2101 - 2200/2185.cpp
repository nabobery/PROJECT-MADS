// 2185. Counting Words With a Given Prefix

// Solution 1: Bruteforce and Straight forward
// Time complexity: O(n)
// Space complexity: O(n)
class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int res = 0, n= pref.size();
        for(string& word : words)
            if(word.size() >= n && word.substr(0, n) == pref) res++;
        return res;
    }
};