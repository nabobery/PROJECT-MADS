// 3403. Find the Lexicographically Largest String From the Box I


// Solution 1: Greedy Approach using Sliding Window
// Time Complexity: O(n)
// Space Complexity: O(n)
class Solution {
public:
    string answerString(string word, int numFriends) {
        if(numFriends == 1) return word;
        int n = word.size(), mx = n - numFriends+1;
        vector<vector<int>> maxStart(26);
        int mxStart = 0;
        string res;
        for(int i =0; i < n;i++){
            int curr = word[i] - 'a';
            maxStart[curr].push_back(i);
            mxStart = max(mxStart, curr);
        }
        for(int ind: maxStart[mxStart])
            res = max(res, word.substr(ind, min(n -ind +1 ,mx)));
        return res;
    }
};