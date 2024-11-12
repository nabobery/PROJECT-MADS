// 2696. Minimum String Length After Removing Substrings

// Solution 1: Stack
// Time complexity: O(n)
// Space complexity: O(n)
class Solution {
public:
    int minLength(string s) {
        stack<char> stk;
        int res = s.size();
        unordered_set<char> st = {'A', 'B', 'C', 'D'};
        for(char ch : s){
            if(!stk.empty()){
                if(st.count(ch)){
                    if((ch == 'B' && stk.top() == 'A') || (ch == 'D' && stk.top() == 'C')){
                        stk.pop();
                        res -= 2;
                    }
                    else stk.push(ch);
                }
                else stk.push(ch);
            }
            else stk.push(ch);
        }
        return res;
    }
};

// Solution 2: More Efficient and cleaner Solution 1 
// Time complexity: O(n)
// Space complexity: O(n)
class Solution {
public:
    int minLength(string s) {
        stack<char> stk;
        int res = s.size();
        for(char ch : s){
            if(!stk.empty() && stk.top() == 'A' && ch == 'B') stk.pop();
            else if(!stk.empty() && stk.top() == 'C' && ch == 'D') stk.pop();
            else stk.push(ch);
        }
        return stk.size();
    }
};