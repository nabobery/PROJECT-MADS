// 2110. Number of Smooth Descent Periods of a Stock

// Solution 1: Monotonic Prefix Count Calculation
// Time Complexity: O(n)
// Space Complexity: O(1)
class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        long long res = 1;
        int n = prices.size(), prev = prices[0], curr = 1;
        for(int i = 1; i < n;i++){
            if(prev == prices[i]+1) curr++;
            else curr = 1;
            res += curr;
            prev = prices[i];
        }
        return res;
    }
};