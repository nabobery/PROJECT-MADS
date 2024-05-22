// 3075. Maximize Happiness of Selected Children

// Greedy Solution 1 using sorting
// Time Complexity: O(nlogn)
// Space Complexity: O(logn)
class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        sort(happiness.begin(), happiness.end());
        int n = happiness.size();
        long long res = 0;
        for(int i = n-1; k > 0 && i >= 0; i--,k--)
            res += max(0, happiness[i] - (n-i-1));
        return res;
    }
};