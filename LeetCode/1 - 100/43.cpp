// 43. Multiply Strings
// O(n1*n2) Time and O(n1 + n2) space solution
class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") {
            return "0";
        }
        int n1 = num1.size();
        int n2 = num2.size();
        vector<int> num(n1 + n2,0);
        int i_n1 = 0, i_n2 = 0;
        for(int i = n1 -1; i >= 0;i--){
            int d1 = num1[i] - '0';
            int carry = 0;
            i_n2 = 0;
            for(int j = n2 -1; j >= 0;j--){
                int d2 = num2[j] - '0';
                int sum = d1*d2 + num[i_n1 + i_n2] + carry;
                num[i_n1 + i_n2] = sum % 10;
                carry = sum/10;
                i_n2++;
            }
            if(carry > 0)
                num[i_n1 + i_n2] += carry;
            i_n1++;
        }
        int i = num.size() - 1;
        while(i >= 0 && num[i] == 0)
            i--;
        string result = "";
        while(i >= 0){
            result += to_string(num[i--]);
        }
        return result;
    }
};

// more optimised solution
class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") {
            return "0";
        }
        int n1 = num1.size();
        int n2 = num2.size();
        string result(n1 + n2,'0');
        int i_n1 = 0, i_n2 = 0;
        for(int i = n1 -1; i >= 0;i--){
            int d1 = num1[i] - '0';
            int carry = 0;
            i_n2 = 0;
            for(int j = n2 -1; j >= 0;j--){
                int d2 = num2[j] - '0';
                int sum = d1*d2 + (result[i_n1 + i_n2] - '0') + carry;
                result[i_n1 + i_n2] = (sum % 10) + '0';
                carry = sum/10;
                i_n2++;
            }
            if(carry > 0)
                result[i_n1 + i_n2] += carry;
            i_n1++;
        }
        while(result.back() == '0'){
            result.pop_back();
        }
        reverse(result.begin(),result.end());
        return result;
    }
};

