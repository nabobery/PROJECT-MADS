// 837. New 21 Game

// Solution 1: Dynamic Programming and Math
// Time Complexity: O(n)
// Space Complexity: O(n)
class Solution {
public:
    double new21Game(int n, int k, int maxPts) {
        vector<double> dp(n + 1, 0);
        // if k is 0 (means whatever alice draws is greater than k [1, maxPts]) or n - k + 1 >= maxPts (if the difference between n and k is less than range (Maxpts - 1)), Alice will always have less than n points
        if (k == 0 || n - k + 1 >= maxPts) {
            return 1;
        }
        // base case
        dp[0] = 1;
        // sum of probabilities, initially it's 1 (probability of getting 0 points)
        // for probability of getting card x in [1, maxPts] in a turn is 1/maxPts (Independent and equal probs)
        double sum = 1, kFactor = 1.0/maxPts;
        // calculate dp[i] for i in [1, k)
        for (int i = 1; i < k; ++i) {
            // conditional probability
            dp[i] = sum * kFactor;
            // update sum for next iteration
            // if i is greater than or equal to maxPts, we need to subtract the probability that is no longer in the window
            // dp[i - maxPts] is the probability that is no longer in the window
            // sum is the total probability in the window
            sum += dp[i] - (i >= maxPts ? dp[i - maxPts] : 0);
        }
        // x E [k, k - 1 + m]
        // res = P(x <= n) = P(k <= x <= n)
        // The result is the sum of probabilities for all valid states - those that reach at least k points without exceeding n
        double res = 0;
        for (int i = k; i <= n; ++i) {
            res += sum * kFactor;
            if(i >= maxPts) sum -= dp[i - maxPts];
        }
        // The final result is the accumulated probability
        return res;
    }
};