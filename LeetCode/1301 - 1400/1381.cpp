// 1381. Design a Stack With Increment Operation

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */

// Solution 1 by using vector and top pointer
// Time complexity: O(1)
// Space complexity: O(n)
class CustomStack {
public:
    vector<int> vec;
    int top = -1, sz;
    CustomStack(int maxSize) {
        vec.resize(maxSize, -1);
        sz = 0;
    }
    
    void push(int x) {
        if(sz < vec.size()){
            top++;
            vec[top] = x;
            sz++;
        }
    }
    
    int pop() {
        if(sz == 0) return -1;
        sz--;
        return vec[top--];
    }
    
    void increment(int k, int val) {
        for(int i = 0; i < min(sz, k);i++) vec[i] += val;
    }
};