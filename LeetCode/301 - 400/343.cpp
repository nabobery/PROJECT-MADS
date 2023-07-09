// 343. Integer Break


// O(n^2) time O(n) space DP solution
// dp[i] represents the maximum product of i when it is broken into at least 2 numbers
// i = j + k => k = i - j
// dp[i] = max(dp[i], (max(j,dp[j])) * (max(i - j, dp[i - j]))) for j = 1 to i-1
class Solution {
public:
    int integerBreak(int n) {
        vector<int> dp(n+1,0);
        dp[1] = 1;
        for(int i = 2; i <= n; i ++) {
            for(int j = 1; j < i; j ++) {
                dp[i] = max(dp[i], (max(j,dp[j])) * (max(i - j, dp[i - j])));
            }
        }
        return dp[n];
    }
};


// greedy O(n) time O(1) space solution
class Solution {
public:
    int integerBreak(int n) {
        int result = n-1, temp, counter;
        for(int k = 2; k <= n;k++){
            counter = n%k;
            temp = 1;
            while(counter--){
                temp *= (n/k + 1);
            }
            counter = k - n%k;
            while(counter--){
                temp *= (n/k);
            }
            result = max(result,temp);
        }
        return result;
    }
};

// O(logn) time O(1) space solution

// Based on the fact that 3 is the best number to break into 2 numbers (mathematical obeervation)
// we can use the greedy approach to break the number into 3s and 2s
// n = 3k + 2 => 3^k * 2
// n = 3k + 1 => 3^k-1  * 4
// n = 3k => 3^k
class Solution {
public:
    int integerBreak(int n) {
        if(n == 2) return 1;
        if(n == 3) return 2;
        int result = 1;
        while(n > 4){
            result *= 3;
            n -= 3;
        }
        result *= n;
        return result;
    }
};