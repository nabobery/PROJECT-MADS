// 756. Pyramid Transition Matrix

// Solution 1: Using Recursion with Memoization
// Time Complexity: O(N * M^N) where N is the height of the pyramid and M is the number of allowed transitions
// Space Complexity: O(N^2) for the memoization set and recursion stack
class Solution {
public:
    unordered_set<string> memo;
    bool helper(vector<string>& pyramid, int i, int j,
                unordered_map<string, vector<char>>& bottomToTop) {
        if (i == 0)
            return true;

        if (j == pyramid[i].size() - 1) {
            if(memo.count(pyramid[i-1])) return false;
            bool result = helper(pyramid, i - 1, 0, bottomToTop);
            if (!result) memo.insert(pyramid[i-1]);
            return result;
        }

        string base = "";
        base += pyramid[i][j];
        base += pyramid[i][j + 1];

        if (bottomToTop.count(base)) {
            for (char possibility : bottomToTop[base]) {
                pyramid[i - 1][j] = possibility;
                if (helper(pyramid, i, j + 1, bottomToTop))
                    return true;
            }
        }

        return false;
    }
    bool pyramidTransition(string bottom, vector<string>& allowed) {
        memo.clear();
        unordered_map<string, vector<char>> bottomToTop;
        int n = bottom.size();
        for (auto& str : allowed)
            bottomToTop[str.substr(0, 2)].push_back(str[2]);
        vector<string> pyramid(n);
        for (int i = 0; i < n - 1; i++)
            pyramid[i] = string(i+1, '?');
        pyramid[n - 1] = bottom;
        return helper(pyramid, n - 1, 0, bottomToTop);
    }
};