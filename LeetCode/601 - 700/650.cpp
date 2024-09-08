// 650. 2 Keys Keyboard

// Solution 1 using Math
// Get all prime factors of n and then use them as base of copy and then use paste to get n A's
// Time complexity: O(sqrt(n))
// Space complexity: O(1)
class Solution {
public:
    int minSteps(int n) {
        if(n == 1) return 0;
        int res = 0;
        // get all copy and paste operations to reduce the even part to odd part
        while(n % 2 == 0){
            n /= 2;
            res += 2;
        }
        // go thorugh all odd prime factors of n and add them to res we use 1 A and use i paste operations to get i A's
        for(int i = 3; i <= sqrt(n);i += 2){
            while(n%i == 0){
                n /= i;
                res += i;
            }
        }
        // if n is prime then n is the only factor and we need n operations to get n A's
        if(n > 2) res += n;
        return res;
    }
};

// Solution 2 using DP
// Time complexity: O(n*sqrt(n))
// Space complexity: O(n)
class Solution {
public:
    int minSteps(int n) {
        vector<int> dp(n+1, INT_MAX);
        dp[1] = 0;
        for(int i = 2; i <= n; i++){
            for(int j = 1; j <= sqrt(i); j++){
                if(i % j == 0){
                    dp[i] = min(dp[i], dp[j] + i/j);
                    dp[i] = min(dp[i], dp[i/j] + j);
                }
            }
        }
        return dp[n];
    }
};