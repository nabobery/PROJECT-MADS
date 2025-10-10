// 2300. Successful Pairs of Spells and Potions

// Solution 1: Using Sorting and Binary Search
// Time Complexity: O(m log m + n log m)
// Space Complexity: O(1)
class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions,
                                long long success) {
        int n = spells.size();
        vector<int> res(n);
        sort(potions.begin(), potions.end());
        for (int i = 0; i < n; i++) {
            long minPotion = (success + spells[i] - 1) / spells[i];
            auto it = lower_bound(potions.begin(), potions.end(), minPotion);
            if (it != potions.end())
                res[i] = potions.end() - it;
        }
        return res;
    }
};