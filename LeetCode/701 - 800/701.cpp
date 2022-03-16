// 701. Insert into a Binary Search Tree
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
 // my naive recursive sol O(n) time and space
class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root == NULL){
            root = new TreeNode(val);
        }
        else{
            if(val < root->val){
                root->left = insertIntoBST(root->left,val);
            }
            else if (val > root->val){
                root->right = insertIntoBST(root->right,val);
            }
        }
        return root;
    }
};

// iterative solution O(n) time and O(1) space
class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root == NULL){
            root = new TreeNode(val);
            return root;
        }
        TreeNode *y = NULL;
        TreeNode *x = root;
        while(x != NULL){
            y = x;
            if(val < x->val){
                x = x->left;
            }
            else
                x = x->right;
        }
        if(val < y->val){
            y->left = new TreeNode(val);
        }
        else{
            y->right = new TreeNode(val);
        }
        return root;
    }
};

