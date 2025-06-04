// 2894. Divisible and Non-divisible Sums Difference

// Simple and Straightforward Brute Force
// Time Complexity: O(n)
// Space Complexity: O(1)
class Solution {
public:
    int differenceOfSums(int n, int m) {
        int res = 0;
        for(int i = 1; i <= n;i++){
            if(i % m) res += i;
            else res -= i;
        }
        return res;
    }
};