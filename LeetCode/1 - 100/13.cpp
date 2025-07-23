// 13. Roman to Integer
class Solution {
public:
    int romanToInt(string s) {
        int result = 0;
        if(s[0] == 'I'){
            result++;
        }
        else if(s[0] == 'V'){
            result += 5;
        }
        else if(s[0] == 'X'){
            result += 10;
        }
        else if(s[0] == 'L'){
            result += 50;
        }
        else if(s[0] == 'C'){
            result += 100;
        }
        else if(s[0] == 'D'){
            result += 500;
        }
        else{
            result += 1000;
        }
        for(int i = 1; i < s.length(); i++){
            if(s[i] == 'I'){
                result++;
            }
            else if(s[i] == 'V'){
                if(s[i - 1] == 'I')
                    result += 3;
                else
                    result += 5;
            }
            else if(s[i] == 'X'){
                if(s[i - 1] == 'I')
                    result += 8;
                else
                    result += 10;
            }
            else if(s[i] == 'L'){
                if(s[i - 1] == 'X')
                    result += 30;
                else
                    result += 50;
            }
            else if(s[i] == 'C'){
                if(s[i - 1] == 'X')
                    result += 80;
                else
                    result += 100;
            }
            else if(s[i] == 'D'){
                if(s[i - 1] == 'C')
                    result += 300;
                else
                    result += 500;
            }
            else{
                if(s[i - 1] == 'C')
                    result += 800;
                else
                    result += 1000;
            }
        }
        return result;
    }
};