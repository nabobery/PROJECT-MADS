// 3047. Find the Largest Area of Square Inside Two Rectangles

// Solution 1: Go through all rectangle pairs, calcuate instersction and check max square side
// Time Complexity: O(n^2)
// Space Complexity: O(1)
class Solution {
public:
    long long largestSquareArea(vector<vector<int>>& bottomLeft, vector<vector<int>>& topRight) {
        long long maxArea = 0;
        int n = bottomLeft.size();

        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                // Calculate intersection
                // get the bottom-left and top-right coordinates of the intersection rectangle
                int x1 = max(bottomLeft[i][0], bottomLeft[j][0]);
                int y1 = max(bottomLeft[i][1], bottomLeft[j][1]);
                int x2 = min(topRight[i][0], topRight[j][0]);
                int y2 = min(topRight[i][1], topRight[j][1]);
                
                // Check if there is an intersection and calculate the largest square area
                if (x1 < x2 && y1 < y2) {
                    int xGap = x2 - x1;
                    int yGap = y2 - y1;
                    long long side = min(xGap, yGap);
                    maxArea = max(maxArea, side * side);
                }
            }
        }

        return maxArea;
    }
};

// Solution 2: Using Sorting and early stopping
// Time Complexity: O(n^2) (with early stopping)
// Space Complexity: O(n)
class Solution {
public:
    long long largestSquareArea(vector<vector<int>>& bottomLeft,
                                vector<vector<int>>& topRight) {
        int n = bottomLeft.size();
        vector<int> indices(n);
        for (int i = 0; i < n; ++i)
            indices[i] = i;
        // Sort rectangles by their bottom-left x-coordinate
        sort(indices.begin(), indices.end(),
             [&](int a, int b) { return bottomLeft[a][0] < bottomLeft[b][0]; });
        long long maxSide = 0;
        for (int i = 0; i < n; ++i) {
            int idx1 = indices[i];
            for (int j = i + 1; j < n; ++j) {
                int idx2 = indices[j];
                // Early stopping if no intersection is possible in x-axis
                int x1 = max(bottomLeft[idx1][0], bottomLeft[idx2][0]);
                int x2 = min(topRight[idx1][0], topRight[idx2][0]);
                if (x2 <= x1)
                    break;
                int y1 = max(bottomLeft[idx1][1], bottomLeft[idx2][1]);
                int y2 = min(topRight[idx1][1], topRight[idx2][1]);
                // Check for intersection in y-axis and calculate max square side
                if (y1 < y2) {
                    long long side = min(x2 - x1, y2 - y1);
                    if (side > maxSide)
                        maxSide = side;
                }
            }
        }
        return maxSide * maxSide;
    }
};