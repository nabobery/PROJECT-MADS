// 1014. Best Sightseeing Pair

// O(n) time and O(n) space solution
class Solution {
public:
    // We need to find the maximum value of A[i] + A[j] + i - j for all i < j and can be written as A[i] + i + A[j] - j
    // We fix the value of i and find the maximum value of A[j] - j for all j > i
    // We can do this by storing the maximum value of A[j] - j for all j > i in a dp array  where dp[i] = max(A[j] - j) for all j > i
    int maxScoreSightseeingPair(vector<int>& values) {
        int n = values.size(), result = -1e5;
        vector<int> dp(n);
        dp[n-1] = values[n-1] -n + 1;
        for(int i = n-2; i >= 0;i--){
            dp[i] =  max(dp[i+1], values[i+1] - i-1);
            result = max(result, values[i] + i + dp[i]);
        }
        return result;
    }
};

// O(n) time, O(1) space solution
class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int n = values.size(), result = -1e5;
        int maxsecond = values[n-1] -n + 1;
        for(int i = n-2; i >= 0;i--){
            maxsecond =  max(maxsecond, values[i+1] - i-1);
            result = max(result, values[i] + i + maxsecond);
        }
        return result;
    }
};