// 1382. Balance a Binary Search Tree

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

// Solution 1 by Inorder Traversal and creating a new tree
// Time complexity: O(n)
// Space complexity: O(n)
class Solution {
public:
    int n;
    void inorder(TreeNode* root, vector<int>& nodes){
        if(!root) return;
        inorder(root->left, nodes);
        nodes.push_back(root->val);
        inorder(root->right, nodes);
    }
    TreeNode* createBST(vector<int>& nodes, int l, int r){
        if(l > r) return NULL;
        int mid = (l+r)/ 2;
        TreeNode* root = new TreeNode(nodes[mid]);
        root->left = createBST(nodes, l ,mid-1);
        root->right = createBST(nodes, mid+1, r);
        return root;

    }
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> nodes;
        inorder(root, nodes);
        n = nodes.size();
        TreeNode* res = createBST(nodes, 0, n-1);
        return res;
    }
};