// 2559. Count Vowel Strings in Ranges

// Solution 1: Using Prefix Sum
// Time Complexity: O(n)
// Space Complexity: O(n)
class Solution {
public:
    unordered_set <char> st = {'a', 'e', 'i', 'o','u'};
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int n = words.size(), q = queries.size();
        vector<int> prefix(n+1, 0), res(q, 0);
        for(int i = 0; i < n;i++){
            prefix[i+1] = prefix[i] + (st.count(words[i][0]) && st.count(words[i].back()));
        }
        for(int i = 0; i < q;i++)
            res[i] = prefix[queries[i][1]+1] - prefix[queries[i][0]];
        return res;
    }
};