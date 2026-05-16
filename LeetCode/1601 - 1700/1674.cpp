// 1674. Minimum Moves to Make Array Complementary

// Solution 1: Prefix Sum and Range Update
// Time Complexity: O(n)
// Space Complexity: O(n)
class Solution {
public:
    int minMoves(vector<int>& nums, int limit) {
        int n = nums.size(), res = 2*n;
        // diff[i] means the number of moves needed to make all pairs sum to i
        vector<int> diff(2 * limit + 2, 0);
        for (int i = 0; i < n / 2; ++i) {
            // For each pair (a, b), we can make them sum to any value in [2, 2*limit] by changing at most 2 elements.
            int a = nums[i], b = nums[n - 1 - i];
            // If we want to make the pair sum to a value in [2, 2*limit], we need at most 2 moves.
            diff[2] += 2;
            diff[2 * limit + 1] -= 2;
            // If we want to make the pair sum to a value in [min(a, b) + 1, max(a, b) + limit], we need at most 1 move.
            int left1 = min(a, b) + 1, right1 = max(a, b) + limit;
            diff[left1] -= 1;
            diff[right1 + 1] += 1;
            // If we want to make the pair sum to a value in [a + b, a + b], we need 0 moves.
            int sum0 = a + b;
            diff[sum0] -= 1;
            diff[sum0 + 1] += 1;
        }
        // Calculate the prefix sum of diff to get the number of moves needed for each possible sum.
        int currMoves = 0;
        for (int i = 2; i <= 2 * limit; ++i) {
            currMoves += diff[i];
            // Update the result with the minimum moves needed to make all pairs sum to i.
            res = min(res, currMoves);
        }
        // Return the minimum moves needed to make all pairs complementary.
        return res;
    }
};