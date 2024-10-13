// 641. Design Circular Deque


// Solution 1 by using vector and maintaining front and rear pointers and size
// Time complexity: O(1)
// Space complexity: O(n)
class MyCircularDeque {
public:
    int front, rear,n, sz;
    vector<int> vec;
    MyCircularDeque(int k) {
        n = k;
        vec.resize(n, -1);
        front = -1; 
        rear = -1;
        sz = 0;
    }
    
    bool insertFront(int value) {
        if(isFull()) return false;
        else if(isEmpty()){
            front = 0; rear = 0;
        }
        vec[front] = value;
        front = (front+1)%n;
        sz++;
        return true;
    }
    
    bool insertLast(int value) {
        if(isFull()) return false;
        else if(isEmpty()){
            front = 0; rear = 0;
        }
        rear= (rear-1+n)%n;
        vec[rear] = value;
        sz++;
        return true;
    }
    
    bool deleteFront() {
        if(isEmpty()) return false;
        front = (front-1+n) % n;
        sz--;
        return true;
    }
    
    bool deleteLast() {
        if(isEmpty()) return false;
        rear = (rear+1)%n;
        sz--;
        return true;
    }
    
    int getFront() {
        if(isEmpty()) return -1;
        return vec[(front-1+n)%n];
    }
    
    int getRear() {
        if(isEmpty()) return -1;
        return vec[rear%n];
    }
    
    bool isEmpty() {
        return sz == 0;
    }
    
    bool isFull() {
        return sz == n;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */