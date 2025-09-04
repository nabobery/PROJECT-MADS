// 3027. Find the Number of Ways to Place People II

// Solution 2: Using Sorting (Greedy Approach)
// Time Complexity: O(n^2 + nlogn) = O(n^2)
// Space Complexity: O(n)
class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        // 1. Sort points: ascending by x, then descending by y.
        sort(points.begin(), points.end(), [](const vector<int>& a, const vector<int>& b) {
            if (a[0] != b[0]) {
                return a[0] < b[0];
            }
            return a[1] > b[1];
        });

        int res = 0;
        int n = points.size();

        // 2. Iterate through each point as a potential upper-left point 'pi'.
        for (int i = 0; i < n; ++i) {
            // This will track the highest 'y' of a valid partner for the current 'pi'.
            int maxY = -1e9 - 7; // Initialize to a very small number.

            // 3. Iterate through subsequent points as potential lower-right partners 'pj'.
            for (int j = i + 1; j < n; ++j) {
                // Check if points[j] is below points[i] (it's already to the right due to sorting).
                // And check if its y-coordinate is higher than any previous valid partner.
                if (points[j][1] <= points[i][1] && points[j][1] > maxY) {
                    // This forms a valid pair because no other point previously considered
                    // as a partner for points[i] is inside the bounding box.
                    res++;
                    // Update maxY to the y-coordinate of this new, higher partner.
                    maxY = points[j][1];
                }
            }
        }
        return res;
    }
};