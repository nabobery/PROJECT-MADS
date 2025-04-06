// 2818. Apply Operations to Maximize Score

// Solution 1: Using Sieve of Eratosthenes to find prime numbers, Monotonic stack, Sorting and Fast exponentiation
// The idea is to find the prime factors of each number in the array and count the number of distinct prime factors for each number.
// Then, we can use a monotonic stack to find the left and right boundaries for each number based on its prime score.
// After that, we can sort the numbers based on their values and use a greedy approach to select the numbers with the highest values and prime scores with the least index
// Finally, we can calculate the maximum score by multiplying the selected numbers raised to the power of their respective ranges.
// Time Complexity: O(nlogn), 
// Space Complexity: O(n)
class Solution {
    public:
        int mod = 1e9 + 7;
        int primeScore(int n) {
            if (n <= 2)
                return n - 1;
            unordered_set<int> s;
            for (int i = 2; i * i <= n; i++) {
                while (n % i == 0) {
                    s.insert(i);
                    n /= i;
                }
            }
            if (n > 2)
                s.insert(n);
            return s.size();
        }
        long power(long base, long exp, long modulus) {
            if (modulus == 1)
                return 0;
            long result = 1;
            base %= modulus;
            while (exp > 0) {
                if (exp & 1)
                    result = (result * base) % modulus;
                base = (base * base) % modulus;
                exp >>= 1;
            }
            return result;
        }
        int maximumScore(vector<int>& nums, int k) {
            int n = nums.size();
            long res = 1;
            // Calculate the prime score for each number in nums
            vector<int> scores(n, 0);
            for (int i = 0; i < n; i++)
                scores[i] = primeScore(nums[i]);
            // Create a monotonic stack to find the left and right boundaries for each number based on its prime score (find the max prime score for each number left and right of it)
            // The left boundary is the last index where the score is less than the current score    
            vector<int> left(n, -1), right(n, n);
            vector<long> ranges(n, 0);
            {
                stack<int> stk;
                for (int i = 0; i < n; i++) {
                    while (!stk.empty() && scores[stk.top()] < scores[i])
                        stk.pop();
                    left[i] = stk.empty() ? -1 : stk.top();
                    stk.push(i);
                }
            }
            // The right boundary is the first index where the score is less than the current score
            {
                stack<int> stk;
                for (int i = n - 1; i >= 0; i--) {
                    while (!stk.empty() && scores[stk.top()] <= scores[i])
                        stk.pop();
                    right[i] = stk.empty() ? n : stk.top();
                    stk.push(i);
                }
            }
            // Calculate the ranges for each number based on its left and right boundaries where it is the max prime score
            for (int i = 0; i < n; i++) {
                ranges[i] = (long)(i - left[i]) * (right[i] - i);
            }
            // sort the numbers based on their values and indices
            // The idea is to sort the numbers in descending order and then select the top k numbers with the highest values and prime scores with the least index
            vector<int> idx(n);
            iota(idx.begin(), idx.end(), 0);
            sort(idx.begin(), idx.end(), [&](int a, int b) {
                if (nums[a] == nums[b])
                    return a < b;
                return nums[a] > nums[b];
            });
            // use fast exponentiation to calculate the maximum score
            for (int i = 0; i < n && k > 0; i++) {
                long use = min(ranges[idx[i]], (long)k);
                res = (res * power(nums[idx[i]], use, mod)) % mod;
                k -= use;
            }
            return res % mod;
        }
    };
    