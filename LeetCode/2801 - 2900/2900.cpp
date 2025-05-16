// 2900. Longest Unequal Adjacent Groups Subsequence I

// Solution 1: Greedy Appraoch by just starting from 1 or 0 as 1st element and finding max length subsequence
// Time Complexity: O(n)
// Space Complexity: O(n)
class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        auto getSequence = [&](int startVal) {
            vector<int> seq;
            int prev = -1;
            for (int i = 0; i < groups.size(); ++i) {
                if (prev == -1 && groups[i] == startVal) {
                    seq.push_back(i);
                    prev = i;
                } else if (prev != -1 && groups[prev] != groups[i]) {
                    seq.push_back(i);
                    prev = i;
                }
            }
            return seq;
        };

        vector<int> seq0 = getSequence(0), seq1 = getSequence(1);

        vector<int>& selected = (seq0.size() >= seq1.size()) ? seq0 : seq1;
        vector<string> res;
        for (int idx : selected) res.push_back(words[idx]);
        return res;
    }
};
