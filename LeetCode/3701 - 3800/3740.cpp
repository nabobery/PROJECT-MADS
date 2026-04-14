// 3740. Minimum Distance Between Three Equal Elements I

// Solution 1: Using Hash Map to Track Last Two Occurrences
// Time Complexity: O(n)
// Space Complexity: O(n)
class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        unordered_map<int, pair<int, int>> lastTwo;
        int res = INT_MAX;

        for (int i = 0; i < nums.size(); ++i) {
            int val = nums[i];
            if (lastTwo.count(val)) {
                auto& [idx1, idx2] = lastTwo[val];
                if (idx1 != -1) {
                    // (idx1, idx2, i) are the three occurrences of val
                    // The distance is (i - idx1) + (idx2 - idx1) = 2 * (i - idx1)
                    res = min(res, 2 * (i - idx1));
                }
                idx1 = idx2;
                idx2 = i;
            } else {
                lastTwo[val] = {-1, i};
            }
        }

        return res == INT_MAX ? -1 : res;
    }
};