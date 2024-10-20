// 1106. Parsing A Boolean Expression

// Solution 1: Using 2 stacks
// Time complexity: O(n)
// Space complexity: O(n)
class Solution {
public:
    unordered_map<char, bool> operands_mp = {
        {'t', true},
        {'f', false}
    };
    unordered_set<char> operator_st = {'!', '&', '|'};
    bool parseBoolExpr(string expression) {
        int n = expression.size();
        stack<int> operands, operators;
        for(int i = 0; i < n;i++){
            if(operator_st.count(expression[i])) operators.push(i);
            else if(operands_mp.count(expression[i])) operands.push(i);
            else if(expression[i] == ')'){
                int op_ind = operators.top();
                operators.pop();
                char op = expression[op_ind];
                if(op == '!'){
                    int ind = operands.top();
                    operands.pop();
                    expression[i] = expression[ind] == 'f' ? 't' : 'f';
                    if(!operators.empty()) operands.push(i); 
                }
                else{
                    bool result = (op == '&');
                    while(!operands.empty() && op_ind < operands.top()){
                        bool val = operands_mp[expression[operands.top()]];
                        operands.pop();
                        result = (op == '&') ? (result && val) : (result || val);
                    }
                    expression[i] = result ? 't' : 'f';
                    if(!operators.empty()) operands.push(i); 
                }
            }
        }
        return operands_mp[expression[n-1]];
    }
};