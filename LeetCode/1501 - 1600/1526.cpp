// 1526. Minimum Number of Increments on Subarrays to Form a Target Array

// Solution 1: Greedy Approach using Monotonic Stack
// Time Complexity: O(n)
// Space Complexity: O(1)
// The idea is to count the increments needed at each position based on the difference from the previous position.
// We only need to consider positive differences since negative differences do not require any operations.
// Based on this observation, the number of operations only increase when the array is rising
// the number of operations for a given sub array is equal to the largest value in that subarray.
class Solution {
public:
    int minNumberOperations(vector<int>& target) {
        int n = target.size(), res = target[0];
        for (int i = 1; i < n; i++)
            res += max(target[i] - target[i - 1], 0);
        return res;
    }
};