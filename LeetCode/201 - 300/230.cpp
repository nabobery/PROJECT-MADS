// 230. Kth Smallest Element in a BST
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
 // my naive solution using O(n) time and O(k) space
class Solution {
public:
    vector<int> result;
    void inorder(TreeNode* root, int k){
        if(!root || result.size() > k) return;
        inorder(root->left,k);
        result.push_back(root->val);
        inorder(root->right,k);
    }
    int kthSmallest(TreeNode* root, int k) {
        inorder(root,k);
        return result[k-1];
    }
};

// O(h+k) time and O(h) space iterative solution (worst case : O(n + k) and O(n))
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> stk;
        while(true){
            // go from root to smallest then start traversing
            while(root){
                stk.push(root);
                root = root->left;
            }
            root = stk.top();
            stk.pop();
            if(--k == 0) return root->val;
            root = root->right;
        }
    }
};