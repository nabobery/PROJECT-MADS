// 110. Balanced Binary Tree

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


// Solution 1: DFS
// Time Complexity: O(n)
// Space Complexity: O(h) where h is the height of the tree
class Solution {
public:
    pair<bool, int> helper(TreeNode* root){
        if(!root->left && !root->right) return {true, 0};
        pair<bool,int> l = {false, -1}, r = l, res = {true, 0};
        if(root->left){
            l = helper(root->left);
            res.first &= l.first;
        }
        if(root->right){
            r = helper(root->right);
            res.first &= r.first;
        }
        res.second = max(l.second, r.second)+1;
        res.first &= abs(l.second - r.second) < 2;
        return res;
    }
    bool isBalanced(TreeNode* root) {
        if(!root) return true;
        return helper(root).first;
    }
};

// Solution 2: DFS with early stopping
// Time Complexity: O(n)
// Space Complexity: O(h) where h is the height of the tree
class Solution {
public:
    int checkHeight(TreeNode* root) {
        if (!root) return 0;

        // Recursively get height of left subtree
        int leftHeight = checkHeight(root->left);
        if (leftHeight == -1) return -1; // Left is already unbalanced

        // Recursively get height of right subtree
        int rightHeight = checkHeight(root->right);
        if (rightHeight == -1) return -1; // Right is already unbalanced

        // Check current node balance: if difference > 1, return -1
        if (abs(leftHeight - rightHeight) > 1) return -1;

        // Otherwise, return the actual height
        return max(leftHeight, rightHeight) + 1;
    }

    bool isBalanced(TreeNode* root) {
        return checkHeight(root) != -1;
    }
};