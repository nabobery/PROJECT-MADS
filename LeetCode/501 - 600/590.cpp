// 590. N-ary Tree Postorder Traversal

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

// Solution 1: Recursive
// Time complexity: O(n)
// Space complexity: O(n)

class Solution {
public:
    vector<int> res;
    void helper(Node* root){
        if(!root) return;
        for(auto children: root->children) helper(children);
        res.push_back(root->val);
    }
    vector<int> postorder(Node* root) {
        helper(root);
        return res;
    }
};

// Solution 2: Iterative
// Time complexity: O(n)
// Space complexity: O(n)
class Solution {
public:
    vector<int> postorder(Node* root) {
        vector<int> res;
        if(!root) return res;
        stack<Node*> st;
        st.push(root);
        while(!st.empty()){
            Node* node = st.top();
            st.pop();
            res.push_back(node->val);
            for(auto children: node->children) st.push(children);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};