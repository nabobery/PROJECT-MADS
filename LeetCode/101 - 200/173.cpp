// 173. Binary Search Tree Iterator
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */

// my naive solution
class BSTIterator {
public:
    int i;
    vector<int> node;

    void helper(TreeNode* root){
        if(!root) return;
        helper(root->left);
        node.push_back(root->val);
        helper(root->right);
    }

    BSTIterator(TreeNode* root) {
        i = 0;
        helper(root);
    }

    int next() {
        return node[i++];
    }

    bool hasNext() {
        return(i < node.size());
    }
};

// another solution using stack
class BSTIterator {
    stack<TreeNode*> stk;
public:
    BSTIterator(TreeNode* root) {
        while(root){
            stk.push(root);
            root = root->left;
        }
    }

    int next() {
        TreeNode* curr =  stk.top();
        int result = curr->val;
        curr = curr->right;
        stk.pop();
        while(curr){
            stk.push(curr);
            curr = curr->left;
        }
        return result;

    }

    bool hasNext() {
        return(!stk.empty());
    }
};

