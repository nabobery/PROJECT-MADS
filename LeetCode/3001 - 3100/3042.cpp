// 3042. Count Prefix and Suffix Pairs I

// Solution 1: Brute Force by comparing suffix and prefix of each word
// Time Complexity: O(n^2 * m) where n is the number of words and m is the length of each word
// Space Complexity: O(1)
class Solution {
public:
    int countPrefixSuffixPairs(vector<string>& words) {
        int n = words.size(), res = 0;
        for(int i = 0; i < n-1;i++){
            int k = words[i].size();
            for(int j = i+1; j < n;j++){
                if(words[j].size() >= k){
                    string prefix = words[j].substr(0, k), suffix = words[j].substr(words[j].size() - k);
                    if(prefix == words[i] && suffix == words[i]) res++;
                }
            }
        }   
        return res;
    }
};