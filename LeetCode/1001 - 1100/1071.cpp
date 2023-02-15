// 1071. Greatest Common Divisor of Strings

class Solution {
public:
    int gcd(int a, int b){
        if(b==0) return a;
        return gcd(b,a%b);
    }
    string gcdOfStrings(string str1, string str2) {
        int n1 = str1.size(), n2 = str2.size();
        int n = gcd(n1,n2);
        int i = 0, j = 0;
        bool flag = true;
        string t1, t2;
        while(i < n1 || j < n2){
            if(i < n1){
                t1 = str1.substr(i,n);
                i += n;
            }
            if(j < n2){
                t2 = str2.substr(j,n);
                j += n;
            }
            if(t1 != t2){
                flag = false;
                break;
            }
        }
        return (flag ? t1 : "");
    }
};