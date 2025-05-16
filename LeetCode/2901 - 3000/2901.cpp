// 2901. Longest Unequal Adjacent Groups Subsequence II

// Solution 1: By Finding the Maximum Length of the Subsequence that Satisfies the Condition (Time Limit Exceeded) using Recursion
// Time Complexity: O(n^3) where n is the number of words
// Space Complexity: O(n)
class Solution {
public:
    vector<int> selected;
    void helper(int ind, vector<string>& words, vector<int>& groups, vector<vector<bool>>& hammingDist, vector<int>& seq){
        seq.push_back(ind);
        if (seq.size() > selected.size()) selected = seq;
        if(ind+1 == words.size()){
            seq.pop_back();
            return;
        }
        for(int j = ind+1; j < words.size();j++){
            if(groups[ind] != groups[j] && hammingDist[ind][j])
                helper(j, words, groups, hammingDist, seq);
        }
        seq.pop_back();
    }
    vector<string> getWordsInLongestSubsequence(vector<string>& words,
                                                vector<int>& groups) {
        int n = groups.size();
        vector<vector<bool>> hammingDist(n, vector<bool>(n, false));
        for(int i = 0; i < n;i++){
            for(int j = i+1; j < n;j++){
                if(words[i].size() == words[j].size()){
                    int curr = 0, p = 0;
                    while(curr < 2 && p < words[i].size()){
                        if(words[i][p] != words[j][p]) curr++;
                        p++;
                    }
                    hammingDist[i][j] = (curr == 1);
                }
            }
        }
        for(int i = 0; i < n;i++){
            vector<int> seq;
            helper(i, words, groups, hammingDist, seq);
        }
        vector<string> res;
        for (int idx : selected)
            res.push_back(words[idx]);
        return res;
    }
};

// Solution 2: Using Dynamic Programming
// Time Complexity: O(n^2) where n is the number of words
// Space Complexity: O(n)
class Solution {
public:
    vector<string> getWordsInLongestSubsequence(vector<string>& words,
                                                vector<int>& groups) {
        int n = words.size();
        // Precompute the Hamming distance between all pairs of words
        // and store the results in a 2D vector
        vector<vector<bool>> good(n, vector<bool>(n, false));
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (words[i].size() != words[j].size()) continue;
                int diffs = 0;
                for (int p = 0; p < words[i].size() && diffs < 2; ++p) {
                    if (words[i][p] != words[j][p]) ++diffs;
                }
                if (diffs == 1) good[i][j] = true;
            }
        }
        // Initialize the dp array and the next array
        // dp[i] stores the length of the longest subsequence starting at index i
        vector<int> dp(n, 1), nxt(n, -1);
        for (int i = n - 1; i >= 0; --i) {
            for (int j = i + 1; j < n; ++j) {
                // If the groups are different and the words are good,
                // update the dp array and the next array
                // to keep track of the longest subsequence
                if (groups[i] != groups[j] && good[i][j]) {
                    if (dp[j] + 1 > dp[i]) {
                        dp[i] = dp[j] + 1;
                        nxt[i] = j;
                    }
                }
            }
        }

        // Find the starting index of the longest subsequence
        // by looking for the maximum value in the dp array        
        int bestStart = 0;
        for (int i = 1; i < n; ++i) {
            if (dp[i] > dp[bestStart]) bestStart = i;
        }

        // Reconstruct the longest subsequence using the next array
        // and store the words in the result vector
        vector<string> result;
        for (int cur = bestStart; cur != -1; cur = nxt[cur]) {
            result.push_back(words[cur]);
        }
        return result;
    }
};