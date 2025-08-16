// 904. Fruit Into Baskets


// Solution 1: Using Two Pointers Technique
// Time Complexity: O(n)    
// Space Complexity: O(1)
class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int b[2] = {-1, -1};
        int count[2] = {0, 0};
        int l = 0, r = 0, n = fruits.size();
        int res = 0;

        while (r < n) {
            int fruit = fruits[r];

            if (fruit == b[0]) {
                count[0]++;
            } else if (fruit == b[1]) {
                count[1]++;
            } else if (b[0] == -1) {
                b[0] = fruit;
                count[0] = 1;
            } else if (b[1] == -1) {
                b[1] = fruit;
                count[1] = 1;
            } else {
                while (count[0] > 0 && count[1] > 0) {
                    if (fruits[l] == b[0]) {
                        count[0]--;
                        if (count[0] == 0) {
                            b[0] = fruit;
                            count[0] = 0;
                        }
                    } else if (fruits[l] == b[1]) {
                        count[1]--;
                        if (count[1] == 0) {
                            b[1] = fruit;
                            count[1] = 0;
                        }
                    }
                    l++;
                }

                if (b[0] == fruit) count[0]++;
                else if (b[1] == fruit) count[1]++;
            }

            res = max(res, count[0] + count[1]);
            r++;
        }

        return res;
    }
};