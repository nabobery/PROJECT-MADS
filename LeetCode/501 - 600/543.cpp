// 543. Diameter of Binary Tree

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

// Solution 1 using basic DFS and calculating diameter at each node by using depth
// Time Complexity: O(n)
// Space Complexity: O(n)
class Solution {
public:
    int res;
    int helper(TreeNode* root, int depth){
        if(!root) return depth;
        int l = depth, r = depth; 
        if(root->left) l = helper(root->left, depth+1);
        if(root->right) r = helper(root->right, depth+1);
        res = max(res, l+r - 2*depth);
        return max(l,r);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        res = 0;
        helper(root, 0);
        return res;
    }
};

// A Cleaner version of Solution 1
class Solution {
public:
    int res;
    int helper(TreeNode* root){
        if(!root) return 0;
        int l = helper(root->left);
        int r = helper(root->right);
        res = max(res, l+r);
        return max(l,r) + 1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        res = 0;
        helper(root);
        return res;
    }
};
