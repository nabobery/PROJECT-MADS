// 878. Nth Magical Number
// So what we want to find is Nth integer that is in the set of all numbers divisible by either a or b
/* We know that number of numbers divisible by a number a from 1 to K can be given as floor(K/a)
We know that number of numbers divisible by a number b from 1 to K can be given as floor(K/b)
We know that number of numbers divisible by both number a and b from 1 to K can be given as floor(K/lcm(a,b))
Therefore our required number result can be given as 
    N = result/a + result/b - result/lcm(a,b);
*/
class Solution {
public:
    long long int mod = 1e9 + 7;
    long long int gcd(long long int a, long long int b){
        if(b == 0){
            return a;
        }
        else{
            return gcd(b,a%b);
        }
    }
    long long int lcm(long long int a, long long int b){
        return((a*b)/gcd(a,b));
    }
    int nthMagicalNumber(int n, int a, int b) {
        long long int LCM = lcm(a,b);
        long long int low, mid,high, target;
        low = 1;
        high = 1e17;
        while(low < high){
            mid = (low + high)/2;
            target = (mid/a) + (mid/b) - (mid/LCM);
            if(target < n){
                low = mid + 1;
            }
            else{
                high = mid;
            }
        }
        return high%mod; // return low%mid also works because at mid (low = high)
    }
};