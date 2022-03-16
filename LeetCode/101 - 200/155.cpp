// 155. Min Stack
// my naive solution
class MinStack {
public:
    vector<int> stk;
    vector<int> min;
    MinStack() {

    }

    void push(int val) {
        stk.push_back(val);
        if(min.empty() || min.back() > val){
            min.push_back(val);
        }
        else{
            min.push_back(min.back());
        }
    }

    void pop() {
        stk.pop_back();
        min.pop_back();
    }

    int top() {
        return stk.back();
    }

    int getMin() {
        return min.back();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

