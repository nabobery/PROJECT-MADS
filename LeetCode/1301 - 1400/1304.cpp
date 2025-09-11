// 1304. Find N Unique Integers Sum up to Zero

// Solution 1: Straightforward and greedy
// Time Complexity: O(n)
// Space Complexity: O(n)
class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> res(n);
        int l = 1 - n%2, p =0;
        for(int i = -n/2;i < 0;i++) res[p++] = i;
        for(int i = l; i <= n/2;i++) res[p++] = i;
        return res;
    }
};