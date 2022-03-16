// 563. Binary Tree Tilt
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
    int helper(TreeNode* root, int* result){
        if(root == NULL){
            return 0;
        }
        int left = helper(root->left,result);
        int right = helper(root->right,result);
        *result += abs(left - right);
        return (left + right + root->val);
    }
    int findTilt(TreeNode* root) { 
        int result = 0;
        helper(root, &result);
        return result;
    }
};

class Solution {
public:
    int result = 0;
    int helper(TreeNode* root){
        if(root == NULL){
            return 0;
        }
        int left = helper(root->left);
        int right = helper(root->right);
        result += abs(left - right);
        return (left + right + root->val);
    }
    int findTilt(TreeNode* root) { 
        helper(root);
        return result;
    }
};