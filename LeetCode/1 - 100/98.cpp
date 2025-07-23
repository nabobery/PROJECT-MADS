// 98. Validate Binary Search Tree

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

// Solution 1
class Solution {
public:
    vector<int> arr;
    void helper(TreeNode* root){
        if(root->left) helper(root->left);
        if(root) arr.push_back(root->val);
        if(root->right) helper(root->right);
    }
    bool isValidBST(TreeNode* root) {
        helper(root);
        for(int i = 1; i < arr.size();i++){
            if(arr[i] <= arr[i-1]) return false;
        }
        return true;
    }
};

// Solution 2
class Solution {
public:
    bool helper(TreeNode* root, long long l, long long r){
        if(!root) return true;
        if(root->val > l && root->val < r) return(helper(root->left, l, root->val) && helper(root->right, root->val, r));
        return false;
    }
    bool isValidBST(TreeNode* root) {
        long long mi = -1e10, ma = 1e10;
        return helper(root, mi, ma);
    }
};