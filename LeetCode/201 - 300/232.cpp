// 232. Implement Queue using Stacks

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */

// Solution 1 Simple and Naive
// Time Complexity: O(n)
// Space Complexity: O(n)

// O(1) push, peek, empty and O(n) pop

class MyQueue {
public:
    stack<int> s1, s2;
    int front;
    MyQueue() {
        
    }
    
    void push(int x) {
        if(s1.empty()) front = x;
        s1.push(x);
    }
    
    int pop() {
        while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }
        int res = s2.top();
        s2.pop();
        if(!s2.empty()) front = s2.top();
        while(!s2.empty()){
            s1.push(s2.top());
            s2.pop();
        }
        return res;
    }
    
    int peek() {
        return front;
    }
    
    bool empty() {
        return s1.empty();
    }
};

// Solution 2 Amortized O(1) pop
// Time Complexity: O(1)
// Space Complexity: O(n)

// O(1) push, peek, empty and pop

class MyQueue {
public:
    stack<int> s1, s2;
    int front;
    MyQueue() {
        
    }
    
    void push(int x) {
        if(s1.empty()) front = x;
        s1.push(x);
    }
    
    int pop() {
        if(s2.empty()){
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
        }
        int res = s2.top();
        s2.pop();
        return res;
    }
    
    int peek() {
        if(!s2.empty()) return s2.top();
        return front;
    }
    
    bool empty() {
        return s1.empty() && s2.empty();
    }
};
