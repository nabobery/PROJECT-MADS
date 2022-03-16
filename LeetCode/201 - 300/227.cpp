// 227. Basic Calculator II
// first sol time : O(n) and space: O(n)
class Solution {
public:
    int priority(char op){
        if(op == '+' || op == '-')
            return 1;
        if(op == '*' || op == '/')
            return 2;
        return 0;
    }
    
    int operation(int a , int b, char op){
        if(op == '+')
            return a + b;
        else if(op == '-')
            return a - b;
        else if(op == '*')
            return a*b;
        else if(op == '/')
            return a/b;
        return 0;
    }
    
    int calculate(string s) {
        stack <int> val;
        stack <char> ops;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == ' ')
                continue;
            if(isdigit(s[i])){
                int temp = 0;
                while(i < s.size() && isdigit(s[i])){
                    temp = temp*10 + (s[i] - '0');
                    i++;
                }
                val.push(temp);
                i--;
            }
            else{
                while(!ops.empty() && priority(ops.top()) >= priority(s[i])){
                    int temp2 = val.top();
                    val.pop();
                    int temp1 = val.top();
                    val.pop();
                    char op = ops.top();
                    ops.pop();
                    val.push(operation(temp1, temp2,op));
                }
                ops.push(s[i]);
            }
        }
        while(!ops.empty()){
            int temp2 = val.top();
            val.pop();
            int temp1 = val.top();
            val.pop();
            char op = ops.top();
            ops.pop();
            val.push(operation(temp1, temp2,op));
        }
        return val.top();
    }
};

// not better than 1st time : O(n) and space: O(n)
class Solution {
public:
    int calculate(string s) {
        int n =  s.size();
        stack<int> stk;
        int curr = 0;
        char op = '+';
        for(int i = 0; i < n; i++){
            char ch = s[i];
            if(isdigit(ch)){
                curr = curr*10 + (ch - '0');
            }
            if(!isdigit(ch) && !iswspace(ch) || i == n - 1){
                if(op == '-'){
                    stk.push(-curr);
                }
                else if(op == '+'){
                    stk.push(curr);
                }
                else if(op == '*'){
                    int temp = stk.top();
                    stk.pop();
                    stk.push(temp*curr);
                }
                else if(op == '/'){
                    int temp = stk.top();
                    stk.pop();
                    stk.push(temp/curr);
                }
                op = ch;
                curr = 0 ;
            }
        }
        int result = 0;
        while(!stk.empty()){
            result += stk.top();
            stk.pop();
        }
        return result;
    }
};

// third sol time : O(n) and space: O(1)
class Solution {
public:
    int calculate(string s) {
        int n =  s.size();
        int curr = 0, prev = 0, result = 0;
        char op = '+';
        for(int i = 0; i < n; i++){
            char ch = s[i];
            if(isdigit(ch)){
                curr = curr*10 + (ch - '0');
            }
            if(!isdigit(ch) && !iswspace(ch) || i == n - 1){
                if(op == '-' || op == '+'){
                    result += prev;
                    prev = (op == '+') ? curr : - curr;
                }
                else if(op == '*'){
                    prev = prev * curr;
                }
                else if(op == '/'){
                    prev = prev / curr;
                }
                op = ch;
                curr = 0 ;
            }
        }
        result += prev;
        return result;
    }
};
