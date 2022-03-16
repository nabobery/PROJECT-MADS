// 415. Add Strings
// my naive solution
class Solution {
public:
    string addStrings(string num1, string num2) {
        int s1 = num1.size(), s2 = num2.size();
        if(s1 > s2){
            for(int i = s2; i < s1;i++){
                num2 = '0' + num2;
            }
        }
        else if(s2 > s1){
            for(int i = s1; i < s2;i++){
                num1 = '0' + num1;
            }
        }
        int carry = 0;
        for(int i = max(s1,s2) - 1; i > -1;i--){
            int temp = (num1[i] - '0') + (num2[i] - '0');
            temp += carry;
            char digit = (temp%10) + '0';
            carry = temp/10;
            num1[i] = digit;
        }
        if(carry == 1) num1 = '1' + num1;
        return num1;
    }
};

// without adding zeroes and reversing the string
class Solution {
public:
    string addStrings(string num1, string num2) {
        string result = "";
        int i1 = num1.size() - 1, i2 = num2.size() - 1, carry = 0;
        while (i1 >= 0 || i2 >= 0 || carry > 0) {
            if (i1 >= 0) {
                carry += num1[i1] - '0';
                i1 -= 1;
            }
            if (i2 >= 0) {
                carry += num2[i2] - '0';
                i2 -= 1;
            }
            result += char(carry % 10 + '0');
            carry /= 10;
        }
        reverse(result.begin(),result.end());
        return result;
    }
};
