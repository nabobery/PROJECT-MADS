// 3783. Mirror Distance of an Integer

// Solution 1: Simple and Straightforward
// Time Complexity: O(log(n))
// Space Complexity: O(1)
class Solution {
public:
    int mirrorDistance(int n) {
        int revN = reverseInt(n);
        return abs(revN - n);
    }
private:
    int reverseInt(int n) {
        if (n == 0)
            return 0;
        while (n > 0 && n % 10 == 0) {
            n /= 10;
        }
        long long rev = 0;
        while (n > 0) {
            rev = rev * 10 + (n % 10);
            n /= 10;
        }
        return (int)rev;
    }
};