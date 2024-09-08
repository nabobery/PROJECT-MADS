// 2022. Convert 1D Array Into 2D Array

// Solution 1: Straightforward Approach
// Time complexity: O(m*n)
// Space complexity: O(1)
class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        if(m*n != original.size()) return {};
        vector<vector<int>> res(m, vector<int>(n));
        for(int i = 0; i < original.size();i++)
            res[i/n][i%n] = original[i];
        return res;
    }
};