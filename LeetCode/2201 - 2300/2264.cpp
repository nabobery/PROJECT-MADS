// 2264. Largest 3-Same-Digit Number in String

// Solution 1 by checking for all numbers that repeat 3 times
// Time complexity: O(n)
// Space complexity: O(1)
class Solution {
public:
    string largestGoodInteger(string num) {
        string res = "";
        for(int i = 1; i < num.size();i++){
            if(num[i] == num[i-1]){
                int cnt = 2, j = i;
                while(j < num.size()-1 && num[j] == num[j+1]){
                    cnt++;
                    j++;
                }
                if(cnt >= 3)
                    if(res == "" || res[0] < num[j]) res = string(3, num[j]);
                i = j;
            }
        }
        return res;
    }
};

// Solution 2 by greedily searching for 999, 888, 777
// Time complexity: O(n)
// Space complexity: O(1)
class Solution {
public:
    string largestGoodInteger(string num) {
        string res = "";
        for(int i = 9; i >= 0;i--){
            string s = string(3, i+'0');
            if(num.find(s) != string::npos){
                res = s;
                break;
            }
        }
        return res;
    }
};