// 2165. Smallest Value of the Rearranged Number
// my naive solution
class Solution {
public:
    long long smallestNumber(long long num) {
        vector<char> digits;
        bool flag = false;
        long long temp;
        if(num > 0){
            temp = num;
        }
        else{
            temp = -num;
            flag = true;
        }
        while(temp){
            char tmp = temp%10 + '0';
            digits.push_back(tmp);
            temp /= 10;
        }
        long long result;
        sort(digits.begin(),digits.end());
        if(flag){
            result = 0;
            for(int i = digits.size() - 1;i >= 0;i--){
                result += (digits[i] - '0');
                if(i > 0){
                    result *= 10;
                }
            }
            result *= -1;
        }
        else{
            int i;
            for(i = 0; i < digits.size();i++){
                if(digits[i] != '0'){
                    break;
                }
            }
            int count = i;
            result = (digits[i] - '0');
            if(i < digits.size() - 1){
                result *= pow(10,count + 1);
                for(i = count + 1; i < digits.size();i++){
                    result += (digits[i] - '0');
                    if(i < digits.size() - 1){
                        result *= 10;
                    }
                }
            }
            else{
                result *= pow(10,count);
            }
        }
        return result;
    }
};

