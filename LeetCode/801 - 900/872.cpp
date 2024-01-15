// 872. Leaf-Similar Trees

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
// Space Complexity: O(n)
class Solution {
public:
    void helper(TreeNode* root, vector<int>& result){
        if(!root->left && !root->right){
            result.push_back(root->val);
            return;
        }
        if(root->left) helper(root->left, result);
        if(root->right) helper(root->right, result);
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> seq1, seq2;
        helper(root1, seq1);
        helper(root2, seq2);
        return seq1 == seq2;
    }
};
