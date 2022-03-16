// 946. Validate Stack Sequences
//my naive simulation solution
class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int n = pushed.size();
        int i = 0, j = 0;
        stack<int> stk;
        for(; i < n;i++){
            if(pushed[i] == popped[j]){
                j++;
            }
            else if(!stk.empty() && stk.top() == popped[j]){
                j++;
                i--;
                stk.pop();
            }
            else if(pushed[i] != popped[j]){
                stk.push(pushed[i]);
            }
        }
        while(!stk.empty()){
            int temp = stk.top();
            stk.pop();
            if(temp != popped[j]) return false;
            j++;
        }
        return true;
    }
};

// greedy O(n) space and time solution (in less lines)
class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int n = pushed.size();
        stack<int> stk;
        int j = 0;
        for(int x : pushed){
            stk.push(x);
            while(!stk.empty() && j < n && stk.top() == popped[j]){
                stk.pop();
                j++;
            }
        }
        return j == n;
    }
};




