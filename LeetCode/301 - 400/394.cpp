// 394. Decode String
// using 2 stacks
class Solution {
public:
    string decodeString(string s) {
        string result = "", temp = "";
        stack <int> stk1;
        stack <char> stk2;
        for(int i = 0; i < s.length(); i++){
            int count = 0;
            if(s[i] >= '0' && s[i] <= '9'){
                while(s[i] >= '0' && s[i] <= '9'){
                    count = count * 10 + s[i] - '0';
                    i++;
                }
                i--;
                stk1.push(count);
            }
            else if(s[i] == ']'){
                temp = "";
                count = 0;
                if(!stk1.empty()){
                    count = stk1.top();
                    stk1.pop();
                }
                while(!stk2.empty() && stk2.top() != '['){
                    temp = stk2.top() + temp;
                    stk2.pop();
                }
                if(!stk2.empty() && stk2.top() == '['){
                    stk2.pop();
                }
                for(int j = 0; j < count;j++){
                    result = result + temp;
                }
                for(int j = 0; j < result.length(); j++){
                    stk2.push(result[j]);
                }
                result = "";
            }
            else if(s[i] == '['){
                if(s[i-1] >= '0' && s[i-1] <= '9'){
                    stk2.push(s[i]);
                }
                else{
                    stk2.push(s[i]);
                    stk1.push(1);
                }
            }
            else{
                stk2.push(s[i]);
            }
        }
        while(!stk2.empty()){
            result = stk2.top() + result;
            stk2.pop();
        }
        return result;
    }
};

// using 1 stack
class Solution {
public:
    string decodeString(string s) {
        stack <char> stk;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == ']'){
                string temp;
                while(!stk.empty() && stk.top() != '['){
                    temp = stk.top() + temp;
                    stk.pop();
                }
                stk.pop();
                string k;
                while(!stk.empty() && isdigit(stk.top())){
                    k = stk.top() + k;
                    stk.pop();
                }
                int count = stoi(k);
                string tmp;
                for(int j = 0; j < count;j++)
                    tmp += temp;
                for(char ch : tmp)
                    stk.push(ch);
            }
            else{
                stk.push(s[i]);
            }
        }
        string result;
        while(!stk.empty()){
            result = stk.top() + result;
            stk.pop();
        }
        return result;
    }
};