// 921. Minimum Add to Make Parentheses Valid

// Solution 1: Stack (Simple)
// Time complexity: O(n)
// Space complexity: O(n)
class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char> stk;
        int res = 0;
        for(char ch : s){
            if(ch == ')'){
                if(!stk.empty()) stk.pop();
                else res++;
            }
            else stk.push(ch);
        }
        res += stk.size();
        return res;
    }
};