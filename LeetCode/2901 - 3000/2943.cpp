// 2943. Maximize Area of Square Hole in Grid

// Solution 1: Greedy + Sorting
// Time Complexity: O(n log n + m log m)
// Space Complexity: O(1)
class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        // sort and find max gap in horizontal and vertical bars
        auto getMaxGap = [](vector<int>& bars) {
            sort(bars.begin(), bars.end());
            int maxConsecutive = 1;
            int currentConsecutive = 1;
            for (size_t i = 1; i < bars.size(); ++i) {
                if (bars[i] == bars[i - 1] + 1) {
                    currentConsecutive++;
                } else {
                    currentConsecutive = 1;
                }
                maxConsecutive = max(maxConsecutive, currentConsecutive);
            }
            return maxConsecutive + 1;
        };

        // get max gaps
        int maxHGap = getMaxGap(hBars);
        int maxVGap = getMaxGap(vBars);
        // calculate max square area
        int side = min(maxHGap, maxVGap);
        return side * side;
    }
};