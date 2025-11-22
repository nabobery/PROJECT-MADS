// 757. Set Intersection Size At Least Two

// Solution 1: Greedy Approach using Sorting
// Time Complexity: O(n log n) due to sorting
// Space Complexity: O(1)
class Solution {
public:
    int intersectionSizeTwo(vector<vector<int>>& intervals) {
        // 1. Sort: Ascending End time so that we can process intervals in the right order, (to maximize overlap)
        // and Descending Start time for intervals with the same end time. (To Handle contained/sub intervals)
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] == b[1] ? a[0] > b[0] : a[1] < b[1];
        });

        // p1 is the second largest chosen point, p2 is the largest
        int p1 = -1, p2 = -1;
        int res = 0;

        for (const auto& iv : intervals) {
            int start = iv[0];
            int end = iv[1];

            // Case 1: Start is greater than our largest point (No Overlap)
            // We need 2 new points. We pick the very end of the current interval.
            if (start > p2) {
                res += 2;
                p2 = end;
                p1 = end - 1;
            }
            // Case 2: Start is greater than second largest, but <= largest (Partial Overlap)
            // We have 1 valid point (p2). We need 1 more.
            // The old p2 becomes the new p1, and we add 'end' as new p2.
            else if (start > p1) {
                res++;
                p1 = p2;
                p2 = end;
            }
            // Case 3: Start <= p1 (Full Overlap)
            // Both p1 and p2 are inside [start, end]. Do nothing.
        }
        return res;
    }
};

