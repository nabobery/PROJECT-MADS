// 8. String to Integer (atoi)
// naive solution
class Solution {
public:
    int myAtoi(string s) {
        int result = 0,sign = 1,i = 0;
        while(s[i] == ' '){
            i++;
        }
        if(s[i] == '+' || s[i] == '-'){
            sign = 1 - 2*(s[i++] == '-');
        }
        while(s[i] >= '0' && s[i] <= '9'){
            if(result > INT_MAX/10 ||(result == INT_MAX/10 && s[i] - '0' > 7)){
                if(sign == 1){
                    return INT_MAX;
                }
                else{
                    return INT_MIN;
                }
            }
            result = result*10 + (s[i++] - '0');
        }
        return (sign*result);
    }
};

