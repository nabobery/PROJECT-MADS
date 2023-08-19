// 326. Power of Three

// Solution 1 in O(log3(n)) time
class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n <= 0) return false;
        bool flag = true;
        while(n != 1){
            if(n % 3 != 0){
                flag = false;
                break;
            }
            n /= 3;
        }
        return flag;
    }
};

// Solution 2 in O(1) time (We greedily choose the highest power of 3 that can be fit in int type)
class Solution {
public:
    bool isPowerOfThree(int n) {
        return n > 0 && 1162261467 % n == 0;
    }
};