// 341. Flatten Nested List Iterator

/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */

// Solution 1 using recursion and Queue
// Time complexity: O(n)
// Space complexity: O(n)
class NestedIterator {
public:
    queue<int> q;
    void helper(vector<NestedInteger>& list, int index){
        if(index >= list.size()) return;
        if(list[index].isInteger()){
            q.push(list[index].getInteger());
        }
        else{
            vector<NestedInteger> li = list[index].getList();
            helper(li, 0);
        }
        helper(list, index+1);
    }
    NestedIterator(vector<NestedInteger> &nestedList) {
        helper(nestedList, 0);
    }
    
    int next() {
        int res = q.front();
        q.pop();
        return res;
    }
    
    bool hasNext() {
        return (!q.empty());
    }
};

// Solution 2 using stack
// Time complexity: O(n)
// Space complexity: O(n)
class NestedIterator {
public:
    stack<NestedInteger> s;
    NestedIterator(vector<NestedInteger> &nestedList) {
        for(int i = nestedList.size()-1; i >= 0; i--){
            s.push(nestedList[i]);
        }
    }
    
    int next() {
        int res = s.top().getInteger();
        s.pop();
        return res;
    }
    
    bool hasNext() {
        while(!s.empty()){
            NestedInteger curr = s.top();
            if(curr.isInteger()) return true;
            s.pop();
            vector<NestedInteger> li = curr.getList();
            for(int i = li.size()-1; i >= 0; i--){
                s.push(li[i]);
            }
        }
        return false;
    }
};