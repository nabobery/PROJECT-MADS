// 812. Largest Triangle Area

// Solution 1: Brute Force and Straight Forward
// Time Complexity: O(n^3)
// Space Complexity: O(1)
class Solution {
public:
    // Area of traingle
    // (1/2){x1(y2 − y3) + x2(y3 − y1) + x3(y1 − y2)}
    double largestTriangleArea(vector<vector<int>>& points) {
        int n = points.size();
        double res = 0;
        for (int i = 0; i < n - 2; i++) {
            for (int j = i + 1; j < n - 1; j++) {
                for (int k = j + 1; k < n; k++) {
                    int x1 = points[i][0], y1 = points[i][1], x2 = points[j][0],
                        y2 = points[j][1], x3 = points[k][0], y3 = points[k][1];
                    int s = x1*(y2 - y3) + x2*(y3 - y1) + x3*(y1 - y2);
                    double curr = abs(s) / 2.0;
                    res = max(curr, res);
                }
            }
        }
        return res;
    }
};