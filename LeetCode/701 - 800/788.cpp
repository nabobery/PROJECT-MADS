// 788. Rotated Digits

// Solution 1: Straightforward
// Time Complexity: O(nlogn) (As log10(n) is the number of digits in n and n <= 10^4, log10(n) is a constant) ~ O(n)
// Space Complexity: O(1)
class Solution {
public:
    // A number is valid if it contains at least one of the digits 2, 5, 6, or 9 and does not contain 3, 4, or 7.
    bool valid(int num){
        bool changed = false;
        while(num){
            int digit = num%10;
            num /= 10;
            if(digit == 0 || digit == 1 || digit == 8) continue;
            else if(digit == 2 || digit == 5 || digit == 6 || digit == 9){
                changed = true;
                continue;
            }
            else return false;
        }
        return changed;
    }
    int rotatedDigits(int n) {
        int res = 0;
        for(int i = 1; i <= n;i++){
            if(valid(i)) res++;
        }
        return res;
    }
};