// 1026. Maximum Difference Between Node and Ancestor
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

// Using Recursion by finding out maximum and minimum of each sub-tree  and then subtracting with the ancestor
class Solution {
public:
    int result;
    int maxAncestorDiff(TreeNode* root) {
        if(root == NULL){
            return 0;
        }
        result = 0;
        helper(root, root->val, root->val);
        return result;
    }

    void helper(TreeNode* node, int currMax, int currMin){
        if(node == NULL){
            return;
        }
        int currResult = max(abs(currMax - node->val), abs(currMin - node->val));
        result = max(currResult, result);
        currMax = max(currMax, node->val);
        currMin = min(currMin, node->val);
        helper(node->left, currMax, currMin);
        helper(node->right, currMax, currMin);
    }
};

// recursive but we keep track of maximum difference in each sub-tree
class Solution {
public:
    int maxAncestorDiff(TreeNode* root) {
        return helper(root, root->val, root->val);
    }

    int helper(TreeNode* node, int currMax, int currMin){
        if(node == NULL){
            return currMax - currMin;
        }
        currMax = max(currMax, node->val);
        currMin = min(currMin, node->val);
        int leftDiff = helper(node->left, currMax, currMin);
        int rightDiff = helper(node->right, currMax, currMin);
        return max(leftDiff, rightDiff);
    }
};

