// 3000. Maximum Area of Longest Diagonal Rectangle

// Solution 1: Simple and StraightForward
// Time Complexity: O(n)
// Space Complexity: O(1)
class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int res = 0;
        double mxDiagonal = 0;
        for(auto& dimension: dimensions){
            double curr = sqrt(pow(dimension[0], 2) + pow(dimension[1], 2));
            if(curr > mxDiagonal) res = dimension[0] * dimension[1];
            else if(curr == mxDiagonal) res = max(res, dimension[0] * dimension[1]);
            mxDiagonal = max(curr, mxDiagonal);
        }
        return res;
    }
};