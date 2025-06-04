// 2929. Distribute Candies Among Children II

// Solution 1: Using Math and Combinatorics
// Time Complexity: O(1)
// Space Complexity: O(1)
class Solution {
public:
    // constraints x1 + x2 + x3 = nl
    // 0 <= x1 <= limit and 0 <= x2 <= limit and 0 <= x3 <= limit
    long long distributeCandies(int n, int limit) {
        long long nl = n, Ll = limit;
        if(nl > 3*limit) return 0;
        else if(nl <= limit)
            return (nl + 2LL) * (nl + 1LL) / 2;
        else if(nl <= 2*limit)
            return (-2LL * nl * nl + 6LL * Ll * nl - 3LL * Ll * Ll + 3LL * Ll + 2LL) / 2;
        return (nl * nl - (6LL * Ll + 3LL) * nl + (9LL * Ll * Ll + 9LL * Ll + 2LL)) / 2;
    }
};