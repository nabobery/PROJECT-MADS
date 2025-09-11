// 2749. Minimum Operations to Make the Integer Zero

// Solution 1: Greedy and Math
// Time Complexity: O(1)
// Space Complexity: O(1)
class Solution {
public:
    int makeTheIntegerZero(int num1, int num2) {
        if(num2 > num1) return -1;
        long long temp = num1;
        for(int i = 1; i <= 32;i++){
            temp -= num2;
            if(temp <= 0) break;
            // min number of powers of 2 required for that sum
            int setBits = __builtin_popcountll(temp);
            // max number of powers of 2 is temp (we can sum 1 temp times)
            if(i >= setBits && i <= temp) return i;
        }
        return -1;
    }
};