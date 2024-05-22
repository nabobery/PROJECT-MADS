// 1325. Delete Leaves With a Given Value

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

// Solution 1 using basic DFS
// Time complexity: O(n)
// Space complexity: O(n)
class Solution {
public:
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        if(!root->left && !root->right){
            if(root->val == target) return NULL;
            return root;
        }
        TreeNode* l = NULL, *r = NULL;
        if(root->left) l = removeLeafNodes(root->left, target);
        if(root->right) r = removeLeafNodes(root->right, target);
        root->left = l; root->right = r;
        if(!l && !r && root->val == target) return NULL;
        return root;
    }
};