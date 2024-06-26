// 1249. Minimum Remove to Make Valid Parentheses

// Naive solution using 2 stacks
// Time complexity: O(n)
// Space complexity: O(n)
class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<char> stk1, stk2;
        int sum = 0;
        for(char ch : s){
            if(sum > 0 && ch == ')'){
                stk1.push(ch);
                sum--;
            }
            else if(ch == '('){
                stk1.push(ch);
                sum++;
            }
            else if(ch >= 'a' && ch <= 'z'){
                stk1.push(ch);
            }
        }
        string result = "";
        while(!stk1.empty()){
            if(sum > 0 && stk1.top() == '('){
                stk1.pop();
                sum--;
            }
            else{
                stk2.push(stk1.top());
                stk1.pop();
            }
        }
        while(!stk2.empty()){
            result += stk2.top();
            stk2.pop();
        }
        return result;
    }
};

// Optimized solution using 1 stack by modifying the string in place
// if we encounter '(', we push to stack and if we encounter ')' and there's no balance then we make it '#', else we pop
// if there're some leftover '(', we make it '#', now we erase all '#' from string
// Time complexity: O(n)
// Space complexity: O(n)
class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int> stk;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(') stk.push(i);
            if (s[i] == ')') {
                if (!stk.empty()) stk.pop();
                else s[i] = '#';
            }
        }
        while (!stk.empty()) {
            s[stk.top()] = '#';
            stk.pop();
        }
        s.erase(remove(s.begin(), s.end(), '#'), s.end());
        return s;
    }
};

// Solution using Stack and Set
// Time complexity: O(n)
// Space complexity: O(n)
class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int n = s.size();
        stack<int> stk;
        unordered_set<int> st;
        for(int i = 0; i < n;i++){
            if(s[i] == '(') stk.push(i);
            else if(s[i] == ')'){
                if(stk.empty()) st.insert(i);
                else stk.pop();
            }
        }
        while(!stk.empty()){
            st.insert(stk.top());
            stk.pop();
        }
        if(st.empty()) return s;
        string res = "";
        for(int i = 0; i < s.size();i++)
            if(!st.count(i)) res += s[i];
        return res;
    }
};

// Solution without using stack
// Time complexity: O(n)
// Space complexity: O(1)
class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int n = s.size();
        int count=0;
        for(int i=0;i<n;++i){
            if(s[i]=='('){
                ++count;
            }
            else if(s[i]==')'){
                if(count==0){
                    s[i]='#';
                }
                else{
                    --count;
                }
            }
        }
        count = 0;
        for(int i = n-1;i >= 0;--i){
            if(s[i]==')'){
                ++count;
            }
            else if(s[i]=='('){
                if(count==0){
                    s[i]='#';
                }
                else{
                    --count;
                }
            }
        }
        s.erase(remove(s.begin(), s.end(), '#'), s.end());
        return s;
    }
};