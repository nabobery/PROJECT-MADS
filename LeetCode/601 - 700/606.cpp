// 606. Construct String from Binary Tree

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
// Time complexity: O(n^2)
// Space complexity: O(n)
class Solution {
public:
    string tree2str(TreeNode* root) {
        if(!root) return "";
        string left = "", right ="";
        if(root->left) left = "(" + tree2str(root->left) + ")";
        if(root->right){
            if(!root->left) left = "()";
            right = "(" + tree2str(root->right) + ")";
        } 
        return to_string(root->val) + left + right;
    }
};


// Solution 2 using DFS (optimized)
// Time complexity: O(n)
// Space complexity: O(logn)
class Solution {
public:
    string tree2str(TreeNode* root) {
        string res;
        helper(root, res);
        return res;
    }
    void helper(TreeNode* root, string& res){
        if(!root) return;
        res += to_string(root->val);
        if(root->left){
            res += "(";
            helper(root->left, res);
            res += ")";
        }
        if(root->right){
            if(!root->left) res += "()";
            res += "(";
            helper(root->right, res);
            res += ")";
        }
    }
};
