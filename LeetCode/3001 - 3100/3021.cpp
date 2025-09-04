// 3021. Alice and Bob Playing Flower Game

// Solution 1: Simple and Straightforward (Basic Math)
// Time Complexity: O(1)
// Space Complexity: O(1)
class Solution {
public:
    // Odd sum pairs: one odd+one even → OnEm+EmOn = 2*(n/2*m/2) = floor(n*m/2)
    long long flowerGame(int n, int m) {
        if(n == 1 && m == 1) return 0;
        return (1LL * n * m)/2;
    }
};

