// 838. Push Dominoes


// Solution 1: Two-Pointer Approach
// Time Complexity: O(n)
// Space Complexity: O(n)
// L L (deosn't matter) (just go left)
// L R (just go left and right)
// R L (nullification happens, need to meet in the middle)
// R R (just go right)
class Solution {
    public:
        string pushDominoes(string dominoes) {
            int n = dominoes.size();
            string res = dominoes;
            int prev = -1;
    
            for (int i = 0; i < n; i++) {
                if (prev == -1) {
                    if (dominoes[i] == 'L') {
                        for (int j = 0; j < i; j++)
                            res[j] = 'L';
                    }
                } else {
                    if (dominoes[prev] == 'L' && dominoes[i] == 'L') {
                        for (int j = prev + 1; j < i; j++)
                            res[j] = 'L';
                    } else if (dominoes[prev] == 'R' && dominoes[i] == 'R') {
                        for (int j = prev + 1; j < i; j++)
                            res[j] = 'R';
                    } else if (dominoes[prev] == 'R' && dominoes[i] == 'L') {
                        int left = prev + 1;
                        int right = i - 1;
                        while (left < right) {
                            res[left++] = 'R';
                            res[right--] = 'L';
                        }
                    }
                }
                if (dominoes[i] != '.')
                    prev = i;
            }
    
            if (prev != -1 && dominoes[prev] == 'R') {
                for (int i = prev + 1; i < n; i++)
                    res[i] = 'R';
            }
    
            return res;
        }
};
