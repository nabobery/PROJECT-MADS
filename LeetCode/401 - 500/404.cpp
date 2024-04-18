// 404. Sum of Left Leaves

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

// Solution 1 using isLeaf helper function to check if the node is leaf or not
// Time complexity: O(n)
// Space complexity: O(n)
class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        int total = 0;
        if(!root){
            if(isLeaf(root->left))
                total += root->left->val;
            else  total += sumOfLeftLeaves(root->left);
            total += sumOfLeftLeaves(root->right);
        }
        return total;
    }
    bool isLeaf(TreeNode* node){
        if(!node)
            return false;
        if(!node->left && !node->right){
            return true;
        }
        return false;
    }
};

// Solution 2 using a helper function to check if the leaf is left leaf of parent or not
// Time complexity: O(n)
// Space complexity: O(n)
class Solution {
public:
    int res;
    void helper(TreeNode* root, TreeNode* p){
        if(!root->left && !root->right){
            if(p->left == root) res += root->val;
            return; 
        }
        if(root->left) helper(root->left, root);
        if(root->right) helper(root->right, root);
    }
    int sumOfLeftLeaves(TreeNode* root) {
        res = 0;
        if(!root->left && !root->right) return res;
        if(root->left) helper(root->left, root);
        if(root->right) helper(root->right, root);
        return res;
    }
};