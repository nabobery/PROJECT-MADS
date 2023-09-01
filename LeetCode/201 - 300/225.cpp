// 225. Implement Stack using Queues

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */

// Naive 2 Queues Solution push O(1) pop O(n)
class MyStack {
public:
    queue<int> q1, q2;
    MyStack() {
        
    }
    
    void push(int x) {
        q1.push(x);
    }
    
    int pop() {
        q2 = {};
        while(q1.size() != 1){
            q2.push(q1.front());
            q1.pop();
        }
        int res = q1.front();
        q1.pop();
        q1 = q2;
        return res;
    }
    
    int top() {
        q2 = {};
        while(q1.size() != 1){
            q2.push(q1.front());
            q1.pop();
        }
        int res = q1.front();
        q1.pop();
        q2.push(res);
        q1 = q2;
        return res;
    }
    
    bool empty() {
        return q1.size() == 0;
    }
};


// Naive 2 Queue Solution push O(n) pop O(1)
// q1 acts as a stack
// q2 is used to push new elements
class MyStack {
public:
    queue<int> q1, q2;
    MyStack() {
        
    }
    
    void push(int x) {
        q2.push(x);
        while(q1.size()){
            q2.push(q1.front());
            q1.pop();
        }
        swap(q1, q2);
    }
    
    int pop() {
        int res = q1.front();
        q1.pop();
        return res;
    }
    
    int top() {
        return q1.front();
    }
    
    bool empty() {
        return q1.size() == 0;
    }
};

// 1 Queue Solution push O(n) pop O(1)
// q1 acts as a stack, we push new elements to the back of the queue and then reverse the order
class MyStack {
public:
    queue<int> q1;
    MyStack() {
        
    }
    
    void push(int x) {
        q1.push(x);
        int n = q1.size();
        while(n > 1){
            q1.push(q1.front());
            q1.pop();
            n--;
        }
    }
    
    int pop() {
        int res = q1.front();
        q1.pop();
        return res;
    }
    
    int top() {
        return q1.front();
    }
    
    bool empty() {
        return q1.size() == 0;
    }
};