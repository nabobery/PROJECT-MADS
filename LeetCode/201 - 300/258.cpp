// 258. Add Digits
// my naive loop solution
class Solution {
public:
    int addDigits(int num) {
        int temp = num, result = num, sum;
        while(result > 9){
            sum = 0;
            while(temp){
                sum += temp % 10;
                temp /= 10;
            }
            result = sum;
            temp = sum;
        }
        return result;
    }
};

// naive O(1) solution
class Solution {
public:
    int addDigits(int num) {
        if(num < 10) return num;
        if(num % 9) return (num%9);
        return 9;
    }
};

// one liner solution
class Solution {
public:
    int addDigits(int num) {
        return num == 0 ? 0 : 1 + (num - 1) % 9;
    }
};
