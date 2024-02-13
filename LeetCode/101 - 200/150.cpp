// 150. Evaluate Reverse Polish Notation

// Solution 1 using Stack to maintain operands
// Time complexity: O(n)
// Space complexity: O(n)

class Solution {
public:
    bool isOperator(string& str){
        return str== "+" || str == "-" || str == "*" || str == "/";
    }
    int evalRPN(vector<string>& tokens) {
        stack<int> stk;
        for(string& token : tokens){
            if(isOperator(token)){
                int op2 = stk.top();
                stk.pop();
                int op1 = stk.top();
                stk.pop();
                if(token == "+") stk.push(op1+op2);
                else if(token == "*") stk.push(op1*op2);
                else if(token == "-") stk.push(op1-op2);
                else stk.push(op1/op2);
            }
            else stk.push(stoi(token));
        }
        return stk.top();
    }
};

// Solution 2 using input as stack
// Time complexity: O(n)
// Space complexity: O(1)
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int top = 0;
        for(string& token : tokens){
            if(token == "+" || token == "-" || token == "*" || token == "/"){
                int op2 = stoi(tokens[--top]), op1 = stoi(tokens[--top]);
                if(token == "+") tokens[top++] = to_string(op1+op2);
                else if(token == "*") tokens[top++] = to_string(op1*op2);
                else if(token == "-") tokens[top++] = to_string(op1-op2);
                else tokens[top++] = to_string(op1/op2);
            }
            else tokens[top++] = token;
        }
        return stoi(tokens[0]);
    }
};