// 1266. Minimum Time Visiting All Points

// Solution 1 Simple Math
// Time complexity: O(n)
// Space complexity: O(1)
class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int res = 0;
        for(int i = 1; i < points.size();i++){
            res += max(abs(points[i][0] - points[i-1][0]), abs(points[i][1] - points[i-1][1]));
        }
        return res;
    }
};
