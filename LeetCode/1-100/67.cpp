//67. Add Binary
// my naive sol
class Solution {
public:
    string addBinary(string a, string b) {
        int m = a.size(), n = b.size();
        if(m != n){
            if(m > n){
                for(int i = n; i < m;i++){
                    b = '0' + b;
                }
            }
            else if(n > m){
                for(int i = m; i < n;i++){
                    a = '0' + a;
                }
            }
        }
        char carry = '0';
        int sum = 0;
        string result = "";
        for(int i = max(m,n) - 1; i >= 0;i--){
            sum = carry - '0' + a[i] - '0' + b[i] - '0';
            if(sum == 0 || sum == 1){
                char temp = (sum + '0');
                result =  temp + result;
                carry = '0';
            }
            else{
                char temp = ((sum%2) +'0');
                result = temp + result;
                carry = '1';
            }
        }
        if(carry != '0'){
            result = carry + result;
        }
        return result;
    }
};

// short and concise solution
class Solution {
public:
    string addBinary(string a, string b) {
        int i = a.size() - 1, j = b.size() - 1, carry = 0;
        string result = "";
        while(i >= 0 || j >= 0 || carry == 1){
            carry += i >= 0 ? a[i--] - '0' : 0;
            carry += j >= 0 ? b[j--] - '0' : 0;
            result = char(carry % 2 + '0') + result;
            carry /= 2;
        }
        return result;
    }
};

// same solution with more memory efficiency
class Solution {
public:
    string addBinary(string a, string b) {
        int i = a.size() - 1, j = b.size() - 1, carry = 0;
        auto result = ""s;
        while(i >= 0 || j >= 0 || carry){
            if (i >= 0 && a[i--] == '1') ++carry;
            if (j >= 0 && b[j--] == '1') ++carry;
            result.insert(0, carry % 2 == 1 ? "1" : "0");
            carry /= 2;
        }
        return result;
    }
};

