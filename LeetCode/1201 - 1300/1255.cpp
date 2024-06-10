// 1255. Maximum Score Words Formed by Letters

// Solution 1 using Recursion + Backtracking + Pruning
// Time complexity: O(2^n*n)
// Space complexity: O(n)
class Solution {
public:
    int res;
    void helper(int ind, vector<string>& words, vector<int>& cnt,vector<int>& score, int curr){
        if(ind >= words.size()){
            res = max(res, curr);
            return;
        }
        bool canTake = true;
        vector<int> temp(26,0);
        for(char c : words[ind]) temp[c-'a']++;
        for(int i = 0; i < 26;i++){
            if(cnt[i] < temp[i]){
                canTake = false;
                break;
            }
        }
        if(!canTake) helper(ind+1, words, cnt, score, curr);
        else{
            for(int i = 0; i < 26;i++){
                cnt[i] -= temp[i];
                curr += score[i]*temp[i];
            }
            helper(ind+1, words, cnt, score, curr);
            for(int i = 0; i < 26;i++){
                cnt[i] += temp[i];
                curr -= score[i]*temp[i];
            }
            helper(ind+1, words, cnt, score, curr);
        }
    }
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        vector<int> cnt(26,0);
        res = 0;
        for(char c : letters) cnt[c-'a']++;
        helper(0, words, cnt, score, 0);
        return res;
    }
}; 

// Solution 2 iterative for every possible subset of words
// Time complexity: O(2^n*n)
// Space complexity: O(n)

class Solution {
public:
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        vector<int> cnt(26,0);
        for(char c : letters) cnt[c-'a']++;
        int n = words.size();
        int res = 0;
        for(int i = 0; i < (1<<n);i++){
            vector<int> temp(26,0);
            int curr = 0;
            for(int j = 0; j < n;j++){
                if(i & (1<<j)){
                    for(char c : words[j]) temp[c-'a']++;
                }
            }
            bool canTake = true;
            for(int j = 0; j < 26;j++){
                if(cnt[j] < temp[j]){
                    canTake = false;
                    break;
                }
            }
            if(canTake){
                for(int j = 0; j < 26;j++){
                    cnt[j] -= temp[j];
                    curr += score[j]*temp[j];
                }
                res = max(res, curr);
                for(int j = 0; j < 26;j++){
                    cnt[j] += temp[j];
                    curr -= score[j]*temp[j];
                }
            }
        }
        return res;
    }
};
