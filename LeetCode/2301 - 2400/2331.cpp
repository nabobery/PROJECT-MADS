// 2331. Evaluate Boolean Binary Tree

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

// Solution 1 using basic dfs
// Time complexity: O(n)
// Space complexity: O(n)
class Solution {
public:
    bool evaluateTree(TreeNode* root) {
        if(!root->left && !root->right) return root->val;
        bool l = evaluateTree(root->left), r = evaluateTree(root->right);
        if(root->val == 2) return l | r;
        return l & r;
    }
};