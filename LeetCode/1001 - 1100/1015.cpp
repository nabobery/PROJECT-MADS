// 1015. Smallest Integer Divisible by K


// Solution 1: Simulation + Math + Pigeonhole Principle
// Time Complexity: O(k)
// Space Complexity: O(1)
// as we know that a number say i can be written as (i/k)*k + i%k we need to take care of remainder as we increase the number of digits
/*Example : 3
 1 % 3 = 1  (0*3 + 1 % 3) = 1
 1*10 + 1 % 3 = 2 (3*3 + 2 % 3) = 2 = 11% 3
 2*10 + 1 % 3 = 0 (3*37 % 3) = 0 = 21%3
 */
class Solution {
public:
    int smallestRepunitDivByK(int k) {
        if(!(k%2) || !(k%5)) return -1;
        int remainder = 0;
        // at max we will have k different remainders from 0 to k-1
        // so if we don't find any number with 0 remainder in k iterations then we won't find it later as well 
        // hence we return -1
        for(int n = 1; n <= k; n++){
            remainder = (remainder*10 + 1)%k;
            if(remainder % k == 0){
                return n;
            }
        }
        return -1;
    }
};

