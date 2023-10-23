// 844. Backspace String Compare

// Solution 1 using Stack
// Time complexity: O(n)
// Space complexity: O(n)
class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char> stk1, stk2;
        for(auto ch : s){
            if(ch == '#'){
                if(!stk1.empty()) stk1.pop();
            }
            else stk1.push(ch);
        }
        for(auto ch : t){
            if(ch == '#'){
                if(!stk2.empty()) stk2.pop();
            }
            else stk2.push(ch);
        }
        return (stk1 == stk2);
    }
};

// Solution 2 using Two Pointers
// Time complexity: O(n)
// Space complexity: O(1)
class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int i = s.size()-1, j = t.size()-1;
        int skip1 = 0, skip2 = 0;
        while(i >= 0 || j >= 0){
            while(i >= 0){
                if(s[i] == '#'){
                    skip1++;
                    i--;
                }
                else if(skip1 > 0){
                    skip1--;
                    i--;
                }
                else break;
            }
            while(j >= 0){
                if(t[j] == '#'){
                    skip2++;
                    j--;
                }
                else if(skip2 > 0){
                    skip2--;
                    j--;
                }
                else break;
            }
            if(i >= 0 && j >= 0 && s[i] != t[j]) return false;
            if((i >= 0) != (j >= 0)) return false;
            i--;
            j--;
        }
        return true;
    }
};