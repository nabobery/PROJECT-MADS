// 3477. Fruits Into Baskets II

// Solution 1: BruteForce using Used Boolean Array
// Time Complexity: O(n^2)
// Space Complexity: O(n)
class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int res = 0, n = fruits.size();
        vector<bool> used(n, false);

        for (int i = 0; i < n; i++) {
            bool placed = false;
            for (int j = 0; j < n; j++) {
                if (!used[j] && baskets[j] >= fruits[i]) {
                    used[j] = true;
                    placed = true;
                    break;
                }
            }
            if (!placed) res++;
        }

        return res;
    }
};