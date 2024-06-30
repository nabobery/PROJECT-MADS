// 633. Sum of Square Numbers

// Solution 1 by bruteforcing and checking for all possible combinations that can lead to sum of 2 squares equal to c
// Time complexity: O(sqrt(c))
// Space complexity: O(1)
class Solution {
public:
    bool judgeSquareSum(int c) {
        if(c == 0) return true;
        int l = sqrt(c), n;
        for(int i = 1; i <= l;i++){
            n = c - pow(i, 2);
            if(ceil((double)sqrt(n)) == floor((double)sqrt(n))) return true;
        }
        return false;
    }
};

// Solution 2 using two pointers
// Time complexity: O(sqrt(c))
// Space complexity: O(1)
class Solution {
public:
    bool judgeSquareSum(int c) {
        long long l = 0, r = sqrt(c);
        while(l <= r){
            long long sum = l * l + r * r;
            if(sum == c) return true;
            else if(sum < c) l++;
            else r--;
        }
        return false;
    }
};