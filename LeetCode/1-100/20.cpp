// 20. Valid Parentheses
// my naive O(n) time and space solution using Stack
class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        char temp;
        for(char ch : s){
            if(ch == '(' || ch == '{' || ch == '['){
                stk.push(ch);
                continue;
            }
            if(stk.empty()) return false;
            switch(ch){
                case ')':
                    temp = stk.top();
                    stk.pop();
                    if(temp == '[' || temp == '{') return false;
                    break;
                case '}':
                    temp = stk.top();
                    stk.pop();
                    if(temp == '(' || temp == '[') return false;
                    break;
                case ']':
                    temp = stk.top();
                    stk.pop();
                    if(temp == '(' || temp == '{') return false;
                    break;
            }
        }
        return(stk.empty());
    }
};

