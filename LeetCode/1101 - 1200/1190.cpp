// 1190. Reverse Substrings Between Each Pair of Parentheses

// Solution 1 using Stack and Queue
// Time complexity: O(n)
// Space complexity: O(n)
class Solution {
public:
    string reverseParentheses(string s) {
        string res;
        stack<char> stk;
        queue<char> temp;
        for(char ch : s){
            if(ch != ')') stk.push(ch);
            else{
                while(stk.top() != '('){
                    temp.push(stk.top());
                    stk.pop();
                }
                stk.pop();
                while(!temp.empty()){
                    stk.push(temp.front());
                    temp.pop();
                }
            }
        }
        while(!stk.empty()){
            res.push_back(stk.top());
            stk.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};

// Solution 2 using Stack
// Time complexity: O(n)
// Space complexity: O(n)
class Solution {
public:
    string reverseParentheses(string s) {
        stack<int> stk;
        vector<int> pair(s.size());
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '(') stk.push(i);
            if(s[i] == ')'){
                int j = stk.top();
                stk.pop();
                pair[i] = j;
                pair[j] = i;
            }
        }
        string res;
        for(int i = 0, d = 1; i < s.size(); i += d){
            if(s[i] == '(' || s[i] == ')'){
                i = pair[i];
                d = -d;
            }
            else res.push_back(s[i]);
        }
        return res;
    }
};