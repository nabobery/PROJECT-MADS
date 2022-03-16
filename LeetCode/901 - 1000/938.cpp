// 938. Range Sum of BST
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
class Solution {
public:
    int sum;
    int rangeSumBST(TreeNode* root, int low, int high) {
        sum = 0;
        helper(root,low,high);
        return sum;    
    }
    void helper(TreeNode* root, int low, int high){
        if(root != NULL){
            if(root->val >= low && root->val <= high){
                sum += root->val;
            }
            if(root->val > low)
                helper(root->left, low, high);
            if(root->val < high) 
                helper(root->right, low, high);
        }
    }
};