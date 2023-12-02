// 1611. Minimum One Bit Operations to Make Integers Zero

// Observations
// 1. The minimum number of operations to make an integer of the form 2^k to 0 is 2^k - 1
// 2. The minimum number of operations to make an integer of the form n = 2^k + x to 0 is 2^(k+1) - 1 - f(x)
// 3. f(x) = minimum number of operations to make x to 0

// Solution 1 - Using Bit Manipulation and Math
// Time Complexity = O(log^2n), 
// Space Complexity = O(logn)
class Solution {
public:
    string deciToBin(int n){
        string res = "";
        while(n){
            if(n%2) res += "1";
            else res += "0";
            n /= 2;
        }
        reverse(res.begin(), res.end());
        return res;
    }
    int minimumOneBitOperations(int n) {
        if(n < 2) return 0;
        string s = deciToBin(n);
        int res = 0, cnt = 0;
        for(int i = 0; i < s.size();i++){
            if(s[i] == '1'){
                if(cnt%2) res -= (pow(2, s.size()-i)-1);
                else res += (pow(2, s.size()-i)-1);
                cnt++;
            }
        }
        return res;
    }
};

// Solution 2 - Using Bit Manipulation and Recursion
// Time Complexity = O(log^2n),
// Space Complexity = O(logn)
class Solution {
public:
    int minimumOneBitOperations(int n) {
        if (n == 0) 
            return 0;
        int k = 0, curr = 1;
        while (curr * 2 <= n) {
            curr *= 2;
            k++;
        }
        return (1 << (k + 1)) - 1 - minimumOneBitOperations(n ^ curr);
    }
};

// Solution 3 - Using Bit Manipulation and Iteration
// Time Complexity = O(log^2n),
// Space Complexity = O(1)
class Solution {
public:
    int minimumOneBitOperations(int n) {
        // res is the result of the first k bits of n
        // k is the number of bits of n
        // mask is the mask of the current bit
        int res = 0, k = 0, mask = 1;
        while (mask <= n) {
            if ((n & mask) != 0) {
                res = (1 << (k + 1)) - 1 - res;
            }
            mask <<= 1;
            k++;
        }
        return res;
    }
};
