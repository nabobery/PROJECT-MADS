// 1038. Binary Search Tree to Greater Sum Tree

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

// Solution 1 using Inorder Traversal and calculating the sum of the tree
// Time complexity: O(n)
// Space complexity: O(n)
class Solution {
public:
    int findSum(TreeNode* root){
        if(!root) return 0;
        int sum = root->val + findSum(root->left) + findSum(root->right);
        return sum;
    }
    void helper(TreeNode* root, int& s){
        if(!root) return;
        if(root->left) helper(root->left, s);
        s -= root->val;
        root->val += s;
        if(root->right) helper(root->right, s);
    }
    TreeNode* bstToGst(TreeNode* root) {
        int sum = findSum(root);
        helper(root, sum);
        return root;
    }
};