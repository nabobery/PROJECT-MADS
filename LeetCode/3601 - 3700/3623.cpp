// 3623. Count Number of Trapezoids I

// Solution 1: Using combinatorial counting and modular arithmetic
// Time Complexity: O(N)
// Space Complexity: O(N)
class Solution {
public:
    const int mod = 1e9 + 7;
    int countTrapezoids(vector<vector<int>>& points) {
        // Count frequency of points by their y-coordinates
        // We need to get horizontal pairs of points so one condition is that they should have same y-coordinate
        unordered_map<int,int> yToCnt;
        for(auto& point: points){
            yToCnt[point[1]]++;
        }
        
        // Now for each unique y-coordinate, calculate the number of ways to choose 2 points (horizontal pairs)
        // Then use these counts to calculate the number of trapezoids
        
        // sumOfSquares will hold the sum of squares of counts of horizontal pairs
        // sum will hold the total count of horizontal pairs
        // The result is derived from the formula: (sum^2 - sumOfSquares) / 2
        long long sumOfSquares = 0, sum = 0;
        
        for(auto& it : yToCnt){
            long long count = it.second;
            long long sides = (count * (count - 1)) / 2; 
            sides %= mod;   
            sumOfSquares = (sumOfSquares + (sides * sides) % mod) % mod;
            sum = (sum + sides) % mod;
        }
        long long res = ((sum * sum % mod) - sumOfSquares + mod) % mod;

        // Divide by 2 using modular inverse => res / 2 mod = res * modinv(2) % mod
        // Inverse of 2 for (1e9+7) is 500000004
        long long inv2 = 500000004;
        res = (res * inv2) % mod;
        
        return res;
    }
};