// 402. Remove K Digits
// my greedy solution
class Solution {
public:
    string removeKdigits(string num, int k) {
        if(num.size() == k) return "0";
        stack<char> stk;
        for(int i = 0; i < num.size();i++){
            if(!stk.empty() && k > 0){
                while(!stk.empty() && stk.top() > num[i] && k > 0){
                    stk.pop();
                    k--;
                }
            }
            stk.push(num[i]);
        }
        while(k > 0){
            stk.pop();
            k--;
        }
        stack<char> temp;
        while(!stk.empty()){
            temp.push(stk.top());
            stk.pop();
        }
        string result = "";
        while(!temp.empty() && temp.top() == '0'){
            temp.pop();
        }
        while(!temp.empty()){
            result += temp.top();
            temp.pop();
        }
        if(result == "") return "0";
        return result;
    }
};
