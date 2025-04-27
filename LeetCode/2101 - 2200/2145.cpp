// 2145. Count the Hidden Sequences

// Solution 1: Using Prefix Sum
// Time Complexity: O(n)
// Space Complexity: O(1)
class Solution {
    public:
        int numberOfArrays(vector<int>& differences, int lower, int upper) {
            long prefix = 0, mi = INT_MAX, mx = INT_MIN;
            for(auto& diff: differences){
                prefix += diff;
                mi = min(prefix, mi);
                mx = max(prefix, mx);
            }
            long nl = max(lower - mi, long(lower)), nr = min(upper - mx, long(upper));
            return max(nr - nl + 1, 0L);
        }
};
