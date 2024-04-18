// 1614. Maximum Nesting Depth of the Parentheses

// Solution 1 using stack 
// Time complexity: O(n)
// Space complexity: O(n)
class Solution {
public:
    int maxDepth(string s) {
        stack<char> stk;
        int res = 0;
        for(char ch : s){
            if(ch == '(') stk.push(ch);
            else if(ch == ')') stk.pop();
            res = max(res, (int)stk.size());
        }
        return res;
    }
};

// Solution 2 using two variables
// Time complexity: O(n)
// Space complexity: O(1)
class Solution {
public:
    int maxDepth(string s) {
        int res = 0, cnt = 0;
        for(char ch : s){
            if(ch == '(') cnt++;
            else if(ch == ')') cnt--;
            res = max(res, cnt);
        }
        return res;
    }
};