// 104. Maximum Depth of Binary Tree
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
 // my naive solution using dfs O(n) time and O(h) space (recursive stack)
class Solution {
public:
    int helper(TreeNode* node){
        if(node == NULL)
            return 0;
        int left = helper(node->left);
        int right = helper(node->right);
        if(left > right) return (left + 1);
        else return (right+1);

    }
    int maxDepth(TreeNode* root) {
        return helper(root);
    }
};

// without helper
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (root==NULL) return 0;
        return max(maxDepth(root->left)+1, maxDepth(root->right)+1);
    }
};

// using bfs O(n) time and space
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (root == NULL) return 0;
        queue<TreeNode*> q;
        int depth = 0,n;
        q.push(root);
        TreeNode* left, *right;
        while(!q.empty()){
            depth++;
            n = q.size();
            for(int i = 0; i < n;i++){
                left = q.front()->left;
                if(left) q.push(left);
                right = q.front()->right;
                if(right) q.push(right);
                q.pop();
            }
        }
        return depth;
    }
};
