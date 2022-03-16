/* Name : Reverse Integer
Example 1:
Input: x = 123
Output: 321
Example 2:
Input: x = -123
Output: -321
Example 3:
Input: x = 120
Output: 21
Example 4:
Input: x = 0
Output: 0
Constraints:
-2^31 <= x <= 2^31 - 1
*/
// Trial
class Solution {
public:
    int reverse(int x) {
        long int rev_num = 0;
        signed long int num;
        if(x > 0)
            num = x;
        else 
            num = -x;
        
        while (num > 0){
            rev_num = rev_num*10 + num % 10;
            num = num / 10;
        }
        if (x < 0 && rev_num <= 2147483648)
            rev_num = -rev_num;
        if (x < 0 && rev_num > 2147483648) 
            rev_num = 0;
        if (x > 0 && rev_num > 2147483647)
            rev_num = 0;
        return rev_num;
    }
};

// Correct Solution :
class Solution {
public:
    int reverse(int x) {
        int rev_num = 0;        
        while (x != 0){
            int num = x % 10;
            x = x / 10;
            if (rev_num > INT_MAX/10 || (rev_num == INT_MAX / 10 && num > 7)) return 0;
            if (rev_num < INT_MIN/10 || (rev_num == INT_MIN / 10 && num < -8)) return 0;
            rev_num = rev_num*10 + num;
        }
        return rev_num;
    }
};