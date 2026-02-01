// 3453. Separate Squares I

// Solution 1: Using Binary Search
// Time Complexity: O(n log n)
// Space Complexity: O(1)
class Solution {
public:
    double helper(double y, vector<vector<int>>& squares){
        double areaBelowY = 0;
        for(auto& square: squares){
            double l = square[2];
            if(square[1] >= y) continue;
            if(square[2] + square[1] < y) areaBelowY += (l*l);
            else areaBelowY += (y - square[1]) * l;
        }
        return areaBelowY;
    }
    double separateSquares(vector<vector<int>>& squares) {
        double totalArea = 0, low = INT_MAX, high = 0;
        for(auto& square: squares){
            double l = square[2], y = square[1];
            totalArea += (l * l);
            low = min(low, y);
            high = max(high, y + square[2]);
        }
        while(high - low > 1e-5){
            double mid = (low + high)/2;
            if(helper(mid, squares) >= totalArea/2) high = mid;
            else low = mid;
        }
        return low;
    }
};