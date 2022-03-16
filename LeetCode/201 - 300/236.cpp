// 236. Lowest Common Ancestor of a Binary Tree
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// recursive O(n) time and O(n) space solution
class Solution {
public:
    TreeNode* result = NULL;
    bool dfs(TreeNode* curr, TreeNode* p, TreeNode* q){
        // If reached the end of a branch, return false.
        if(!curr) return false;
        // Left Recursion. If left recursion returns true, set left = 1 else 0
        int left = dfs(curr->left,p,q) ? 1 : 0;
        // Right Recursion
        int right = dfs(curr->right,p,q) ? 1 : 0;
        // If the current node is one of p or q
        int mid = (curr == p || curr == q) ? 1 : 0;
        // If any two of the flags left, right or mid become True
        if(mid + left + right >= 2){
            result = curr;
        }
        // Return true if any one of the three bool values is True.
        return (mid + left + right > 0);
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        dfs(root,p,q);
        return result;
    }
};

// iterative O(n) time and O(n) space solution

