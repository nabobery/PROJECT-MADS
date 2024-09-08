// 264. Ugly Number II

// Solution 1 using set
// Time complexity: O(nlogn)
// Space complexity: O(n)
class Solution {
public:
    int nthUglyNumber(int n) {
        set<long long> s;
        s.insert(1);
        long long result = 1;
        for(int i = 0;i < n;i++){
            result = *s.begin();
            s.erase(result);
            s.insert(result*2);
            s.insert(result*3);
            s.insert(result*5);
        }
        return result;
    }
};

// Solution 2 using dynamic programming
// Time complexity: O(n)
// Space complexity: O(n)
class Solution {
public:
    int nthUglyNumber(int n) {
        if(n == 1) return 1;
        // array to store ugly numbers
        int dp[n];
        // 1 is the first ugly number
        dp[0] = 1;
        // p2, p3, p5 are the pointers to the ugly numbers that are multiplied by 2, 3, 5 respectively
        int p2 = 0, p3 = 0, p5 = 0;
        for(int i = 1;i < n;i++){
            // dp[i] is the minimum of dp[p2]*2, dp[p3]*3, dp[p5]*5
            dp[i] = min(dp[p2]*2, min(dp[p3]*3, dp[p5]*5));
            // move the pointer if the ugly number is multiplied by 2, 3, 5 respectively
            if(dp[i] == dp[p2]*2) p2++;
            if(dp[i] == dp[p3]*3) p3++;
            if(dp[i] == dp[p5]*5) p5++;
        }
        return dp[n-1];
    }
};