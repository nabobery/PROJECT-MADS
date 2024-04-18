// 129. Sum Root to Leaf Numbers

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

// Solution 1 using DFS
// Time complexity: O(n)
// Space complexity: O(n)
class Solution {
public:
    int res;
    void helper(TreeNode* root, int sum){
        sum = sum*10 + root->val;
        if(!root->left && !root->right){
            res += sum;
            return;
        }
        if(root->left) helper(root->left, sum);
        if(root->right) helper(root->right, sum);
    }
    int sumNumbers(TreeNode* root) {
        res = 0;
        helper(root, 0);
        return res;
    }
};