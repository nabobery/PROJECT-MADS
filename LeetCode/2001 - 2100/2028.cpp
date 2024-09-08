// 2028. Find Missing Observations

// Solution 1 using Math Observation and greedy approach
// Time complexity: O(n)
// Space complexity: O(1)
class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int s = 0, x, m = rolls.size();
        for(int roll : rolls) s += roll;
        x = (n+m)*mean - s;
        if(x < n || x/n > 6 || (x % n && x/n + 1 > 6)) return {};
        vector<int> res(n);
        int rem = x % n;
        for(int i = 0; i < rem;i++) res[i] = x/n + 1;
        for(int i = rem; i < n;i++) res[i] = x/n;
        return res;
    }
};