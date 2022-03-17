// 856. Score of Parentheses
// O(n) time and O(n) space solution using string stack
class Solution {
public:
    int scoreOfParentheses(string s) {
        // string stack
        stack<string> stk;
        int result = 0;
        // iterate over the string
        for(char ch : s){
            // if we encounter a ( push it into stack
            if(ch == '('){
                stk.push("(");
            }
            // if we encounter a )
            else{
                // if the top is a ( then we push 1 as it means we encountered a () so push 1 as score of () is 1
                if(stk.top() == "("){
                    stk.pop();
                    stk.push("1");
                }
                // if we encounter the intermediate result then calculate and get the sum of the inner parenthesis and then double the intermediate result
                else{
                    int temp = 0;
                    // calculate everything inside the inner parenthesis
                    while(stk.top() != "("){
                        temp += stoi(stk.top());
                        stk.pop();
                    }
                    // double the current result and push it into stack and pop the outer ( for the inner brackets as (A) = 2*score(A)
                    stk.pop();
                    stk.push(to_string(2*temp));
                }
            }
        }
        // get the result by adding the various parenthesis sum as AB = A + B
        while(!stk.empty()){
            result += stoi(stk.top());
            stk.pop();
        }
        // return result
        return result;
    }
};

// O(n) time and O(1) space solution
class Solution {
public:
    int scoreOfParentheses(string s) {
        // result and temp which holds the depth of nested brackets
        int result = 0, temp = 0;
        for(int i = 0; i < s.size();i++){
            // increase the depth if we encounter a (
            if(s[i] == '(') temp++;
            else{
                // decrease the depth if we encounter a )
                temp--;
                // if the prev bracket is a (, then add the 2^depth to result as (A) = 2*A, if depth is 0 () then it just adds 1
                if(s[i-1] == '(')
                    result += 1 << temp;
            }
        }
        return result;
    }
};


