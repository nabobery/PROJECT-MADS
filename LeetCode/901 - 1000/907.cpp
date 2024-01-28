// 907. Sum of Subarray Minimums

// Solution 1 using Monotonic Stack to find subarrays where arr[i] is the minimum element and sum them up
// Time Complexity: O(N)
// Space Complexity: O(N)

class Solution {
public:
    const int MOD = 1e9 + 7;
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        // left[i] is the index of the first element to the left of arr[i] that is smaller than arr[i]
        // right[i] is the index of the first element to the right of arr[i] that is smaller than arr[i]
        vector<int> left(n, -1), right(n, n);
        // a monoincreasing stack of indices of elements in arr that are smaller than the top element
        stack<int> stk;
        // fill left and right
        for (int i = 0; i < n; ++i) {
            while (!stk.empty() && arr[stk.top()] >= arr[i]) {
                stk.pop();
            }
            if (!stk.empty()) {
                left[i] = stk.top();
            }
            stk.push(i);
        }
        stk.clear();
        for (int i = n - 1; i >= 0; --i) {
            while (!stk.empty() && arr[stk.top()] > arr[i]) {
                stk.pop();
            }
            if (!stk.empty()) {
                right[i] = stk.top();
            }
            stk.push(i);
        }
        // sum up the subarrays where arr[i] is the minimum element
        long long res = 0;
        // given an array of length n, containing arr[0], arr[1], ..., arr[k], arr[k+1], ..., arr[n - 1]
        // the number of subarrays where arr[k] is present is k*(n - k+1)
        // the number of subarrays where arr[k] is the minimum element is (k - left[k])*(right[k] - k)
        for (int i = 0; i < n; ++i) {
            res += (long long)(i - left[i]) * (right[i] - i) * arr[i] % MOD;
            res %= MOD;
        }
        return res;
    }
};

// Solution 2 using Monotonic Stack One pass
// Time Complexity: O(N)
// Space Complexity: O(N)
class Solution {
public:
    const int MOD = 1e9 + 7;
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size(), res = 0;
        // stack to store indices of elements in arr that are smaller than the top element
        stack<int> stk;
        // dp[i] is the sum of subarrays ending at arr[i] 
        vector<int> dp(n + 1, 0);
        // dp[0] = 0
        // dp[i] = dp[j+1] + (i - j) * arr[i] where j is the index of the first element to the left of arr[i] that is smaller than arr[i]
        stk.push(-1);
        for (int i = 0; i < n; ++i) {
            while (stk.top() != -1 && arr[stk.top()] >= arr[i]) {
                stk.pop();
            }
            dp[i + 1] = (dp[stk.top() + 1] + (i - stk.top()) * arr[i]) % MOD;
            stk.push(i);
            res += dp[i+1];
            res %= MOD;
        }
        return res;
    }
};