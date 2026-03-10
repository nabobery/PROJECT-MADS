// 1536. Minimum Swaps to Arrange a Binary Grid

// Solution 1: Greedy by counting the number of trailing zeros in each row
// Time complexity: O(n^2)
// Space complexity: O(n)
class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        int n = grid.size(), res = 0;
        vector<int> trailingZeroes(n);
        for(int i = 0; i < n;i++){
            int count = 0;
            for(int j = n-1; j >= 0; j--){
                if(grid[i][j] == 0) count++;
                else break;
            }
            trailingZeroes[i] = count;
        }
        for(int i = 0; i < n;i++){
            int minZerosRequired = n-1-i, foundIdx = -1;
            for(int j = i; j < n;j++){
                if(trailingZeroes[j] >= minZerosRequired){
                    foundIdx = j;
                    break;
                }
            }
            if(foundIdx == -1) return -1;
            for(int j = foundIdx; j > i;j--){
                swap(trailingZeroes[j], trailingZeroes[j-1]);
                res++;
            }
        }
        return res;
    }
};