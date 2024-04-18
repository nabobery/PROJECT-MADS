// 1544. Make The String Great

// Solution 1 using stack
// Time complexity: O(n)
// Space complexity: O(n)
class Solution {
public:
    string makeGood(string s) {
        int n = s.size();
        stack<char> stk;
        string res = "";
        for(int i = 0; i < n;i++){
            stk.push(s[i]);
            while(stk.size() > 1){
                char c = stk.top(); stk.pop();
                if(c != stk.top() && (c == tolower(stk.top()) || c == toupper(stk.top()))) stk.pop();
                else{
                    stk.push(c);
                    break;
                }
            }
        }
        while(!stk.empty()){
            res += stk.top(); 
            stk.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};

// Solution 2 using string as stack
// Time complexity: O(n)
// Space complexity: O(n)
class Solution {
public:
    string makeGood(string s) {
        string res = "";
        for(char c : s){
            if(res.size() && (c != res.back() && (c == tolower(res.back()) || c == toupper(res.back()))))
                res.pop_back();
            else
                res.push_back(c);
        }
        return res;
    }
};