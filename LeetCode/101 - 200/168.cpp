// 168. Excel Sheet Column Title

// Solution 1
class Solution {
public:
    string convertToTitle(int columnNumber) {
        string res;
        while(columnNumber > 0){
            columnNumber--;
            res += (columnNumber%26 + 'A');
            columnNumber /= 26;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};

// Solution 2
class Solution {
public:
    string convertToTitle(int columnNumber) {
        stack<char> stk;
        while(columnNumber > 0){
            columnNumber -= 1;
            stk.push(columnNumber%26 + 'A');
            columnNumber /= 26;
        }
        string res = "";
        while(!stk.empty()){
            res += stk.top();
            stk.pop();
        }
        return res;
    }
};