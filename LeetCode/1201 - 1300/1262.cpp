// 1262. Greatest Sum Divisible by Three

// Solution 1: Using Math (Faster)
// Time Complexity: O(n)
// Space Complexity: O(1)
// The idea is to calculate the total sum and track the smallest one or two numbers
// that can be removed to make the sum divisible by 3.
class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        int sum = 0;
        int one1 = 10000, one2 = 10000; // Smallest two nums with remainder 1
        int two1 = 10000, two2 = 10000; // Smallest two nums with remainder 2
        
        for (int n : nums) {
            sum += n;
            if (n % 3 == 1) {
                if (n < one1) { one2 = one1; one1 = n; }
                else if (n < one2) { one2 = n; }
            } else if (n % 3 == 2) {
                if (n < two1) { two2 = two1; two1 = n; }
                else if (n < two2) { two2 = n; }
            }
        }
        
        if (sum % 3 == 0) return sum;
        if (sum % 3 == 1) return sum - min(one1, two1 + two2);
        return sum - min(two1, one1 + one2);
    }
};

// Solution 2: Using Dynamic Programming
// Time Complexity: O(3n) = O(n)
// Space Complexity: O(1)
class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        // dp[i] stores the max sum encountered so far with remainder i
        // Initialize with a very small number to represent "unreachable" states
        // dp[0] is 0 because a sum of 0 has remainder 0
        vector<int> dp = {0, INT_MIN, INT_MIN};

        for (int num : nums) {
            // Create a copy to calculate new states based on the current number
            vector<int> next_dp = dp;
            
            for (int i = 0; i < 3; ++i) {
                // If dp[i] is reachable
                if (dp[i] != INT_MIN) {
                    int current_sum = dp[i] + num;
                    int remainder = current_sum % 3;
                    
                    // Update the max sum for this specific remainder
                    next_dp[remainder] = max(next_dp[remainder], current_sum);
                }
            }
            // Update the main dp array for the next iteration
            dp = next_dp;
        }

        return dp[0];
    }
};