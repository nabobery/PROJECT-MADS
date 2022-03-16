// 337. House Robber III
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

// not efficient enough
class Solution {
public:
    int rob(TreeNode* root) {
        int* result = helper(root);
        return max(result[0],result[1]);
    }
    int* helper(TreeNode* root){
        if(root == NULL){
            return new int[]{0,0};
        }
        int *left = helper(root->left);
        int *right = helper(root->right);
        int rob_y = root->val + left[0] + right[0];
        int rob_n = max(left[0],left[1]) + max(right[0], right[1]);
        return new int[]{rob_n, rob_y};
    }
};